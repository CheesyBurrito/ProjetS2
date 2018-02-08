#pragma once
#include <string>
using namespace std;

class Character
{
private:
	int ID;
	bool isHidden = true;
	string picturePath;
	string name;
public:
	Character();
	~Character();
};

