TEMPLATE     = vcapp
TARGET       = GuessWho
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += StartWindow.h MenuWindow.h MainWindow.h GameWindow.h CharacterGrid.h LowerBar.h SideMenu.h CharacterCard.h CharacterTraits.h PauseMenu.h MenuButton.h AddCharacter.h QuestionMenuBar.h MainMenu.h OptionsMenu.h OnePlayerMenu.h TwoPlayersMenu.h
SOURCES     += GuessWho.cpp StartWindow.cpp MenuWindow.cpp MainWindow.cpp GameWindow.cpp CharacterGrid.cpp LowerBar.cpp SideMenu.cpp CharacterCard.cpp CharacterTraits.cpp PauseMenu.cpp MenuButton.cpp AddCharacter.cpp QuestionMenuBar.cpp MainMenu.cpp OptionsMenu.cpp OnePlayerMenu.cpp TwoPlayersMenu.cpp
INCLUDEPATH += ../GuessWhoLib
QT += widgets
win32:RC_ICONS += OhmBoys.ico
