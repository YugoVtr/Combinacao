QT += core
QT -= gui

CONFIG += c++11

TARGET = Combinacao
CONFIG += console
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS +=  -fopenmp
LIBS += -lgomp -lpthread

TEMPLATE = app

SOURCES += main.cpp
