#include "stdafx.h"
#include "Games.h"


Games::Games()
{
}


Games::~Games()
{
}

void Games::start()
{
	gameLoop();
}

void Games::gameLoop()
{
	//Input

	//Calculations

	//Render
	characterManager.printProperties();
	characterManager.exportCharacters("Ressources/CharacterFiles/");
	characterManager.importCharacters("Ressources/CharacterFiles/");
	characterManager.printProperties();
}
