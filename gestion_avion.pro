QT +=core gui sql printsupport multimedia network
QT +=widgets multimedia
QT += network

QT       += core gui sql charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

QT += printsupport
TARGET = gestion_avion
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avion.cpp \
    connection.cpp \
    dialog.cpp \
    exportexcelobject.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    smtp.cpp

HEADERS += \
    avion.h \
    connection.h \
    dialog.h \
    exportexcelobject.h \
    login.h \
    mainwindow.h \
    notification.h \
    smtp.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    notification.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
