#pragma once
#include "CharacterManager.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include "FPGA.h"
#include <time.h>

class Games
{
private:
	
	bool gameOver = false; //Indicates if the is over. When the value is true, the game ends
	bool restart = true;
	CharacterManager characterManager;
	Player player1;
	Player player2;
	enum gameStateEnum { Pause, player1Turn, player2Turn, CardReadingError }; //Indicates the possible states of the game
	int gameState = player1Turn; //Indicates the current state of the game
	int tie = 0;
	int numOfGames = 0;
	int numOfGamesPlayed = 0;
	string winner;
	FPGA fpgaCommunication;
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
	void reinitializeBoard();//restart the game with new board
	void reinitialize();//restart the game with the same player
	void copyCharacterManagerToPlayer(Player player); //Called when a copy of the character manager has to be done
	void playerPreperations(Player &player); //Prepares the player object, by modifying the name and if it is an AI
	void searchPlayerCharacteristicsQuestion(int characteristicsSlected, int input, Player &player, Player &otherPlayer); //Search for the characters with the specific characteristic
	void checkEndGameConditions(Player &player,Player &otherPlayer); //Method to check if the end game has been met
	void answerBotQuestion(int characteristicsSlected, int input, Player& player, Player& otherPlayer); //Method that will ask the user to answer a bots question
	int fpgaCommunicationInputHandler(); //Method to read the input of the player, if fails, will switch to manual mode
	
	//Setters and Getters
	bool is_game_over() const;
	void set_game_over(bool game_over);
	bool is_restart() const;
	void set_restart(bool restart_);
	int get_num_of_games() const;
	void set_num_of_games(int num_of_games);
	int get_num_of_games_played() const;
	void set_num_of_games_played(int num_of_games_played);
	CharacterManager get_character_manager();
	void set_character_manager(CharacterManager character_manager);
	Board get_board_player1() const;
	void set_board_player1(Board board_player1);
	Board get_board_player2() const;
	void set_board_player2(Board board_player2);
};

