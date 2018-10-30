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
    polynomial.cpp \
    polynomial-friends.cpp \
    expression.cpp

HEADERS += \
    term.h \
    fraction.h \
    constants.h \
    polynomial.h \
    expression.h

DISTFILES += \
    test.md
