import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: root

    function open() {dialog.open()}

    anchors.fill: parent

    Dialog {
      id: dialog
      x: 0
      y: 0
      width: 200
      title: "Kek"
      modal: true
    }
}
