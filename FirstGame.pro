QT       += core gui \
            multimedia \
            multimediawidgets \


 greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bgdecks.cpp \
    bgdeckscontainer.cpp \
    bgdeckscruise.cpp \
    bullet.cpp \
    enemy.cpp \
    enemy1.cpp \
    enemy2.cpp \
    enemy3.cpp \
    game.cpp \
    health.cpp \
    main.cpp \
    meteor.cpp \
    meteor1.cpp \
    player.cpp \
    score.cpp

HEADERS += \
    bgdecks.h \
    bgdeckscontainer.h \
    bgdeckscruise.h \
    bullet.h \
    enemy.h \
    enemy1.h \
    enemy2.h \
    enemy3.h \
    game.h \
    health.h \
    meteor.h \
    meteor1.h \
    player.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
