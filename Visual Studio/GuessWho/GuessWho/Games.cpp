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
	/*
	 * Game Logic order:
	 * 
	 * 1 - Game prepares required elements before the initial turn
	 * 1.1 - Game initialises all the characters availbale for the game
	 * 1.2- Game initializes the Players
	 * 1.2.1 - Each player must have a deep copy of the charactermanager
	 * 1.3 - Game initializes the boards
	 * 2 - Starts the game
	 */
	//Preperations for the game
	preperationGame();

	while (!gameOver)
	{
		//Input
		inputGame();

		//Calculations
		calculationGame();

		//Render
		renderGame();
	}


}

void Games::preperationGame()
{
	
	characterManager.generateCharacters();
	characterManager.shuffleCharacters();
	characterManager.exportCharacters("Ressources/CharacterFiles/");//This line is crucial, because it allows the other character manger to know what is the order
	copyCharacterManagerToPlayer(player1);
	copyCharacterManagerToPlayer(player2);

	
}

void Games::inputGame()
{
	int input = 0;
	cin >> input;
}

void Games::calculationGame()
{
	
}

void Games::renderGame()
{
	//characterManager.printProperties();
	//characterManager.exportCharacters("Ressources/CharacterFiles/");
	//characterManager.clearCharacterVector();
	//characterManager.importCharacters("Ressources/CharacterFiles/");
	//characterManager.printProperties();

	cout << "Player 1" << endl;
	player1.get_board_of_player()->get_character_manager()->printProperties();

	cout << "Player 2" << endl;
	player2.get_board_of_player()->get_character_manager()->printProperties();
}

void Games::copyCharacterManagerToPlayer(Player player)
{
	player.get_board_of_player()->initializeCharacterManagerBoard(characterManager);
}

bool Games::is_game_over() const
{
	return gameOver;
}

void Games::set_game_over(bool game_over)
{
	gameOver = game_over;
}

CharacterManager Games::get_character_manager() const
{
	return characterManager;
}

void Games::set_character_manager(CharacterManager character_manager)
{
	characterManager = move(character_manager);
}

