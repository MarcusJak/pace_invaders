QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 multimedia multimediawidgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullets.cpp \
    enemy.cpp \
    enemy_bullet.cpp \
    game.cpp \
    health.cpp \
    main.cpp \
    menyObj.cpp \
    play_bullet.cpp \
    player.cpp \
    score.cpp \
    stats.cpp \
    storeobjects.cpp

HEADERS += \
    bullets.h \
    enemy.h \
    enemy_bullet.h \
    game.h \
    health.h \
    menyObj.h \
    play_bullet.h \
    player.h \
    score.h \
    stats.h \
    storeobjects.h

FORMS +=

TRANSLATIONS += \
    Projekt_Game_Marcus_sv_SE.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sound.qrc
