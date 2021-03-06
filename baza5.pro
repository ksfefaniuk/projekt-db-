#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T23:13:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = baza5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        edycja_klient.cpp \
        edycja_naprawa.cpp \
        edycja_serwisowanie.cpp \
        edycja_urzadzenie.cpp \
        main.cpp \
        mainwindow.cpp \
        rejestracja.cpp \
        zalogowany.cpp

HEADERS += \
    edycja_klient.h \
    edycja_naprawa.h \
    edycja_serwisowanie.h \
    edycja_urzadzenie.h \
        mainwindow.h \
    rejestracja.h \
        zalogowany.h \

FORMS += \
    edycja_klient.ui \
    edycja_naprawa.ui \
    edycja_serwisowanie.ui \
    edycja_urzadzenie.ui \
        mainwindow.ui \
    rejestracja.ui \
        zalogowany.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
