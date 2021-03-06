#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T16:01:45
#
#-------------------------------------------------

QT       += core gui
QT +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CookBook
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    ingrlist.cpp \
    ingrrecipe.cpp \
    ingrsearch.cpp \
    lastrecipe.cpp \
    recipe.cpp \
    searchrecipe.cpp \
    dataprocessing.cpp \
    mainwidget.cpp \
    recipewidget.cpp \
    recipefullwidget.cpp \
    searchform.cpp \
    lastrepform.cpp \
    changerecipeform.cpp \
    newrecipeform.cpp

HEADERS  += mainwindow.h \
    ingrbase.h \
    ingrlist.h \
    ingrrecipe.h \
    ingrsearch.h \
    lastrecipe.h \
    recipe.h \
    searchrecipe.h \
    dataprocessing.h \
    mainwidget.h \
    recipewidget.h \
    recipefullwidget.h \
    searchform.h \
    lastrepform.h \
    changerecipeform.h \
    newrecipeform.h


FORMS    += mainwindow.ui \
    recipewidget.ui \
    recipefullwidget.ui \
    searchform.ui \
    lastrepform.ui \
    changerecipeform.ui \
    newrecipeform.ui
