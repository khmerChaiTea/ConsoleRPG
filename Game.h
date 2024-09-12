#pragma once

#include "Event.h"
#include<ctime>
#include<vector>
#include<sstream>

using namespace std;

class Game
{
private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;

	// Enemies
	dArr<Enemy> enemies;

public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void levelUpCharacter();
	void saveCharacter();
	void loadCharacter();
	void selectCharacter();
	void Travel();

	// Accessors
	inline bool getPlaying() const { return this->playing; };

	// Modifiers
};

