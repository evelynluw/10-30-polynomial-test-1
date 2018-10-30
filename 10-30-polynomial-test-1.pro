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
    expression.cpp \
    expression-friends.cpp \
    calculate.cpp

HEADERS += \
    term.h \
    fraction.h \
    constants.h \
    expression.h \
    calculate.h

DISTFILES += \
    test.md
