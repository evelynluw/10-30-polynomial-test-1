TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    term-friends.cpp \
    term.cpp \
    fraction-friends.cpp \
    fraction.cpp \
    calculate.cpp \
    polynomial.cpp \
    polynomial-friends.cpp

HEADERS += \
    term.h \
    fraction.h \
    constants.h \
    calculate.h \
    polynomial.h

DISTFILES += \
    test.md
