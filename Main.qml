import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick3D
import QtQuick3D.Helpers
import linesExample

ApplicationWindow {
    visible: true
    width: 800
    height: 600

    Axis {
        id: oldAxis
    }

    Axis {
        id: axisLabelX
    }

    Axis {
        id: axisLabelY
    }

    Axis {
        id: axisLabelZ
    }

    Axis {
        id: axisLabelX1
    }

    Axis {
        id: axisLabelY1
    }

    Axis {
        id: axisLabelZ1
    }

    property int applyButtonClickCountEuler: 0

    property int applyButtonClickCountAircraft: 0

    property int buttonCheckIf: 0


    Component.onCompleted: {
        axisLabelX.initializeFirstLabels(0);
        axisLabelY.initializeFirstLabels(1);
        axisLabelZ.initializeFirstLabels(2);

        axisLabelX1.initializeFirstLabels(0);
        axisLabelY1.initializeFirstLabels(0);
        axisLabelZ1.initializeFirstLabels(0);
    }

    property string angle0LabelText: "Угол поворота по X:"
    property string angle1LabelText: "Угол поворота по Y:"
    property string angle2LabelText: "Угол поворота по Z:"

    // Основной контейнер, где 3D сцена и элементы управления находятся вместе
    Item {
        anchors.fill: parent

        // 3D-сцена
        View3D {
            id: view3d
            anchors.fill: parent  // Заполняем всё окно для 3D-сцены
            camera: PerspectiveCamera {
                id: camera
                position: Qt.vector3d(150, 60, 150)// Камера на расстоянии от линии по оси Z
                eulerRotation: Qt.vector3d(0,45,0)

            }
            environment: SceneEnvironment {
                backgroundMode: SceneEnvironment.Color
                clearColor: "white"
            }

            // Отрисовка лейбла для оси OX
            Model {
                geometry: axisLabelX.xAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelX.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OX
            Model {
                geometry: axisLabelX.yAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelX.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OY
            Model {
                geometry: axisLabelY.xAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelY.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OY
            Model {
                geometry: axisLabelY.yAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelY.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OZ
            Model {
                geometry: axisLabelZ.xAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelZ.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OZ
            Model {
                geometry: axisLabelZ.yAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelZ.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OZ
            Model {
                geometry: axisLabelZ.zAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelZ.zAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OX1
            Model {
                id: xlabelX1
                geometry: axisLabelX1.xAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelX1.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OX1
            Model {
                id: ylabelX1
                geometry: axisLabelX1.yAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelX1.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OY1
            Model {
                id: xlabelY1
                geometry: axisLabelY1.xAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelY1.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OY1
            Model {
                id: ylabelY1
                geometry: axisLabelY1.yAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelY1.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OZ1
            Model {
                id: xlabelZ1
                geometry: axisLabelZ1.xAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelZ1.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OZ1
            Model {
                id: ylabelZ1
                geometry: axisLabelZ1.yAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelZ1.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            // Отрисовка лейбла для оси OZ1
            Model {
                id: zlabelZ1
                geometry: axisLabelZ1.zAxis
                materials: PrincipledMaterial {
                    baseColor: axisLabelZ1.zAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            Model {
                geometry: oldAxis.xAxis
                materials: PrincipledMaterial {
                    baseColor: oldAxis.xAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            Model {
                geometry: oldAxis.yAxis
                materials: PrincipledMaterial {
                    baseColor: oldAxis.yAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            Model {
                geometry: oldAxis.zAxis
                materials: PrincipledMaterial {
                    baseColor: oldAxis.zAxis.color  // Основной цвет линии
                    roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
                    metalness: 0.0    // Без металлического блеска
                    lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
                }
            }

            Model {
                id: xAxisModel
                geometry: oldAxis.xAxis
                materials: PrincipledMaterial {
                    baseColor: oldAxis.xAxis.color
                    roughness: 1.0
                    metalness: 0.0
                    lighting: PrincipledMaterial.NoLighting
                }
            }

            Model {
                id: yAxisModel
                geometry: oldAxis.yAxis
                materials: PrincipledMaterial {
                    baseColor: oldAxis.yAxis.color
                    roughness: 1.0
                    metalness: 0.0
                    lighting: PrincipledMaterial.NoLighting
                }
            }

            Model {
                id: zAxisModel
                geometry: oldAxis.zAxis
                materials: PrincipledMaterial {
                    baseColor: oldAxis.zAxis.color
                    roughness: 1.0
                    metalness: 0.0
                    lighting: PrincipledMaterial.NoLighting
                }
            }


            // Model {
            //     geometry: Line {}
            //     materials: PrincipledMaterial {
            //         baseColor: "red"  // Основной цвет линии
            //         roughness: 1.0    // Максимальная шероховатость, чтобы не было отражений
            //         metalness: 0.0    // Без металлического блеска
            //         lighting: PrincipledMaterial.NoLighting  // Отключаем освещение
            //     }
            // }

            // Model {
            //     id: yAxisOld
            //     geometry: oldAxis.getYAxis()
            // }

            // Model {
            //     id: zAxisOld
            //     geometry: oldAxis.getZAxis()
            // }

        }


        // Элементы управления, расположенные поверх 3D-сцены
        Rectangle {
            anchors.fill: parent
            color: "transparent"  // Прозрачный фон, чтобы не закрывать 3D-сцену
            ColumnLayout {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 20
                spacing: 10

                // Первый выпадающий список с подписью
                RowLayout {
                    spacing: 10
                    Label {
                        text: "Тип преобразования:"
                    }
                    ComboBox {
                        id: firstComboBox
                        model: ["Эйлеровы углы", "Самолетные углы", "Кватернионы"]
                        currentIndex: -1  // Устанавливаем -1, чтобы изначально не было выбрано ничего
                        onCurrentIndexChanged: {
                            updateSecondComboBoxModel();
                        }
                    }
                }

                // Второй выпадающий список с подписью
                RowLayout {
                    visible: firstComboBox.currentIndex !== 2
                    spacing: 10
                    Label {
                        text: "Преобразование:"
                    }
                    ComboBox {
                        id: secondComboBox
                        model: []  // Изначально пустой список
                        onCurrentTextChanged: {
                            updateAngleLabels();
                        }
                    }
                }

                // Поля ввода
                ColumnLayout {
                    Layout.alignment: Qt.AlignLeft
                    spacing: 10;

                    // Три текстовых поля для углов поворота
                    RowLayout {
                        visible: firstComboBox.currentIndex === 0 || firstComboBox.currentIndex === 1;
                        spacing: 10
                        // Label { text: "Угол поворота по X:" }
                        Label {text: angle0LabelText}
                        TextField {
                            id: angle_0
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly  // Разрешаем ввод чисел
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    RowLayout {
                        visible: firstComboBox.currentIndex === 0 || firstComboBox.currentIndex === 1;
                        spacing: 10
                        // Label { text: "Угол поворота по Y:" }
                        Label {text: angle1LabelText}
                        TextField {
                            id: angle_1
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    RowLayout {
                        visible: firstComboBox.currentIndex === 0 || firstComboBox.currentIndex === 1;
                        spacing: 10
                        // Label { text: "Угол поворота по Z:" }
                        Label {text: angle2LabelText}
                        TextField {
                            id: angle_2
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    // Поля ввода для кватернионов
                    RowLayout {
                        visible: firstComboBox.currentIndex === 2;
                        spacing: 10
                        Label { text: "Координата X:" }
                        TextField {
                            id: quaternionX
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    RowLayout {
                        visible: firstComboBox.currentIndex === 2;
                        spacing: 10
                        Label { text: "Координата Y:" }
                        TextField {
                            id: quaternionY
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    RowLayout {
                        visible: firstComboBox.currentIndex === 2;
                        spacing: 10
                        Label { text: "Координата Z:" }
                        TextField {
                            id: quaternionZ
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    RowLayout {
                        visible: firstComboBox.currentIndex === 2;
                        spacing: 10
                        Label { text: "Угол повор. G:" }
                        TextField {
                            id: quaternionAngle
                            placeholderText: "Введите значение"
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                            Layout.preferredWidth: 120  // Одинаковая ширина для всех полей
                        }
                    }

                    Button {
                        visible: firstComboBox.currentIndex === 0 || firstComboBox.currentIndex === 1 || firstComboBox.currentIndex === 2
                        text: "Применить"
                        onClicked: {
                            // Кватернионы
                            if (quaternionX.text !== "" && quaternionY.text !== "" && quaternionZ.text !== "" && quaternionAngle.text !== "") {
                                // Преобразование данных из строк в числа
                                var x = parseFloat(quaternionX.text);
                                var y = parseFloat(quaternionY.text);
                                var z = parseFloat(quaternionZ.text);
                                var angle = parseFloat(quaternionAngle.text);

                                // Применяем кватернион к oldAxis и получаем новый Axis
                                var newAxis = oldAxis.applyQuaternion(angle, Qt.vector3d(x, y, z));

                                // Обновляем отрисовку осей
                                xAxisModel.geometry = newAxis.xAxis;
                                xAxisModel.materials[0].baseColor = "orange";

                                yAxisModel.geometry = newAxis.yAxis;
                                yAxisModel.materials[0].baseColor = "brown";

                                zAxisModel.geometry = newAxis.zAxis;
                                zAxisModel.materials[0].baseColor = "purple";

                                // Замена лейблов у вторых осей
                                // Замена для X'
                                var labelAxisX = newAxis.initializeSecondLabels(newAxis.xAxis.end, 0);

                                xlabelX1.geometry = labelAxisX.xAxis;
                                xlabelX1.materials[0].baseColor = "orange";

                                ylabelX1.geometry = labelAxisX.yAxis;
                                ylabelX1.materials[0].baseColor = "orange";

                                // Замена для Y'
                                var labelAxisY = newAxis.initializeSecondLabels(newAxis.yAxis.end, 1);

                                xlabelY1.geometry = labelAxisY.xAxis;
                                xlabelY1.materials[0].baseColor = "brown";

                                ylabelY1.geometry = labelAxisY.yAxis;
                                ylabelY1.materials[0].baseColor = "brown";

                                // Замена для Z'
                                var labelAxisZ = newAxis.initializeSecondLabels(newAxis.zAxis.end, 2);

                                xlabelZ1.geometry = labelAxisZ.xAxis;
                                xlabelZ1.materials[0].baseColor = "purple";

                                ylabelZ1.geometry = labelAxisZ.yAxis;
                                ylabelZ1.materials[0].baseColor = "purple";

                                zlabelZ1.geometry = labelAxisZ.zAxis;
                                zlabelZ1.materials[0].baseColor = "purple";

                            } /*else {
                                console.log("Все поля должны быть заполнены!");
                            }*/

                            // Углы Эйлера
                            if (firstComboBox.currentIndex === 0 && secondComboBox.currentIndex !== -1 && applyButtonClickCountEuler === 0) {
                                var ang0;
                                var ang1;
                                var ang2;

                                if (angle_0.text !== "") {
                                    ang0 = parseFloat(angle_0.text);
                                } else {
                                    ang0 = 0;
                                    angle_0.text = "0";
                                }
                                console.log(ang0);

                                if (angle_1.text !== "") {
                                    ang1 = parseFloat(angle_1.text);
                                } else {
                                    ang1 = 0;
                                    angle_1.text = "0";
                                }
                                console.log(ang1);

                                if (angle_2.text !== "") {
                                    ang2 = parseFloat(angle_2.text);
                                } else {
                                    ang2 = 0;
                                    angle_2.text = "0";
                                }
                                console.log(ang2);

                                var rotationOrder = secondComboBox.currentText;
                                console.log(rotationOrder);

                                var newAxis = oldAxis.applyEulerAnglesWithOrder(ang0, ang1, ang2, rotationOrder);

                                xAxisModel.geometry = newAxis.xAxis;
                                xAxisModel.materials[0].baseColor = "orange";

                                yAxisModel.geometry = newAxis.yAxis;
                                yAxisModel.materials[0].baseColor = "brown";

                                zAxisModel.geometry = newAxis.zAxis;
                                zAxisModel.materials[0].baseColor = "purple";


                                // Замена лейблов у вторых осей
                                // Замена для X'
                                var labelAxisX = newAxis.initializeSecondLabels(newAxis.xAxis.end, 0);

                                xlabelX1.geometry = labelAxisX.xAxis;
                                xlabelX1.materials[0].baseColor = "orange";

                                ylabelX1.geometry = labelAxisX.yAxis;
                                ylabelX1.materials[0].baseColor = "orange";

                                // Замена для Y'
                                var labelAxisY = newAxis.initializeSecondLabels(newAxis.yAxis.end, 1);

                                xlabelY1.geometry = labelAxisY.xAxis;
                                xlabelY1.materials[0].baseColor = "brown";

                                ylabelY1.geometry = labelAxisY.yAxis;
                                ylabelY1.materials[0].baseColor = "brown";

                                // Замена для Z'
                                var labelAxisZ = newAxis.initializeSecondLabels(newAxis.zAxis.end, 2);

                                xlabelZ1.geometry = labelAxisZ.xAxis;
                                xlabelZ1.materials[0].baseColor = "purple";

                                ylabelZ1.geometry = labelAxisZ.yAxis;
                                ylabelZ1.materials[0].baseColor = "purple";

                                zlabelZ1.geometry = labelAxisZ.zAxis;
                                zlabelZ1.materials[0].baseColor = "purple";

                                applyButtonClickCountEuler = 1;
                                buttonCheckIf = 1;
                            }

                            // Самолетные углы
                            if (firstComboBox.currentIndex === 1 && secondComboBox.currentIndex !== -1 && applyButtonClickCountAircraft === 0) {
                                var ang0;
                                var ang1;
                                var ang2;

                                if (angle_0.text !== "") {
                                    ang0 = parseFloat(angle_0.text);
                                } else {
                                    ang0 = 0;
                                    angle_0.text = "0";
                                }
                                // console.log(ang0);

                                if (angle_1.text !== "") {
                                    ang1 = parseFloat(angle_1.text);
                                } else {
                                    ang1 = 0;
                                    angle_1.text = "0";
                                }
                                // console.log(ang1);

                                if (angle_2.text !== "") {
                                    ang2 = parseFloat(angle_2.text);
                                } else {
                                    ang2 = 0;
                                    angle_2.text = "0";
                                }
                                // console.log(ang2);

                                var rotationOrder = secondComboBox.currentText;

                                // var newAxis = oldAxis.applyAircraftAnglesGlobal(roll, pitch, yaw, rotationOrder);
                                var newAxis = oldAxis.aircraftAngles(ang0, ang1, ang2, rotationOrder);

                                xAxisModel.geometry = newAxis.xAxis;
                                xAxisModel.materials[0].baseColor = "orange";

                                yAxisModel.geometry = newAxis.yAxis;
                                yAxisModel.materials[0].baseColor = "brown";

                                zAxisModel.geometry = newAxis.zAxis;
                                zAxisModel.materials[0].baseColor = "purple";

                                // Замена лейблов у вторых осей
                                // Замена для X'
                                var labelAxisX = newAxis.initializeSecondLabels(newAxis.xAxis.end, 0);

                                xlabelX1.geometry = labelAxisX.xAxis;
                                xlabelX1.materials[0].baseColor = "orange";

                                ylabelX1.geometry = labelAxisX.yAxis;
                                ylabelX1.materials[0].baseColor = "orange";

                                // Замена для Y'
                                var labelAxisY = newAxis.initializeSecondLabels(newAxis.yAxis.end, 1);

                                xlabelY1.geometry = labelAxisY.xAxis;
                                xlabelY1.materials[0].baseColor = "brown";

                                ylabelY1.geometry = labelAxisY.yAxis;
                                ylabelY1.materials[0].baseColor = "brown";

                                // Замена для Z'
                                var labelAxisZ = newAxis.initializeSecondLabels(newAxis.zAxis.end, 2);

                                xlabelZ1.geometry = labelAxisZ.xAxis;
                                xlabelZ1.materials[0].baseColor = "purple";

                                ylabelZ1.geometry = labelAxisZ.yAxis;
                                ylabelZ1.materials[0].baseColor = "purple";

                                zlabelZ1.geometry = labelAxisZ.zAxis;
                                zlabelZ1.materials[0].baseColor = "purple";

                                applyButtonClickCountAircraft = 1;
                                buttonCheckIf = 1;
                            }

                            if (buttonCheckIf === 0) {
                                if (applyButtonClickCountEuler === 1 && firstComboBox.currentIndex === 0) {
                                    var rotationOrder = secondComboBox.currentText;
                                    var angleX = oldAxis.quatToEul(rotationOrder).x;
                                    var angleY = oldAxis.quatToEul(rotationOrder).y;
                                    var angleZ = oldAxis.quatToEul(rotationOrder).z;

                                    console.log("X = ", angleX);
                                    console.log("Y = ", angleY);
                                    console.log("Z = ", angleZ);

                                    console.log("");

                                    angle_0.text = angleX;
                                    angle_1.text = angleY;
                                    angle_2.text = angleZ;

                                    applyButtonClickCountEuler = 0;
                                }

                                if (applyButtonClickCountAircraft === 1 && firstComboBox.currentIndex === 1) {
                                    var rotationOrder = secondComboBox.currentText;
                                    var angleX = oldAxis.quatToAir(rotationOrder).x;
                                    var angleY = oldAxis.quatToAir(rotationOrder).y;
                                    var angleZ = oldAxis.quatToAir(rotationOrder).z;

                                    console.log("X = ", angleX);
                                    console.log("Y = ", angleY);
                                    console.log("Z = ", angleZ);

                                    console.log("");

                                    angle_0.text = angleX;
                                    angle_1.text = angleY;
                                    angle_2.text = angleZ;

                                    applyButtonClickCountAircraft = 0;
                                }
                            }

                            console.log(buttonCheckIf)
                            buttonCheckIf = 0;
                        }
                    }
                }
            }
        }
    }


    // Функция для обновления модели второго ComboBox
    function updateSecondComboBoxModel() {
        switch (firstComboBox.currentIndex) {
            case 0:  // Эйлеровы углы
                secondComboBox.model = ["X-Y-Z", "X-Z-Y", "Y-Z-X", "Y-X-Z", "Z-X-Y", "Z-Y-X",
                                        "X-Y-X", "X-Z-X", "Y-X-Y", "Y-Z-Y", "Z-X-Z", "Z-Y-Z"];
                break;
            case 1:  // Самолетные углы
                secondComboBox.model = ["X-Y-Z", "X-Z-Y", "Y-Z-X", "Y-X-Z", "Z-X-Y", "Z-Y-X"];
                break;
            case 2:  // Кватернионы
                secondComboBox.model = ["7", "10", "11"];
                break;
            default:
                secondComboBox.model = [];  // Очищаем, если ничего не выбрано
        }

        secondComboBox.currentIndex = -1;  // Сбрасываем выбранный элемент во втором списке
        updateAngleLabels();
    }

    // Функция динамической смены оконо лейблов окон ввода
    function updateAngleLabels() {
        if (firstComboBox.currentIndex === 0 || firstComboBox.currentIndex === 1) {
            if (secondComboBox.currentIndex !== -1) {
                var rotationOrder = secondComboBox.currentText;
                console.log(rotationOrder)
                var axes = rotationOrder.split('-');  // Разбиваем строку "X-Z-Y" на ["X", "Z", "Y"]

                angle0LabelText = "Угол поворота по " + axes[0] + ":";
                angle1LabelText = "Угол поворота по " + axes[1] + ":";
                angle2LabelText = "Угол поворота по " + axes[2] + ":";

            } else {
                angle0LabelText = "Угол поворота по X:";
                angle1LabelText = "Угол поворота по Y:";
                angle2LabelText = "Угол поворота по Z:";
            }
        }
    }
}
