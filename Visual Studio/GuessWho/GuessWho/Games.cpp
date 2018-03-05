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
		//Check Game State
		switch(gameState)
		{
		case 0:
			{
				//TODO Implement when the game is paused
		}break;

		case 1:
			{
			//Input
			inputGame(player1);

			//Calculations
			calculationGame(player1);

			//Render
			renderGame(player1);

			gameState = player2Turn;
		}break;

		case 2:
			{
			//Input
			inputGame(player2);

			//Calculations
			calculationGame(player2);

			//Render
			renderGame(player2);

			gameState = player1Turn;
		}break;

		default:{
			cout << "Invalid game state!" << endl;
		}break;
		}

		
	}


}

void Games::preperationGame()
{
	
	characterManager.generateCharacters();
	characterManager.shuffleCharacters();
	characterManager.exportCharacters("Ressources/CharacterFiles/");//This line is crucial, because it allows the other character manger to know what is the order
	copyCharacterManagerToPlayer(player1);
	copyCharacterManagerToPlayer(player2);

	playerPreperations(player1);
	playerPreperations(player2);
}

void Games::playerPreperations(Player &player)
{
	string playerName;
	cout << "Veuiller entrer votre nom: " << endl;
	cin >> playerName;

	player.set_name_of_player(playerName);

	char isAI = -1;
	cout << "Est-ce que ce joueur est une IA? [y/n]" << endl;
	cin >> isAI;

	if(isAI == 'y')
	{
		player.set_is_cpu(true);
	}
	
	int charID;
	cout << "Veuiller entrer l'ID de votre personnage: " << endl;
	cin >> charID;
	player.characterSelection(charID);
	cout << player.get_character_selected()->get_id() << endl;
}

void Games::inputGame(Player &player)
{
	int input = 0;
	cin >> input;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Entree invalide!" << endl;
	}
}

void Games::calculationGame(Player &player)
{
	
}

void Games::renderGame(Player &player)
{
	player.get_board_of_player()->get_character_manager()->printProperties();
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

