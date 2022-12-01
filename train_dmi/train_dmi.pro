QT += quick
QT += multimedia

CONFIG += c++17


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        button_handler.cpp \
        dmi_handler.cpp \
        main.cpp \
        network_client.cpp \
        speedometer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    button_handler.h \
    dmi_handler.h \
    network_client.h \
    speedometer.h

DISTFILES += \
    qmldir \
    desk_ikoner/Down.tif \
    desk_ikoner/DownY.tif \
    desk_ikoner/Up.tif \
    desk_ikoner/UpY.tif \
    desk_ikoner/back.tif \
    desk_ikoner/backR.tif \
    desk_ikoner/backY.tif \
    desk_ikoner/button.tif \
    desk_ikoner/button69.tif \
    desk_ikoner/closed.tif \
    desk_ikoner/closedG.tif \
    desk_ikoner/deskPanel.tif \
    desk_ikoner/deskPanel.xml \
    desk_ikoner/deskPanel0.bmp \
    desk_ikoner/deskPanel1.bmp \
    desk_ikoner/deskPanel2.bmp \
    desk_ikoner/doorleft.tif \
    desk_ikoner/doorleftY.tif \
    desk_ikoner/doorright.tif \
    desk_ikoner/doorrightY.tif \
    desk_ikoner/emergencyCall.tif \
    desk_ikoner/emergencyCallR.tif \
    desk_ikoner/frontLight.tif \
    desk_ikoner/frontLightY.tif \
    desk_ikoner/green.tif \
    desk_ikoner/indicator_frame.png \
    desk_ikoner/indicator_frameR.png \
    desk_ikoner/power.tif \
    desk_ikoner/power_green.tif \
    desk_ikoner/redButton.tif \
    desk_ikoner/siren.tif \
    desk_ikoner/siren5.tif \
    desk_ikoner/siren6.tif \
    desk_ikoner/yellow.tif \
    desk_ikoner/green.png \
    desk_ikoner/redButton.png \
