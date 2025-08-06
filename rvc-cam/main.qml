import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.0
import QtGraphicalEffects 1.0
import MyApp 1.0  // Change to your registration namespace
// import OpenGL 1.0

 Window {
     visible: true
     width: 1920
     height: 720
//     color: "transparent"
     property bool showSettings: false

     property int pad: 9
     property int iconSize: 46

     Column {
         anchors.centerIn: parent
         spacing: 10

         Slider {
             y: 300
             id: angleSlider
             width: 300
             from: -1.0
             to: 1.0
             value: 0
         }

         GuidelineItem {
             id: guideline
             width: 1920
             height: 720
             angle: angleSlider.value
         }
     }

//     Rectangle {
//         width: (pad*2 + iconSize)*4
//         height: pad*2 + iconSize
//         x: parent.width - (pad*2 + iconSize)*4 - pad
//         y: pad
//         radius: 10
//         color: Qt.rgba(0.3, 0.5, 0.5, 0.5)

//         Button {
//             x: pad
//             y: pad
//             width: iconSize
//             height: iconSize
//             background: Image {
//                source: "qrc:/setting.png"
//                fillMode: Image.PreserveAspectFit
//                anchors.fill: parent
//             }
//             onClicked: {
//                 console.log("click on button setting");
//                 settingsDialog.visible = true
//             }
//         }

//         Button {
//             x: pad + (pad*2 + iconSize)
//             y: pad
//             width: iconSize
//             height: iconSize
//             background: Image {
//                source: "qrc:/home.png"
//                fillMode: Image.PreserveAspectFit
//                anchors.fill: parent
//             }
//         }

//         Button {
//             x: pad + (pad*2 + iconSize)*2
//             y: pad
//             width: iconSize
//             height: iconSize
//             background: Image {
//                source: "qrc:/minimize.png"
//                fillMode: Image.PreserveAspectFit
//                anchors.fill: parent
//             }
//         }

//         Button {
//             x: pad + (pad*2 + iconSize)*3
//             y: pad
//             width: iconSize
//             height: iconSize
//             background: Image {
//                source: "qrc:/maximize.png"
//                fillMode: Image.PreserveAspectFit
//                anchors.fill: parent
//             }
//         }
//     }

//     Dialog {
//         id: settingsDialog
//         visible: showSettings
////         visible: true
//         modal: false
//         onAccepted: showSettings = false
//         onRejected: showSettings = false
//         x: parent.width - pad - width
//         y: pad*4 + iconSize
//         width: 300
//         height: parent.height - pad*5 - iconSize

//         background: Rectangle {
//             color: Qt.rgba(0.3, 0.5, 0.5, 0.5)
//             radius: 10
//             border.color: Qt.rgba(0.3, 0.5, 0.8, 0.5)
//             border.width: 2
//         }

//         contentItem: ColumnLayout {
//             anchors.fill: parent
//             anchors.margins: 10
//             spacing: 10

//             Label {
//                 text: qsTr("Rear Camera Guidelines")
//                 font.pixelSize: 20
//                 font.bold: true
//                 color: "#fff"
//             }

//             Label {
//                 text: qsTr("Dynamic Guidelines");
//                 color: "#fff";
//                 font.pixelSize: 18
//             }

//             Switch {
//                 id: dynamicSwitch
//                 checked: false
//                 onCheckedChanged: {
//                 }
//             }

//             Label {
//                 text: qsTr("Static Guidelines");
//                 color: "#fff";
//                 font.pixelSize: 18
//             }

//             Switch {
//                 id: staticSwitch
//                 checked: true
//                 onCheckedChanged: {
//                 }
//             }

//             Label {
//                 text: qsTr("Dynamic Guide Sensitivity");
//                 color: "#fff";
//                 font.pixelSize: 18
//             }

//             Slider {
//                 id: dynamicSensitivity
//                 from: -1; to: 0; value: GuideLineController.m_leftX
//                 width: 180
//                 onValueChanged: {
//                     // Save or update sensitivity
//                     GuideLineController.setGuideParams(value, 1, 1, 1)
//                 }
//             }


//             Label {
//                 text: qsTr("Static Guide Position");
//                 color: "#fff";
//                 font.pixelSize: 18
//             }

//             Slider {
//                 id: staticPosition
//                 from: -10; to: 10
//                 value: 0
//                 width: 180
//                 onValueChanged: {

//                 }
//             }
//             Label {
//                 text: qsTr("Static Guide Position");
//                 color: "#fff";
//                 font.pixelSize: 18
//             }

//             Slider {
//                 id: asd
//                 from: -10; to: 10
//                 value: 0
//                 width: 180
//                 onValueChanged: {

//                 }
//             }

//             RowLayout {
//                 Layout.alignment: Qt.AlignRight
//                 spacing: 18
//                 Button {
//                     text: qsTr("Cancel")
//                     onClicked: settingsDialog.visible = false
//                 }
//                 Button {
//                     text: qsTr("OK")
//                     onClicked: settingsDialog.visible = false
//                 }
//             }
//         }
//     }
 }
