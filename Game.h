#pragma once

#include "Event.h"
#include<ctime>
#include<vector>

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
	void Travel();

	// Accessors
	inline bool getPlaying() const { return this->playing; };

	// Modifiers
};

