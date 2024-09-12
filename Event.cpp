#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{
}

void Event::generateEvent(Character& character, dArr<Enemy>& enemies)
{
	int i = rand() % this->nrOfEvents;

	switch (i)
	{
	case 0:
		// Enemy encounter
		enemyEncounter(character, enemies);
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
void Event::enemyEncounter(Character& character, dArr<Enemy>& enemies)
{
	bool escape = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;

	while (!escape && !playerDefeated && !enemyDefeated)
	{

	}
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
		cout << "Chances: " << chances << "\n\n";
		chances--;
		cout << puzzle.getAsString() << "\n";

		cout << "Your Answer: ";
		cin >> userAns;

		while (cin.fail())
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Your Answer: ";
			cin >> userAns;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;

			character.gainExp(gainExp);
			cout << "YOU GAINED " << gainExp << " EXP!\n\n";
		}
	}

	if (completed)
	{
		cout << "Congrats Puzzle is solved!\n\n";
	}
	else
	{
		cout << "Failed!\n\n";
	}

}
