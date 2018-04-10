#include "stdafx.h"
#include "Games.h"

Games::Games()
{
	srand(time(NULL));
	fpgaCommunication.loadPhonemesFromFile("Phonemes.csv");
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
	while (restart)
	{
		if(numOfGamesPlayed != 0)
			reinitializeBoard();
		preperationGame();

		while (!gameOver)
		{
			//Check Game State
			switch (gameState)
			{
			case Pause:
			{
				//TODO Implement when the game is paused
			}break;

			case player1Turn:
			{

				//Render
				renderGame(player1);

				//Input
				inputGame(player1, player2);

				//Calculations
				calculationGame(player1);

				checkEndGameConditions(player1, player2);

				if (gameState == player1Turn)
				{
					gameState = player2Turn;
					player2.up_num_turn();

				}

			}break;

			case player2Turn:
			{
				//Render
				renderGame(player2);

				//Input
				inputGame(player2, player1);

				//Calculations
				calculationGame(player2);

				checkEndGameConditions(player2, player1);

				if (gameState == player2Turn)
				{
					gameState = player1Turn;
					player1.up_num_turn();
				}

			}break;

			case CardReadingError:
			{
				cout << "Error reading the FPGA card, please restart the program and verify the connection!" << endl;
			}break;

			default: {
				cout << "Invalid game state!" << endl;
			}break;
			}
		}

		if (winner == "Tie")
			cout << "Nous avons une egalite!" << endl;
		else
			cout << "Gagnant : " << winner << endl;

		numOfGamesPlayed++;

		if (numOfGames == numOfGamesPlayed)
		{
			if (player1.get_num_win() > player2.get_num_win())
				cout << player1.get_name_of_player() << " a gagne " << player1.get_num_win() << " - " << player2.get_num_win() << endl;
			else if (player1.get_num_win() < player2.get_num_win())
				cout << player2.get_name_of_player() << " a gagne " << player2.get_num_win() << " - " << player1.get_num_win() << endl;
			else
				cout << "Nous avons une egalite! " << player2.get_num_win() << " - " << player1.get_num_win() << endl;

			char reset;
			cout << "Voulez-vous rejouer? [y/n]" << endl;
			cin >> reset;

			if (reset == 'y')
			{
				restart = true;
				reinitialize();
				reinitializeBoard();
			}
			else
				restart = false;
		}
		else
		{
			cout << player1.get_name_of_player() << " " << player1.get_num_win() << " - " << player2.get_num_win() << " " << player2.get_name_of_player() << endl;
			restart = true;
		}

	}
}

void Games::checkEndGameConditions(Player &player, Player &otherPlayer)
{
	if (tie == 2)
	{
		gameOver = true;
		winner = "Tie";
		player.up_num_win();
		otherPlayer.up_num_win();
	}
	else if(winner == player.get_name_of_player())
	{
		if (player.get_num_turn() == otherPlayer.get_num_turn())
		{
			gameOver = true;
			player.up_num_win();
		}
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

	if (numOfGames == 0)
	{
		cout << "Combien de partie(s) voulez-vous jouer?" << endl;
		cin >> numOfGames;
	}

	cout << "Joueur1 :" << endl;
	playerPreperations(player1);
	cout << "Joueur2 :" << endl;
	playerPreperations(player2);

	//Sets a random character to start the game
	int randStart = rand() % 2 + 1;
	gameState = randStart;
	if (randStart == 1)
	{
		cout << player1.get_name_of_player() << " commence la partie!" << endl;
		player1.up_num_turn();
	}
	else
	{
		cout << player2.get_name_of_player() << " commence la partie!" << endl;
		player2.up_num_turn();
	}

}

void Games::playerPreperations(Player &player)
{
	char isAI = -1;
	if (player.get_name_of_player() == "AI")
	{
		isAI = 'y';
	}
	else if (player.get_name_of_player() != "Uninitialized")
	{
		isAI = 'n';
	}
	else
	{
		cout << "Est-ce que ce joueur est une IA? [y/n]" << endl;
		cin >> isAI;
	}

	if(isAI == 'y') //If player is bot, a character from the vector is chosen at random
	{
		player.set_name_of_player("AI");
		int randomIndex = rand() % (player.get_board_of_player()->get_character_manager()->get_total_character());
		player.characterSelection(player.get_board_of_player()->get_character_manager()->get_character_vector().at(randomIndex)->get_id());
		player.set_is_cpu(true);

	}
	else { //Only human player choses a character
		int charID;

		if (player.get_name_of_player() == "Uninitialized")
		{
			string playerName;
			cout << "Veuillez entrer votre nom: " << endl;
			cin >> playerName;

			player.set_name_of_player(playerName);
		}

		cout << "Veuillez entrer l'ID de votre personnage: " << endl;
		cin >> charID;
		player.characterSelection(charID);
		cout << player.get_character_selected()->get_id() << endl;
	}
}

void Games::reinitializeBoard()
{
	for (int i = 0; i < player1.get_board_of_player()->get_character_manager()->get_total_character(); i++)
	{
		player1.get_board_of_player()->get_character_manager()->get_character_vector().at(i)->set_is_hidden(false);
		player2.get_board_of_player()->get_character_manager()->get_character_vector().at(i)->set_is_hidden(false);
	}
	player1.get_board_of_player()->get_character_manager()->set_num_character_hidden(0);
	player2.get_board_of_player()->get_character_manager()->set_num_character_hidden(0);
	player1.set_num_turn(0);
	player2.set_num_turn(0);
	tie = 0;
	gameOver = false;
	winner = "";
}

void Games::reinitialize()
{
	player1.set_name_of_player("Uninitialized");
	player2.set_name_of_player("Uninitialized");
	player1.set_num_win(0);
	player2.set_num_win(0);
	numOfGames = 0;
	numOfGamesPlayed = 0;
	gameOver = false;
}

void Games::inputGame(Player &player, Player &otherPlayer)
{

	if (player.is_is_cpu()) {
		//No need to read fpga here
		cout << player.get_name_of_player() << " | tour : " << player.get_num_turn() << endl;
		cout << "Nombre de personage caches (AI): " << player.get_board_of_player()->get_character_manager()->get_num_character_hidden() << "/" << player.get_board_of_player()->get_character_manager()->get_total_character() << endl;
		cout << "Nombre de personage caches (vous): " << otherPlayer.get_board_of_player()->get_character_manager()->get_num_character_hidden() << "/" << otherPlayer.get_board_of_player()->get_character_manager()->get_total_character() << endl;
		vector<int> question;
		question = player.cpuQuestionGeneretor(50, otherPlayer);

		answerBotQuestion(question[0], question[1], player, otherPlayer);

	}

	else {
		cout << player.get_name_of_player() << " | tour : " << player.get_num_turn() <<  endl;
		cout << "Nombre de personage caches (vous): " << player.get_board_of_player()->get_character_manager()->get_num_character_hidden() << "/" << player.get_board_of_player()->get_character_manager()->get_total_character() << endl;
		cout << "Nombre de personage caches (autre joueur): " << otherPlayer.get_board_of_player()->get_character_manager()->get_num_character_hidden() << "/" << otherPlayer.get_board_of_player()->get_character_manager()->get_total_character() << endl;
		cout << "Quelle est votre choix pour une propriete?" << endl;
		cout << "0 - Yeux" << endl << "1 - Cheveux" << endl
			<< "2 - Traits Cheveux" << endl << "3 - Couleur de peau" << endl
			<< "4 - Accessoires" << endl << "5 - Poils faciaux" << endl
			<< "6 - Age" << endl << "7 - Genre" << endl << "8 - Deviner tout de suite" << endl;
		int input = 0;
		input = fpgaCommunicationInputHandler();
		/*
		if(input == fpgaCommunication.FPGA_READING_ERROR)
		{
			return;
		}*/
		int characteristicsSlected = input;
		if (input == 8)
		{
			cout << "Enter the character ID: " << endl;
			input = fpgaCommunicationInputHandler();
			searchPlayerCharacteristicsQuestion(characteristicsSlected, input, player, otherPlayer);

		}
		else
		{
			player.get_board_of_player()->get_character_manager()->propertyPrinter(input);
			input = fpgaCommunicationInputHandler();
			searchPlayerCharacteristicsQuestion(characteristicsSlected, input, player, otherPlayer);

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
		question += "Est-ce que votre personnage a un(e)/des ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 6:
		question += "Est-ce que votre personnage est un(e) ";
		question += CharacterTraits::printPhysicalTraitsProperties(input);
		break;

	case 7:
		question += "Est-ce que votre personnage est un(e) ";
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
			tie++;
			winner = player.get_name_of_player();
			player.get_board_of_player()->get_character_manager()->hideCharacter(input);
		}
		else {
			gameOver = true;
			winner = otherPlayer.get_name_of_player();
			otherPlayer.up_num_win();
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
			cout << "Oui" << endl;
		}
		else
		{
			//cout << "Implement when a property has not been found" << endl;
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
		}
	}break;
	case 1:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getHairColor() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 2:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getHairCharacteristics() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 3:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getSkinColor() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 4:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->hasAccessory(input))
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 5:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getFacialHair() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 6:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getAge() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 7:
	{
		if (otherPlayer.get_character_selected()->get_character_traits()->getGender() == input)
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(characteristicsSlected, input);
			cout << "Oui" << endl;
		}
		else
		{
			player.get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(characteristicsSlected, input);
			cout << "Non" << endl;
			//cout << "Implement when a property has not been found" << endl;
		}
	}break;
	case 8:
		{
			if(otherPlayer.get_character_selected()->get_id() == input)
			{
				tie++;
				winner = player.get_name_of_player();
				player.get_board_of_player()->get_character_manager()->hideCharacter(input);
				cout << "Oui" << endl;
			}
			else {
				gameOver = true;
				winner = otherPlayer.get_name_of_player();
				otherPlayer.up_num_win();
				player.get_board_of_player()->get_character_manager()->hideCharacter(input);
				cout << "Non" << endl;
			}
	}break;
	default:
	{
		cout << "Hey, this should not show up, Games.cpp -> searchPlayerCharacteristics method" << endl;
	}break;
	}
}

int Games::fpgaCommunicationInputHandler()
{
	cout << "Parler dans le micro pour entendre votre belle voix et controler le menu! AFFICHER ICI LES PHONEMES ET LEUR FONCTION!!!" << endl;
	int fpgaReadingInput = 0; 
	int userVoiceInput = 0;

	do
	{
		fpgaReadingInput = fpgaCommunication.getPhoneme();
		cout << fpgaReadingInput << endl;
		if(fpgaReadingInput == fpgaCommunication.FPGA_UP_VALUE)
		{
			cout << "Vous montez dans le menu" << endl;
			userVoiceInput++;
		}
		if (fpgaReadingInput == fpgaCommunication.FPGA_DOWN_VALUE)
		{
			cout << "Vous descendez dans le menu" << endl;
			userVoiceInput--;
		}
		if (fpgaReadingInput == fpgaCommunication.FPGA_RETURN_VALUE)
		{
			cout << "Vous retournez en arriere" << endl;
			//TODO: Implement return go back value for menus
		}
		cout << "Current choice: " << userVoiceInput << endl;
	} while (fpgaReadingInput != fpgaCommunication.FPGA_READING_ERROR && fpgaCommunication.FPGA_END_STATEMENT_VALUE != fpgaReadingInput);

	if (fpgaReadingInput == fpgaCommunication.FPGA_READING_ERROR)
	{
		//gameState = CardReadingError;
		cout << "Entrez manuellement la valeur: " << endl;
		cin >> userVoiceInput;
		//userVoiceInput = fpgaCommunication.FPGA_READING_ERROR;
		
		if(userVoiceInput == 20)
		{
			gameOver = true;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Entree invalide!" << endl;
			userVoiceInput = -1;
		}
	}
	return userVoiceInput;
}

bool Games::is_game_over() const
{
	return gameOver;
}

void Games::set_game_over(bool game_over)
{
	gameOver = game_over;
}

bool Games::is_restart() const
{
	return restart;
}

void Games::set_restart(bool restart_)
{
	restart = restart_;
}

int Games::get_num_of_games() const
{
	return numOfGames;
}

void Games::set_num_of_games(int num_of_games)
{
	numOfGames = num_of_games;
}

int Games::get_num_of_games_played() const
{
	return numOfGamesPlayed;
}

void Games::set_num_of_games_played(int num_of_games_played)
{
	numOfGamesPlayed = num_of_games_played;
}

CharacterManager Games::get_character_manager()
{
	return characterManager;
}

void Games::set_character_manager(CharacterManager character_manager)
{
	characterManager = move(character_manager);
}