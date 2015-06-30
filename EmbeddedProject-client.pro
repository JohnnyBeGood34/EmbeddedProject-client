TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS +=-std=c++0x

target.path = /home/pi/

SOURCES += main.cpp \
    tcpstream.cpp \
    tcpconnector.cpp \
    pfio.c \
    pifacereader.cpp \
    configfilereader.cpp \
    doormansystem.cpp

HEADERS += \
    tcpstream.h \
    tcpconnector.h \
    pfio.h \
    pifacereader.h \
    configfilereader.h \
    doormansystem.h

