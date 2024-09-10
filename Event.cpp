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

	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		chances--;
		std::cout << puzzle.getAsString() << "\n";

		std::cout << "\nYour Answer: ";
		std::cin >> userAns;
		std::cout << "\n";

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;
			// Give user exp etc and continue
		}
	}

	if (completed)
	{
		std::cout << "Congrats Puzzle is solved!\n";
	}
	else
	{
		std::cout << "Failed!\n";
	}

}
