#pragma once
#include "CharacterManager.h"
#include "Board.h"
#include "Player.h"
using namespace std;

class Games
{
private:
	//Indicates if the is over. When the value is true, the game ends
	bool gameOver = false;
	CharacterManager characterManager;
	Player player1;
	Player player2;
public:
	Games();
	~Games();

	//General Methods
	void gameLoop(); //Called by start to enter the game loop
	void start(); //Called to start the game
	void inputGame(); //Called to register the inputs of the game
	void calculationGame(); //Called after the input to do the calculation absed on the input
	void renderGame(); //Called to render the graphical elements of the game
	void preperationGame(); //Called before the start of the game, used to initialize the game's elements and the pre-input preperation
	void copyCharacterManagerToPlayer(Player player);
	//Setters and Getters

	bool is_game_over() const;
	void set_game_over(bool game_over);
	CharacterManager get_character_manager() const;
	void set_character_manager(CharacterManager character_manager);
	Board get_board_player1() const;
	void set_board_player1(Board board_player1);
	Board get_board_player2() const;
	void set_board_player2(Board board_player2);
};

