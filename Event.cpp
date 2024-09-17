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
	bool playerTurn = false;
	int choice = 0;

	// Coint toss for turn
	int coinToss = rand() % 2 + 1;

	if (coinToss == 1)
		playerTurn = true;
	else
		playerTurn = false;

	// End conditions
	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;

	// Enemies
	int nrOfEnemies = rand() % 5 + 1;

	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies.push(Enemy(character.getLevel() + rand() % 3));
	}

	// Battle variables
	int damage = 0;
	int gainExp = 0;
	int playerTotal = 0;
	int enemyTotal = 0;
	int combatTotal = 0;
	int combatRollPlayer = 0;
	int combatRollEnemy = 0;

	while (!escape && !playerDefeated && !enemiesDefeated)
	{
		if (playerTurn && !playerDefeated)
		{
			// Menu
			//system("CLS");

			cout << "= Battle Menu =" << "\n\n";

			cout << "0: Escape" << "\n";
			cout << "1: Attack" << "\n";
			cout << "2: Defend" << "\n";
			cout << "3: Use Item" << "\n";
			cout << "\n";

			cout << "Choice: ";

			cin >> choice;

			while (cin.fail() || choice > 3 || choice < 0)
			{
				system("CLS");

				cout << "Faulty input!" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout << "= Battle Menu =" << "\n\n";

				cout << "0: Escape" << "\n";
				cout << "1: Attack" << "\n";
				cout << "2: Defend" << "\n";
				cout << "3: Use Item" << "\n";
				cout << "\n";

				cout << "Choice: ";
				cin >> choice;
			}

			cin.ignore(100, '\n');
			cout << "\n";

			// Moves
			switch (choice)
			{
			case 0: // Escape
				escape = true;
				break;

			case 1: // Attack
				// Select Enemy
				cout << "Select enemy:" << "\n\n";

				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << i << ": "
						<< "Level: " << enemies[i].getLevel() << " - " <<
						"Hp: " << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - " <<
						"Defense: " << enemies[i].getDefense() << " - " <<
						"Accuracy: " << enemies[i].getAccuracy() << " - " <<
						"\n";
				}

				cout << "\n";
				cout << "Choice: ";

				cin >> choice;

				while (cin.fail() || choice >= enemies.size() || choice < 0)
				{
					cout << "Faulty input!" << "\n";
					cin.clear();
					cin.ignore(100, '\n');

					cout << "Select enemy:" << "\n\n";

					cout << "Choice: ";
					cin >> choice;
				}

				cin.ignore(100, '\n');
				cout << "\n";

				// Attack roll

				combatTotal = enemies[choice].getDefense() + character.getAccuracy();
				enemyTotal = enemies[choice].getDefense() / (double)combatTotal * 100;
				playerTotal = character.getAccuracy() / (double)combatTotal * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;

				cout << "Player roll: " << combatRollPlayer << "\n";
				cout << "Enemy roll: " << combatRollEnemy << "\n\n";

				if (combatRollPlayer > combatRollEnemy) // Hit
				{
					cout << "HIT!" << "\n\n";

					damage = character.getDamage();
					enemies[choice].takeDamage(damage);
					cout << "Damage: " << damage << "!\n\n";

					if (!enemies[choice].isAlive())
					{
						cout << "ENEMY DEFEATED!\n\n";
						gainExp = enemies[choice].getExp();
						character.gainExp(gainExp);
						cout << "EXP GAINED: " << gainExp << "\n\n";
						enemies.remove(choice);
					}
				}
				else // Miss
				{
					cout << "MISSED!\n\n";
				}

				break;

			case 2: // Defend

				break;

			case 3: // Item

				break;

			default:
				break;
			}

			// End turn
			playerTurn = false;
		}
		else if (!playerTurn && !escape && !enemiesDefeated)
		{
			cout << "= ENEMY TURN =" << "\n";

			// Enemy attack
			for (size_t i = 0; i < enemies.size(); i++)
			{
				cout << "Enemy: " << i << "\n";

				cout << "Player roll: " << combatRollPlayer << "\n";
				cout << "Enemy roll: " << combatRollEnemy << "\n\n";

				if (combatRollPlayer < combatRollEnemy) // Hit
				{
					cout << "HIT!" << "\n\n";

					damage = enemies[i].getDamage();
					character.takeDamage(damage);
					cout << "Damage: " << damage << "!\n\n";

					if (!character.isAlive())
					{
						cout << "YOT ARE DEFEATED!\n\n";
						playerDefeated = true;
					}
				}
				else // Miss
				{
					cout << "MISSED!\n\n";
				}
			}

			// End turn
			playerTurn = true;
		}

		// Conditions

		if (!character.isAlive())
		{
			playerDefeated = true;
		}

		if (enemies.size() <= 0)
		{
			enemiesDefeated = true;
		}
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
