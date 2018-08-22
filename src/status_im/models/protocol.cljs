(ns status-im.models.protocol
  (:require [re-frame.core :as re-frame]
            [status-im.constants :as constants]
            [status-im.transport.core :as transport]
            [status-im.transport.inbox :as transport.inbox]
            [status-im.utils.ethereum.core :as ethereum]
            [status-im.utils.handlers-macro :as handlers-macro]
            [status-im.utils.semaphores :as semaphores]
            [status-im.utils.utils :as utils]))

(defn- assert-correct-network
  [{:keys [db]}]
  ;; Assure that node was started correctly
  (let [{:keys [web3]} db]
    (let [network (get-in db [:account/account :network])
          network-id (str (get-in db [:account/account :networks network :config :NetworkId]))]
      (when (and network-id web3) ; necessary because of the unit tests
        (.getNetwork (.-version web3)
                     (fn [error fetched-network-id]
                       (when (and (not error) ; error most probably means we are offline
                                  (not= network-id fetched-network-id))
                         (utils/show-popup
                          "Ethereum node started incorrectly"
                          "Ethereum node was started with incorrect configuration, application will be stopped to recover from that condition."
                          #(re-frame/dispatch [:close-application])))))))))

(defn update-sync-state
  [{:keys [sync-state sync-data] :as db} error sync]
  (let [{:keys [highestBlock currentBlock] :as state}
        (js->clj sync :keywordize-keys true)
        syncing?  (> (- highestBlock currentBlock) constants/blocks-per-hour)
        new-state (cond
                    error :offline
                    syncing? (if (= sync-state :done)
                               :pending
                               :in-progress)
                    :else (if (or (= sync-state :done)
                                  (= sync-state :pending))
                            :done
                            :synced))]
    (cond-> db
      (when (and (not= sync-data state) (= :in-progress new-state)))
      (assoc :sync-data state)
      (when (not= sync-state new-state))
      (assoc :sync-state new-state))))

(defn check-sync-state
  [{{:keys [web3] :as db} :db :as cofx}]
  (if (:account/account db)
    {:protocol/web3-get-syncing web3
     :dispatch-later    [{:ms 10000 :dispatch [:check-sync-state]}]}
    (semaphores/free :check-sync-state? cofx)))

(defn start-check-sync-state
  [{{:keys [network account/account] :as db} :db :as cofx}]
  (when (and (not (semaphores/locked? :check-sync-state? cofx))
             (not (ethereum/network-with-upstream-rpc? (get-in account [:networks network]))))
    (handlers-macro/merge-fx cofx
                             {:dispatch [:check-sync-state]}
                             (semaphores/lock :check-sync-state?))))

(defn initialize-protocol
  [address {:data-store/keys [transport mailservers] :keys [db] :as cofx}]
  (handlers-macro/merge-fx cofx
                           {:db (assoc db
                                       :rpc-url constants/ethereum-rpc-url
                                       :transport/chats transport)}
                           (assert-correct-network)
                           (start-check-sync-state)
                           (transport.inbox/initialize-offline-inbox mailservers)
                           (transport/init-whisper address)))
