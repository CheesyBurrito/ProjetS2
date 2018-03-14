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
	enum gameStateEnum { Pause, player1Turn, player2Turn }; //Indicates the possible states of the game
	int gameState = 1; //Indicates the current state of the game
public:
	Games();
	~Games();

	//General Methods
	void gameLoop(); //Called by start to enter the game loop
	void start(); //Called to start the game
	void inputGame(Player &player, Player &otherPlayer); //Called to register the inputs of the game
	void calculationGame(Player &player); //Called after the input to do the calculation absed on the input
	void renderGame(Player &player); //Called to render the graphical elements of the game
	void preperationGame(); //Called before the start of the game, used to initialize the game's elements and the pre-input preperation
	void copyCharacterManagerToPlayer(Player player); //Called when a copy of the character manager has to be done
	void playerPreperations(Player &player); //Prepares the player object, by modifying the name and if it is an AI
	void searchPlayerCharacteristicsQuestion(int characteristicsSlected, int input, Player &player, Player &otherPlayer);


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

