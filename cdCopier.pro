#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T16:44:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cdCopier
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    preferences.cpp \
    start_proccess.cpp \
    utils.cpp \
    frame_stat.cpp \
    ProcessWorker.cpp

HEADERS  += mainwindow.h \
    preferences.h \
    start_proccess.h \
    utils.h \
    frame_stat.h \
    ProcessWorker.h

FORMS    += mainwindow.ui \
    preferences.ui \
    start_proccess.ui
