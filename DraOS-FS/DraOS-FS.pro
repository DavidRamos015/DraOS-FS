#-------------------------------------------------
#
# Project created by QtCreator 2012-11-24T00:56:10
#
#-------------------------------------------------

QT       += core gui
QT       += sql

TARGET = DraOS-FS
TEMPLATE = app


SOURCES += main.cpp\
    fsexplorer.cpp \
    formuser.cpp \
    directorio.cpp \
    datablock.cpp \
    usuario.cpp \
    sectorceroinfo.cpp \
    operacion.cpp \
    utilerias.cpp \
    mapabits.cpp \
    fileexplorer.cpp \
    pila.cpp \
    fileproperties.cpp \
    timeclass.cpp

HEADERS  += fsexplorer.h \
    formuser.h \
    directorio.h \
    datablock.h \
    usuario.h \
    sectorceroinfo.h \
    operacion.h \
    utilerias.h \
    mapabits.h \
    fileexplorer.h \
    pila.h \
    fileproperties.h \
    timeclass.h

FORMS    += fsexplorer.ui \
    formuser.ui \
    fileexplorer.ui \
    fileproperties.ui

RESOURCES += \
    recursos.qrc
