/**
 * Copyright (c) 2017-present, Status Research and Development GmbH.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle {
  id: root
  width: 384
  height: 640

  ColumnLayout {
      anchors.centerIn: parent
      Text {
        Layout.alignment: Qt.AlignCenter
        text: "Oh, no! StatusIm application just crashed!"
        font.bold: true
        font.pointSize: 25
      }
      Text {
        Layout.alignment: Qt.AlignCenter
        Layout.topMargin: 20
        text: "Please report us crash log files to allow us fix the issue!"
        font.bold: true
        font.pointSize: 20
      }
      Button {
        Layout.alignment: Qt.AlignCenter
        Layout.topMargin: 40
        text: "Report"
        onClicked: reportPublisher.submit()
      }
  }
}

