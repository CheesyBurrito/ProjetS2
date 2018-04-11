TEMPLATE     = vcapp
TARGET       = GuessWho
CONFIG      += warn_on qt debug_and_release windows console
LIBS 		+= ../GuessWhoLib/CommunicationFPGA.lib
HEADERS     += StartWindow.h MenuWindow.h MainWindow.h GameWindow.h CharacterGrid.h LowerBar.h SideMenu.h CharacterCard.h CharacterTraits.h PauseMenu.h MenuButton.h AddCharacter.h MainMenu.h OptionsMenu.h OnePlayerMenu.h TwoPlayersMenu.h QuestionMenuBar.h Board.h Character.h CharacterManager.h Games.h Phoneme.h Player.h stdafx.h targetver.h FPGA.h
SOURCES     += GuessWho.cpp StartWindow.cpp MenuWindow.cpp MainWindow.cpp GameWindow.cpp CharacterGrid.cpp LowerBar.cpp SideMenu.cpp CharacterCard.cpp CharacterTraits.cpp PauseMenu.cpp MenuButton.cpp AddCharacter.cpp MainMenu.cpp OptionsMenu.cpp OnePlayerMenu.cpp TwoPlayersMenu.cpp QuestionMenuBar.cpp Board.cpp Character.cpp CharacterManager.cpp Games.cpp Phoneme.cpp Player.cpp stdafx.cpp FPGA.cpp
INCLUDEPATH += ../GuessWhoLib
QT += widgets
win32:RC_ICONS += OhmBoys.ico