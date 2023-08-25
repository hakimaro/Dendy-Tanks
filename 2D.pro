QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/movableobject.cpp \
    Model/unmovableobject.cpp \
    Model/bullet.cpp \
    Model/gameobject.cpp \
    Model/level.cpp \
    View/levelscene.cpp \
    main.cpp \
    Model/map.cpp \
    View/rasterwindow.cpp \
    Model/tank.cpp

HEADERS += \
    Model/movableobject.h \
    Model/unmovableobject.h \
    Model/bullet.h \
    Model/gameobject.h \
    Model/level.h \
    View/levelscene.h \
    Model/map.h \
    View/rasterwindow.h \
    Model/tank.h

FORMS +=

INCLUDEPATH += /home/serg/my_libs

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
        res.qrc
