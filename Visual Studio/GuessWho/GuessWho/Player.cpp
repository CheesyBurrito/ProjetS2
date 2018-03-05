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
	nameOfPlayer = move(name_of_player);
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


