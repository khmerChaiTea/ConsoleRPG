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
	vector<Character> characters;
	string fileName;

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
	void travel();
	void rest();

	// Accessors
	inline bool getPlaying() const { return this->playing; };

	// Modifiers
};
