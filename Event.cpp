#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{
}

void Event::generateEvent(Character& character)
{
	int i = rand() % this->nrOfEvents;

	switch (i)
	{
	case 0:
		// Enemy encounter
		enemyEncounter(character);
		break;

	case 1:
		// Puzzle
		puzzleEncounter(character);
		break;

	case 2:
		break;

	default:
		break;
	}
}

// Difference events
void Event::enemyEncounter(Character& character)
{
	// While()
}

void Event::puzzleEncounter(Character& character)
{
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	int gainExp = chances * character.getLevel() * (rand() % 10 + 1);

	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		std::cout << chances << "\n\n";
		chances--;
	
		std::cout << puzzle.getAsString() << "\n";

		std::cout << "\nYour Answer: ";
		std::cin >> userAns;
		std::cout << "\n";

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;

			character.gainExp(gainExp);
			std::cout << "YOU GAINED " << gainExp << " EXP!\n\n";
		}
	}

	if (completed)
	{
		std::cout << "Congrats Puzzle is solved!\n\n";
	}
	else
	{
		std::cout << "Failed!\n\n";
	}

}
