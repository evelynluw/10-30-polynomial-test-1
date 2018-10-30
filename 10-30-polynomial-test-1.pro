TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    term-friends.cpp \
    term.cpp \
    polynomial-friends.cpp \
    polynomial.cpp \
    fraction-friends.cpp \
    fraction.cpp \
    expression.cpp

HEADERS += \
    term.h \
    polynomial.h \
    fraction.h \
    constants.h \
    expression.h
