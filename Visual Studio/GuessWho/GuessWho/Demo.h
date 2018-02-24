#pragma once
#include "CharacterManager.h"

class Demo
{
private:
	CharacterManager characterManager;
	int idCounter;
public:
	void start();
	void addCharacter();
	Demo();
	~Demo();
};

