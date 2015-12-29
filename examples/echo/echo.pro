QT += core
QT -= gui

TARGET = echo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

include(../../QtTelegramBot.pri)
