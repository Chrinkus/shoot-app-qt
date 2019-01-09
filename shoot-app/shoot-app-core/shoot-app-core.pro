#-------------------------------------------------
#
# Project created by QtCreator 2019-01-06T11:50:35
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = shoot-app-core
TEMPLATE = lib
CONFIG += c++14

DEFINES += SHOOTAPPCORE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        event.cpp \
    shooter.cpp \
    databasemanager.cpp \
    event_dao.cpp \
    shooter_dao.cpp \
    aggregate_dao.cpp \
    aggregate.cpp

HEADERS += \
        event.h \
        shoot-app-core_global.h \ 
    shooter.h \
    databasemanager.h \
    event_dao.h \
    shooter_dao.h \
    aggregate_dao.h \
    aggregate.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
