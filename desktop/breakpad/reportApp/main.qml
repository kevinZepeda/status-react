
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

