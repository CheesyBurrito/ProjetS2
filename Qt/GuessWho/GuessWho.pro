TEMPLATE     = vcapp
TARGET       = GuessWho
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += StartWindow.h MenuWindow.h MainWindow.h
SOURCES     += GuessWho.cpp StartWindow.cpp MenuWindow.cpp MainWindow.cpp
INCLUDEPATH += ../GuessWhoLib
QT += widgets
win32:RC_ICONS += OhmBoys.ico
