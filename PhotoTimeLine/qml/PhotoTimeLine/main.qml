import QtQuick 1.0
import qtgoogleclientlogin 1.0
import phototimelinemodel 1.0
import mainlogic 1.0

Rectangle {
    id : photoContainer
    width: 360
    height: 360

    PhotoTimelineModel {
        id : photoModel
    }

    ListView {
        visible: true
        anchors.fill: parent
        model: photoModel
        orientation : ListView.Horizontal
        delegate: Text {
            width : 250
            height : photoContainer.height
            text: timeStamp
        }
    }

    MainLogic {
        id: mainLogic
    }

    GoogleClientLoginLogic {
        id: clientLogin
    }

    GoogleClientLogin {
        id : clientLoginUi
        visible: true
        anchors.fill: parent
        onLogin : {
            mainLogic.username = username
        }

    }
}
