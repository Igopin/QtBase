#-------------------------------------------------
#
# Project created by QtCreator 2014-02-14T20:09:42
#
#-------------------------------------------------

QT       += sql core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBase
TEMPLATE = app


SOURCES += main.cpp\
        probbrowser.cpp \
    newprobdialog.cpp \
    matrix.cpp \
    problemmanager.cpp \
    defines.cpp \
    problem.cpp \
    solvelae.cpp \
    solveslae.cpp \
    prob_slae.cpp \
    prob_lae.cpp \
    setdimdialog.cpp

HEADERS  += probbrowser.h \
    newprobdialog.h \
    matrix.h \
    defines.h \
    problemmanager.h \
    problem.h \
    solvelae.h \
    solveslae.h \
    prob_slae.h \
    prob_lae.h \
    setdimdialog.h

FORMS += \
    newprobdialog.ui \
    probbrowser.ui \
    solvelae.ui \
    solveslae.ui \
    setdimdialog.ui
