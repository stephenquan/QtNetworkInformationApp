import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtNetworkInformationApp 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("NetworkInformation App")

    QtObject {
        id: styles
        property int textPointSize: 12
    }

    Page {
        anchors.fill: parent

        Flickable {
            id: flickable

            anchors.fill: parent
            anchors.margins: 10

            contentWidth: columnLayout.width
            contentHeight: columnLayout.height
            clip: true

            ColumnLayout {
                id: columnLayout

                width: flickable.width

                Frame {
                    Layout.fillWidth: true

                    background: Rectangle {
                    }

                    Text {
                        width: parent.width

                        text: qsTr("AvailableBackends: %1").arg(JSON.stringify(networkInformation.availableBackends))
                        font.pointSize: styles.textPointSize
                    }
                }
            }
        }

        footer: Frame {
            background: Rectangle {
            }

            RowLayout {
                width: parent.width

                Text {
                    text: qsTr("%1 (%2)")
                        .arg(NetworkReachability.stringify(networkInformation.reachability))
                        .arg(networkInformation.reachability)
                    font.pointSize: styles.textPointSize
                }
            }
        }
    }

    NetworkInformation {
        id: networkInformation
    }
}
