#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T14:06:40
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PromesarioR
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    readall.cpp \
	marcarespecifico.cpp \
    widget.cpp \
    colorform.cpp

HEADERS  += dialog.h \
    readall.h  \
marcarespecifico.h \
    widget.h \
    colorform.h


FORMS    += dialog.ui \
    readall.ui \
marcarespecifico.ui \
    widget.ui \
    colorform.ui

RESOURCES += \
    Promesario.qrc

OTHER_FILES += \
    Icono_principal.rc

RC_FILE += Icono_principal.rc

QMAKE_CXXFLAGS += -std=gnu++11
