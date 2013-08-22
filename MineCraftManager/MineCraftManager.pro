#-------------------------------------------------
#
# Project created by QtCreator 2012-12-24T00:02:58
#
#-------------------------------------------------

QT       += core gui webkit network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineCraftManager
TEMPLATE = app


SOURCES += main.cpp\
        mcmanager.cpp \
    config.cpp \
    version.cpp \
    loginutils.cpp \
    update.cpp \
    aboutdialog.cpp \
    configdialog.cpp \
    query.cpp \
    fileutils.cpp \
    hashcalc.cpp \
    launcherclass.cpp \
    splashscreen.cpp \
    simpleencrypt.cpp \
    serverlist.cpp

HEADERS  += mcmanager.h \
    config.h \
    version.h \
    loginutils.h \
    update.h \
    aboutdialog.h \
    configdialog.h \
    query.h \
    fileutils.h \
    hashcalc.h \
    launcherclass.h \
    enumstruct.h \
    splashscreen.h \
    simpleencrypt.h \
    serverlist.h

FORMS    += mcmanager.ui \
    aboutdialog.ui \
    configdialog.ui \
    splashscreen.ui

RESOURCES += \
    resources.qrc
