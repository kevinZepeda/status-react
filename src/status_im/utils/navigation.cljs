(ns status-im.utils.navigation)

(def react-navigation (js/require "react-navigation"))
(def navigation-actions (.-NavigationActions react-navigation))
(def navigator-ref (atom nil))

(defn set-navigator-ref [ref]
  (reset! navigator-ref ref))

(defn navigate-to [route]
  (.dispatch
   @navigator-ref
   (.navigate
    navigation-actions
    #js {:routeName (name route)})))

(defn navigate-back []
  (.dispatch
   @navigator-ref
   (.back navigation-actions)))
