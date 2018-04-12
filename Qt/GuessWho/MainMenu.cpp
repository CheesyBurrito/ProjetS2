#include "MainMenu.h"

MainMenu::MainMenu(QWidget* parent) : QWidget(parent)
{
	createMainMenu();
}

MainMenu::~MainMenu()
{
}

void MainMenu::createMainMenu()
{
	layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	onePlayer = new MenuButton(this, " 1 joueur");
	twoPlayers = new MenuButton(this, " 2 joueurs");
	optionsButton = new MenuButton(this, " Options");
	quitButton = new MenuButton(this, " Quitter");


	layout->addWidget(onePlayer);
	layout->addWidget(twoPlayers);
	layout->addWidget(optionsButton);
	layout->addWidget(quitButton);

	setLayout(layout);
}
