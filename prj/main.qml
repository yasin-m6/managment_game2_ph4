import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow
{
    id : root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color : "red"



    Button
    {
        width: 120
        height: 50

        onClicked:
        {
           // stackView.push("Page1.qml")
        }
    }

    /*Loader
    {
        id : pageLoader
    }*/

    /*Button
    {
        width: 100
        height: 30
        text: "click"
        onClicked:
        {
            pageLoader.source = "page1.qml"
        }
    }*/

    StackView
    {
        id : stackView
        Component.onCompleted: push("Page1.qml")
}

    /*Item {
        id: item

        Rectangle
        {
            id : backGround
            width: root.width
            height: root.height
            color : "blue"
        }

        ListModel
        {
            id : myModel
            ListElement{num : 1 }
            ListElement{num : 2 }
            ListElement{num : 3 }
            ListElement{num : 4 }
        }

        Rectangle
        {
            id : myFarm
            anchors.centerIn: backGround
            width: backGround.width/2
            height: width
           // z : 2
            color: "red"
        }

        /*GridView
        {
            model: myModel
            anchors.fill: myFarm
            cellHeight : width/2
            cellWidth : height/2

            delegate: Rectangle
            {
                id : farm
                width : myFarm.width/2
                height : width
                color : "green"
                border.color : "white"

            //}
        }*/

}
