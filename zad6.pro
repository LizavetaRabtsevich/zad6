QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    circle.cpp \
    ellipse.cpp \
    freeline.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    rect.cpp \
    triangle.cpp

HEADERS += \
    canvas.h \
    circle.h \
    ellipse.h \
    ellipseshape.h \
    freeline.h \
    line.h \
    lineshape.h \
    mainwindow.h \
    rect.h \
    rectangleshape.h \
    scene.h \
    shape.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
