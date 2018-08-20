
import QtQuick 2.4
import QtQuick.Controls 2.2

Rectangle {
  id: root
  width: 384
  height: 640

  Button {
    anchors.centerIn: parent
    text: "Report"
    onClicked: reportPublisher.submit()
  }
}

