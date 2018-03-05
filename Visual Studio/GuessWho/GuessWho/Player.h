#pragma once
#include "Character.h"
#include "Board.h"

class Player
{
private:
	bool isCPU = false;
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
	//Setter and Getters

	bool is_is_cpu() const;
	void set_is_cpu(bool is_cpu);
	string get_name_of_player() const;
	void set_name_of_player(string name_of_player);
	Character* get_character_selected() const;
	void set_character_selected(Character* character_selected);
	Board* get_board_of_player() const;
	void set_board_of_player(Board* board_of_player);
};

