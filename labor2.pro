QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classunit.cpp \
    main.cpp

HEADERS += \
    abstractclassfactory.h \
    abstractmethodfactory.h \
    classunit.h \
    csharpclassfactory.h \
    csharpclassunit.h \
    csharpmethodfactory.h \
    csharpmethodunit.h \
    javaclassfactory.h \
    javaclassunit.h \
    javamethodfactory.h \
    javamethodunit.h \
    methodunit.h \
    printoperatorunit.h \
    unit.h

FORMS += \
    unit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
