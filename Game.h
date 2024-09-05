#pragma once

#include<iostream>
#include<iomanip>
#include<ctime>
#include "Functions.h"
#include "Character.h"

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void mainMenu();

	// Accessors
	inline bool getPlaying() const { return this->playing; };

	// Modifiers

private:
	int choice;
	bool playing;
};

