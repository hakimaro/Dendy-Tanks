QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/movableobject.cpp \
    Model/unmovableobject.cpp \
    base.cpp \
    Model/bullet.cpp \
    Model/gameobject.cpp \
    Model/level.cpp \
    View/levelscene.cpp \
    main.cpp \
    man.cpp \
    Model/map.cpp \
    View/rasterwindow.cpp \
    Model/tank.cpp \
    wall.cpp

HEADERS += \
    Model/movableobject.h \
    Model/unmovableobject.h \
    base.h \
    Model/bullet.h \
    Model/gameobject.h \
    keys.h \
    Model/level.h \
    View/levelscene.h \
    man.h \
    Model/map.h \
    move.h \
    View/rasterwindow.h \
    Model/tank.h \
    wall.h

FORMS +=

INCLUDEPATH += /home/serg/my_libs

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
        res.qrc
