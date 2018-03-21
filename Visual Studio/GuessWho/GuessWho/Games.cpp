#include "stdafx.h"
#include "Games.h"
#include <time.h>

using namespace std;

Games::Games()
{
	srand(time(NULL));
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
	 * 3 - Player asks question
	 * 4 - Based on answer, player removes characters (as of now it will be automatically done)
	 * 5 - Change player
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

			//Render
			renderGame(player1);

			//Input
			inputGame(player1, player2);

			//Calculations
			calculationGame(player1);

			gameState = player2Turn;
			//checkEndGameConditions(player1);
		}break;

		case 2:
			{
			//Render
			renderGame(player2);

			//Input
			inputGame(player2, player1);

			//Calculations
			calculationGame(player2);

			gameState = player1Turn;
			//checkEndGameConditions(player2);
		}break;

		default:{
			cout << "Invalid game state!" << endl;
		}break;
		}
	}

	cout << "Gagnant : " << winner << endl;
	cin >> winner;

}

void Games::checkEndGameConditions(Player player)
{
	if(player.get_board_of_player()->get_character_manager()->get_num_character_hidden() == 19)
	{
		gameOver = true;
		winner = player.get_name_of_player();
	}
}


void Games::preperationGame()
{
	
	//characterManager.generateCharacters();
	characterManager.importCharacters("Ressources/CharacterFiles/");
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

	if(isAI == 'y') //If player is bot, a character from the vector is chosen at random
	{
		int randomIndex = rand() % (player.get_board_of_player()->get_character_manager()->get_total_character());
		player.characterSelection(player.get_board_of_player()->get_character_manager()->get_character_vector().at(randomIndex)->get_id());
		player.set_is_cpu(true);
	}
	else { //Only human player choses a character
		int charID;
		cout << "Veuiller entrer l'ID de votre personnage: " << endl;
		cin >> charID;
		player.characterSelection(charID);
		cout << player.get_character_selected()->get_id() << endl;
	}
}

void Games::inputGame(Player &player, Player &otherPlayer)
{

	if (player.is_is_cpu()) {
		vector<int> question;
		question = player.cpuQuestionGeneretor(-1, otherPlayer);

		answerBotQuestion(question[0], question[1], player, otherPlayer);
	}

	else {

		cout << player.get_name_of_player() << endl;
		cout << "Nombre de personage caches (vous): " << player.get_board_of_player()->get_character_manager()->get_num_character_hidden() << "/" << player.get_board_of_player()->get_character_manager()->get_total_character() << endl;
		cout << "Nombre de personage caches (autre joueur): " << otherPlayer.get_board_of_player()->get_character_manager()->get_num_character_hidden() << "/" << otherPlayer.get_board_of_player()->get_character_manager()->get_total_character() << endl;
		cout << "Quelle est votre choix pour une propriete?" << endl;
		cout << "0 - Yeux" << endl << "1 - Cheveux" << endl
			<< "2 - Traits Cheveux" << endl << "3 - Couleur de peau" << endl
			<< "4 - Accessoires" << endl << "5 - Poils faciaux" << endl
			<< "6 - Age" << endl << "7 - Genre" << endl << "8 - Deviner tout de suite" << endl;
		int input = 0;
		cin >> input;
		int characteristicsSlected = input;
		if (input == 8)
		{
			cout << "Enter the character ID: " << endl;
			cin >> input;
			searchPlayerCharacteristicsQuestion(characteristicsSlected, input, player, otherPlayer);

		}
		else
		{
			player.get_board_of_player()->get_character_manager()->propertyPrinter(input);
			cin >> input;
			searchPlayerCharacteristicsQuestion(characteristicsSlected, input, player, otherPlayer);

		}






		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Entree invalide!" << endl;
		}
	}
}

void Games::calculationGame(Player &player)
{
	
}

void Games::renderGame(Player &player)
{
	if(!player.is_is_cpu()) //Shouldn't display board of cpu
		player.get_board_of_player()->get_character_manager()->printProperties();
}

void Games::copyCharacterManagerToPlayer(Player player)
{
	player.get_board_of_player()->initializeCharacterManagerBoard(characterManager);
}

void Games::answerBotQuestion(int characteristicsSlected, int input, Player& player, Player& otherPlayer) {
	string question = "";
	char answer;

	switch (characteristicsSlected)
	{
	case 0:
		question += "Est-ce que votre personnage a les yeux ";
		question += CharacterTraits::printPhysicalTraitsColorProperties(input);
		break;

	case 1:
		question += "Est-ce que votre personnage a les cheveux ";
		question += CharacterTraits::printPhysicalTraitsColorProperties(input);
		break;

	case 2:
		question += "Est-ce que votre personnage a les cheveux ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 3:
		question += "Est-ce que votre personnage a la peau ";
		question += CharacterTraits::printPhysicalTraitsColorProperties(input);
		break;

	case 4:
		question += "Est-ce que votre personnage a un/des ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 5:
		question += "Est-ce que votre personnage a une/des ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 6:
		question += "Est-ce que votre personnage est un ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 7:
		question += "Est-ce que votre personnage est un ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 8:
		question += "Est-ce que votre personnage est ";
		question += to_string(input);
		break;
	default:
		question = "ERROR : question generated by CPU is not valid";
		break;
	}

	cout << question << " (y/n)" << endl;
	cin >> answer;

	if (characteristicsSlected == 8) {
		if (answer == 'y')
		{
			gameOver = true;
			winner = player.get_name_of_player();
		}
		else {
			player.get_board_of_player()->get_character_manager()->hideCharacter(input);
		}
	}

	else {
		if (answer == 'y') {
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else {
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
		}
	}

}

void Games::searchPlayerCharacteristicsQuestion(int characteristicsSlected, int input, Player& player, Player& otherPlayer)
{
	switch (characteristicsSlected)
	{
	case 0:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getEyes() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			//cout << "Implement when a property has not been found" << endl;
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
		}
	}break;
	case 1:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getHairColor() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 2:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getHairCharacteristics() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 3:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getSkinColor() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 4:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->hasAccessory(input))
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 5:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getFacialHair() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 6:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getAge() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 7:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getGender() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 8:
		{
			if(otherPlayer.get_character_selected()->get_id() == input)
			{
				gameOver = true;
				winner = player.get_name_of_player();
			}
			else {
				player.get_board_of_player()->get_character_manager()->hideCharacter(input);
			}
	}break;
	default:
	{
		cout << "Hey, this should not show up, Games.cpp -> searchPlayerCharacteristics method" << endl;
	}break;
	}
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

