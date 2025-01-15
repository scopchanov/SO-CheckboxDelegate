QT += widgets

CONFIG += c++20

SOURCES += \
    CheckboxDelegate.cpp \
    MainWindow.cpp \
    main.cpp

HEADERS += \
    CheckboxDelegate.h \
    MainWindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
