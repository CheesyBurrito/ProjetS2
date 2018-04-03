#include "stdafx.h"
#include "Player.h"



Player::Player()
{
}

Player::Player(Character& characterSelected1)
{
	characterSelected = &characterSelected1;
}

Player::Player(string name1)
{
	nameOfPlayer = name1;
}

Player::~Player()
{
}

bool Player::characterSelection(int characterID)
{
	if (characterID == -1) 
	{
		int randomIndex = rand() % boardOfPlayer->get_character_manager()->get_total_character();
		characterID = boardOfPlayer->get_character_manager()->get_character_vector().at(randomIndex)->get_id();
	}

	for(int i = 0; i < boardOfPlayer->get_character_manager()->get_total_character(); i++)
	{
		if(characterID == boardOfPlayer->get_character_manager()->get_character_vector().at(i)->get_id())
		{
			set_character_selected(boardOfPlayer->get_character_manager()->get_character_vector().at(i));
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}

vector<int> Player::cpuQuestionGeneretor(int target, Player player2)
{
	srand(time(NULL));
	int i, j;
	int rand_num1, rand_num2;
	float difference = 100;
	bool questionOk = false;
	bool continueOk = false;
	bool askQuestion = true;
	vector<int> question(2, 0);
	vector<Character*> characters = get_board_of_player()->get_character_manager()->get_character_vector();
	int totalCharacter = get_board_of_player()->get_character_manager()->get_total_character();
	int numCharacterHidden = get_board_of_player()->get_character_manager()->get_num_character_hidden();
	int numPlayerVisible = totalCharacter - numCharacterHidden;

	//If there are two characters left, take a guess
	if (numPlayerVisible == 1)
	{
		askQuestion = false;
		question.at(0) = 8;
		for (i = 0; i < totalCharacter; i++)
		{
			if (characters.at(i)->is_is_hidden() == false)
				question.at(1) = characters.at(i)->get_id();
		}
	}
	else if (player2.get_board_of_player()->get_character_manager()->get_num_character_hidden() >= totalCharacter - 1)
	{
		bool randOk = false;
		int randomCharacter = rand() % numPlayerVisible + 1;
		int counter = 0;

		if (player2.get_board_of_player()->get_character_manager()->get_num_character_hidden() == totalCharacter)
			randOk = true;
		else
		{
			if(get_num_turn() != player2.get_num_turn())
				randOk = true;
				
		}

		if (randOk == true)
		{
			askQuestion = false;
			question.at(0) = 8;
			for (i = 0; i < totalCharacter; i++)
			{
				if (characters.at(i)->is_is_hidden() == false)
				{
					counter++;
					if (counter == randomCharacter)
						question.at(1) = characters.at(i)->get_id();
				}
			}
		}
	}
	if(askQuestion == true)
	{
		//Initialize the value to 0
		float characterTraitsCounter[8][16];
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 16; j++)
				characterTraitsCounter[i][j] = 0;
		}

		//Calculate the traits of the characters
		for (i = 0; i < totalCharacter; i++) {
			if (characters.at(i)->is_is_hidden() == false) {
				characterTraitsCounter[0][characters.at(i)->get_character_traits()->getEyes()] += 1;
				characterTraitsCounter[1][characters.at(i)->get_character_traits()->getHairColor()] += 1;
				characterTraitsCounter[2][characters.at(i)->get_character_traits()->getHairCharacteristics()] += 1;
				characterTraitsCounter[3][characters.at(i)->get_character_traits()->getSkinColor()] += 1;
				characterTraitsCounter[5][characters.at(i)->get_character_traits()->getFacialHair()] += 1;
				characterTraitsCounter[6][characters.at(i)->get_character_traits()->getAge()] += 1;
				characterTraitsCounter[7][characters.at(i)->get_character_traits()->getGender()] += 1;
				int accessories = characters.at(i)->get_character_traits()->getAccessories().size();
				for (j = 0; j < accessories; j++)
					characterTraitsCounter[4][characters.at(i)->get_character_traits()->getAccessories().at(j)] += 1;
			}
		}

		//Put the value in pourcentage
		for (i = 0; i < 8; i++)
		{
			cout << endl;
			for (j = 0; j < 16; j++)
			{	
				characterTraitsCounter[i][j] /= (float)numPlayerVisible;
				characterTraitsCounter[i][j] *= 100.0;
				cout << characterTraitsCounter[i][j] << " ";
				if (target != -1)
				{
					if (abs(characterTraitsCounter[i][j] - target) < difference && characterTraitsCounter[i][j] > 0 && characterTraitsCounter[i][j] < 100)
					{
						difference = abs(characterTraitsCounter[i][j] - target);
						question.at(0) = i;
						question.at(1) = j;
					}
				}
			}
		}

		if (target == -1)
		{
			while (questionOk == false)
			{
				rand_num1 = rand() % 8;
				for (i = 0; i < 16; i++)
				{
					if (characterTraitsCounter[rand_num1][i] > 0 && characterTraitsCounter[rand_num1][i] < 100)
					{
						continueOk = true;
					}
				}
				if (continueOk == true)
				{
					while (questionOk == false)
					{
						rand_num2 = rand() % 16;
						if (characterTraitsCounter[rand_num1][rand_num2] > 0 && characterTraitsCounter[rand_num1][rand_num2] < 100)
						{
							question.at(0) = rand_num1;
							question.at(1) = rand_num2;
							questionOk = true;
						}
					}
				}
			}
		}
	}

	return question;
}

void Player::up_num_turn()
{
	numTurn++;
}

void Player::up_num_win()
{
	numWin++;
}

bool Player::is_is_cpu() const
{
	return isCPU;
}

void Player::set_is_cpu(bool is_cpu)
{
	isCPU = is_cpu;
}

string Player::get_name_of_player() const
{
	return nameOfPlayer;
}

void Player::set_name_of_player(string name_of_player)
{
	nameOfPlayer = name_of_player;
}

Character* Player::get_character_selected() const
{
	return characterSelected;
}

void Player::set_character_selected(Character* character_selected)
{
	characterSelected = character_selected;
}

Board* Player::get_board_of_player() const
{
	return boardOfPlayer;
}

void Player::set_board_of_player(Board* board_of_player)
{
	boardOfPlayer = board_of_player;
}

void Player::set_num_turn(int turn)
{
	numTurn = turn;
}

int Player::get_num_turn() const
{
	return numTurn;
}

void Player::set_num_win(int win)
{
	numWin = win;
}

int Player::get_num_win() const
{
	return numWin;
}



