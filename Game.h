#pragma once

#include<ctime>
#include "Character.h"
#include<vector>
#include<fstream>

class Game
{
private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;

public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void saveCharacter();
	void loadCharacter();

	// Accessors
	inline bool getPlaying() const { return this->playing; };

	// Modifiers
};

