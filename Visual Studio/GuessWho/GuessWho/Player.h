#pragma once
#include "Character.h"

class Player
{
private:
	bool isCPU = false;
	Character * characterSelected;
public:
	Player();
	~Player();
};

