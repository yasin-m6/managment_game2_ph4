import QtQuick 2.9
import QtQuick.Controls 2.5

Item
{


    Rectangle
    {
        id : shop
        width: root.width
        height: root.height
        color: "lime"


        Rectangle
        {
            id : shopBackGround
            anchors.centerIn: shop
            width: shop.width * 3/4
            height: shop.height * 3/4
            color : "grey"
            border.color: "green"

            ListModel
            {
                id : myModel
                ListElement{name : "shen_kesh" ; type : 1 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "shen_kesh" ; type : 2 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "bil" ; type : 1 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "bil" ; type : 2 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "sam_pash" ; type : 1 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "sam_pash" ; type : 2 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "loole" ; type : 1 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "loole" ; type : 2 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "das" ; type : 1 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "das" ; type : 2 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "goje" ; type : 0 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "kalam" ; type : 0 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "kahoo" ; type : 0 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name :"havij" ; type : 0 ; path : "qrc:/images/tomato_farm.png"}
                ListElement{name : "gandom" ; type : 0 ; path : "qrc:/images/tomato_farm.png"}
            }

            ScrollView
            {
                anchors.fill: parent
                ListView
                {
                    id : sell
                    anchors.fill: parent
                    model: myModel
                    clip: true

                    delegate: Rectangle
                    {
                        id : item
                        width : shopBackGround.width
                        height : shopBackGround.height / 4
                        color : "white"
                        border.color : "black"
                        Image {
                            source: path
                            sourceSize: Qt.size(parent.height , parent.height)
                            anchors.right: parent.right
                        }

                        Rectangle
                        {
                            id : itemName
                            width: parent.width - parent.height
                            height: parent.height/2
                            color: "blue"
                            border.color: "red"
                            Text {
                                text: type>0 ?  name + " " + type : name
                                anchors.centerIn: parent
                            }
                        }
                        Rectangle
                        {
                            id : itemPrice
                            width: parent.width - parent.height
                            height: parent.height/2
                            color: "blue"
                            border.color: "red"
                            Text {
                                text: type>0 ?  useManager.get_tools_price(name+"_"+type) : useManager.get_seeds_price(name);
                                anchors.centerIn: parent
                            }
                            anchors.top : itemName.bottom
                        }
                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked:
                            {
                                console.log(name + " " + type);
                                if(type > 0)
                                {
                                    useManager.buyTools(name , type);
                                    useManager.print();
                                }
                                else
                                {
                                    useManager.buySeeds(name);
                                    useManager.print();
                                }
                            }
                        }
                    }


                }
            }

            /*ScrollView
            {
                width: parent.width
                height: parent.height*/
                /*Column
                {

                    id : sell
                    width: parent.width
                    height: parent.height
                    spacing: 2*/



                    /*Rectangle
                    {
                        width: parent.width
                        height: parent.height/5
                        color: "red"
                        border.color: "blue"
                        Text {

                            text: qsTr("text")
                        }
                    }
                    Rectangle
                    {
                        width: parent.width
                        height: parent.height/5
                        color: "red"
                        border.color: "blue"
                        Text {

                            text: qsTr("text")
                        }
                    }
                    Rectangle
                    {
                        width: parent.width
                        height: parent.height/5
                        color: "orange"
                        border.color: "blue"
                        Text {

                            text: qsTr("text")
                        }
                    }
                    Rectangle
                    {
                        width: parent.width
                        height: parent.height/5
                        color: "orange"
                        border.color: "blue"
                        Text {

                            text: qsTr("text")
                        }
                    }
                    Rectangle
                    {
                        width: parent.width
                        height: parent.height/5
                        color: "orange"
                        border.color: "blue"
                        Text {

                            text: qsTr("text")
                        }
                    }*/
                //}
           // }




            Button
            {
                text : "sell"
                width : 50
                height: 50
                anchors.right: parent.left
                anchors.bottom: parent.top

                onClicked:
                {
                    if(text == "sell")
                    {
                        text = "buy"
                        //buy.visible = false
                        //sell.visible = true
                        buy.checkVisibility();
                    }
                    else
                    {
                        text = "sell"
                        //buy.visible = true
                       // sell.visible = false
                        buy.checkVisibility();


                    }

                }
            }
        }

        Button
        {
            width: 60
            height: 60
            text: "back"
            onClicked:
            {
                console.log("farm")
                stackView.pop()
            }
        }
    }


}

