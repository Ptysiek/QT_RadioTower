QT -= gui
CONFIG -= Felgo

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../source/Map.cpp \
        ../source/MusicGenreFactory.cpp \
        ../source/Program.cpp \
        ../source/Radio.cpp \
        ../source/RadioTower.cpp \
        ../source/World.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../source/Channel.h \
    ../source/Map.h \
    ../source/MusicGenreFactory.h \
    ../source/Program.h \
    ../source/Radio.h \
    ../source/RadioTower.h \
    ../source/Tile.h \
    ../source/World.h
