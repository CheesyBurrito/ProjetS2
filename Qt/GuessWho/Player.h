/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

Player.h
*****************************************/

#pragma once
#include "Character.h"
#include "Board.h"
#include <time.h>

class Player
{
private:
	bool isCPU = false;
	int numTurn = 0;
	int numWin = 0;
	string nameOfPlayer = "Uninitialized";
	Character *characterSelected;
	Board* boardOfPlayer = new Board();
	

public:
	//Constructor and Deconstructor
	Player();
	Player(Character &characterSelected1);
	Player(string name1);
	~Player();

	//General methods
	bool characterSelection(int characterID);
	void up_num_turn();
	void up_num_win();
	vector<int> cpuQuestionGeneretor(int target, Player player2);
	void generateRandomCharacter();

	//Setter and Getters
	bool is_is_cpu() const;
	void set_is_cpu(bool is_cpu);
	string get_name_of_player() const;
	void set_name_of_player(string name_of_player);
	Character* get_character_selected() const;
	void set_character_selected(Character* character_selected);
	Board* get_board_of_player() const;
	void set_board_of_player(Board* board_of_player);
	int get_num_turn() const;
	void set_num_turn(int turn);
	int get_num_win() const;
	void set_num_win(int win);
	
};

