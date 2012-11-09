#-------------------------------------------------
#
# Project created by QtCreator 2012-09-19T14:31:43
#
#-------------------------------------------------

QT       -= gui

CONFIG(debug, debug|release){
    TARGET = GlobalesFonctionsd

    LIBS += -L../configparser/debug -lconfigparserd
}
CONFIG(release, debug|release){
    TARGET = GlobalesFonctions

    LIBS += -L../configparser/release -lconfigparser
}
TEMPLATE = lib

DEFINES += GLOBALESFONCTIONS_LIBRARY

SOURCES += globalesfonctions.cpp

HEADERS += globalesfonctions.h\
        GlobalesFonctions_global.h

DEPENDPATH += ../configparser

INCLUDEPATH += ../configparser

#debug:LIBS += -L../ctcpclient/debug \
#              -L../configparser/debug

#release:LIBS += -L../ctcpclient/release \
#                -L../configparser/release

#LIBS    +=  -lctcpclient \
#            -lconfigparser

