#pragma once
#include <string>
using namespace std;

class CharacterManager
{
private:
	bool isShuffle = false;
	bool isLoaded = false;
	int numCharacterHidden;
	int totalCharacter;

	enum physicalTraitsColor {Brun, Vert, Bleu, Rouge, Roux, Blond, Noir, Blanc, Basane, Autre};
	enum physicalTraits {Rien, Chauve, Court, Long, Piercing, Chapeau, Lunette, Tattoo, Rase, BarbePleine, Moustache, Favoris};
public:
	CharacterManager();
	~CharacterManager();
};

