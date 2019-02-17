include(ocv_config.pri)

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dz-6
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    Processing.cpp \
    Manager.cpp

HEADERS += \
    MainWindow.h \
    Processing.h \
    Manager.h

FORMS += \
    MainWindow.ui

DISTFILES += \
    ocv_config.pri
