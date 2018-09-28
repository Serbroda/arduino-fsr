QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

SOURCES += \
    main.cpp \
    sensorreader.cpp \
    qcustomplot.cpp \
    mainwindow.cpp

HEADERS += \
    sensorreader.h \
    qcustomplot.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
