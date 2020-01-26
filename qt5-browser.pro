TEMPLATE = app

# keyboard should be within the application
CONFIG += disable-desktop

static {
    QT += svg
    QTPLUGIN += qtvirtualkeyboardplugin
}


QT += webenginewidgets

SOURCES += main.cpp
# Default rules for deployment.

target.path = /usr/bin
INSTALLS += target
