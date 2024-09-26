#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";
}

Game::~Game()
{

}

// Functions
void Game::initGame()
{
	ifstream in;
	in.open("characters.txt");

	if (in.is_open())
		this->loadCharacter();
	else
	{
		createNewCharacter();
		this->saveCharacter();
	}

	// Clone functions help create weapons and armors
	//Weapon w1;
	//Armor a1;
	//Item* item = w1.clone();
	//Item* item2 = a1.clone();

	//Weapon* w = dynamic_cast<Weapon*>(item);
	//if (w != nullptr)
	//	cout << w->getDamageMax() << "\n";

	//Armor* a = dynamic_cast<Armor*>(item2);
	//if (a != nullptr)
	//	cout << a->getDefense() << "\n";

	//delete item;
	//delete item2;

	in.close();
}

void Game::mainMenu()
{
	cout << "ENTER to continue..." << "\n";
	cin.get();
	system("CLS");

	if (this->characters[activeCharacter].isAlive())
	{
		if (this->characters[activeCharacter].getExp() >=
			this->characters[activeCharacter].getExpNext())
		{
			cout << "LEVEL UP AVAILABLE!\n\n";
		}

		cout << "= Main Menu =" << "\n\n";

		cout << "= Active character: " <<
			this->characters[activeCharacter].getName() << " Nr: "
			<< this->activeCharacter + 1 << "/" << this->characters.size() <<
			" =\n\n";

		cout << "0: Quit" << "\n";
		cout << "1: Travel" << "\n";
		cout << "2: Shop" << "\n";
		cout << "3: Level up" << "\n";
		cout << "4: Rest" << "\n";
		cout << "5: Character sheet" << "\n";
		cout << "6: Create new character" << "\n";
		cout << "7: Select characters" << "\n";
		cout << "8: Save characters" << "\n";
		cout << "9: Load characters" << "\n";

		cout << "\n";

		cout << "\n" << "Choice: ";
		cin >> this->choice;

		while (cin.fail())
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\n" << "Choice: ";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0: // Quit
			playing = false;
			this->saveCharacter();
			break;

		case 1: // Travel
			travel();
			break;

		case 2: // Shop

			break;

		case 3: // Level Up
			levelUpCharacter();
			break;

		case 4: // Rest
			rest();
			break;

		case 5: // Character sheet
			characters[activeCharacter].printStats();
			break;

		case 6: // Create character
			createNewCharacter();
			saveCharacter();
			break;

		case 7: // Load character
			selectCharacter();
			break;

		case 8: // Save character
			saveCharacter();
			cout << "Character saved successfully.\n";
			break;

		case 9: // Load character
			loadCharacter();
			break;

		default:
			break;
		}
	}
	else
	{
		cout << "= YOU ARE DEAD, LOAD? =" << "\n\n";
		cout << "(0) Yes, (1) No" << "\n";
		cin >> this->choice;

		while (cin.fail() || this->choice < 0 || this->choice > 1)
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "(0) Yes, (1) No" << "\n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (this->choice == 0)
			this->loadCharacter();
		else
			playing = false;
	}
}

void Game::createNewCharacter()
{
	string name = "";
	cout << "Character name: ";
	getline(cin, name);

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			cout << "Error! Caracter already exists!\n";
			cout << "Character name: ";
			getline(cin, name);
		}
	}

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}

void Game::levelUpCharacter()
{
	this->characters[activeCharacter].levelUP();

	if (this->characters[activeCharacter].getStatPoints() > 0)
	{
		cout << "You have stat points to allocate!\n\n";
		cout << "Stat to upgrade:\n";
		cout << "0: Strength\n";
		cout << "1: Vitality\n";
		cout << "2: Dexterity\n";
		cout << "3: Intelligence\n";

		cin >> this->choice;

		while (cin.fail() || this->choice > 3 || this->choice < 0)
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Stat to upgrade:\n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0: // Strength
			this->characters[activeCharacter].addToStat(0, 1);
			break;

		case 1: // Vitality
			this->characters[activeCharacter].addToStat(1, 1);
			break;

		case 2: // Dexterity
			this->characters[activeCharacter].addToStat(2, 1);
			break;

		case 3: // Intelligence
			this->characters[activeCharacter].addToStat(3, 1);
			break;

		default:
			break;
		}
	}
}

void Game::saveCharacter()
{
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}

	outFile.close();
}

void Game::loadCharacter()
{
	ifstream inFile(fileName);

	this->characters.clear();

	string name = "";
	int distanceTraveled = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int hp = 0;
	int stamina = 0;
	int statPoints = 0;
	int skillPoints = 0;

	string line = "";

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			stringstream str(line); // Initialize stringstream with the line content

			// Read all the character attributes from the line
			str >> name >> distanceTraveled >> gold >> level >> exp
				>> strength >> vitality >> dexterity >> intelligence
				>> hp >> stamina >> statPoints >> skillPoints;

			Character temp(name, distanceTraveled, gold, level,
				exp, strength, vitality, dexterity, intelligence,
				hp, stamina, statPoints);
			this->characters.push_back(temp);

			cout << "Character " << name << " loaded!\n";
		}

		inFile.close();
	}
	else
	{
		cerr << "Unable to open file!" << "\n";
	}

	if (this->characters.size() == 0)
	{
		throw "ERROR! NO CHARACTER LOADED! OR EMPTY FILE!";
	}
}

void Game::selectCharacter()
{
	cout << "Select character:\n\n";

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		cout << "Index: " << i << " = " << this->characters[i].getName() << " Level: " << this->characters[i].getLevel() << "\n";
	}

	cout << "\n";
	cout << "Choice: ";

	cin >> this->choice;

	while (cin.fail() || this->choice > this->characters.size() || this->choice < 0)
	{
		cout << "Faulty input!" << "\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Select character:\n";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << "\n";

	this->activeCharacter = this->choice;

	cout << this->characters[this->activeCharacter].getName() << " is SELECTED!\n\n";
}

void Game::travel()
{
	this->characters[activeCharacter].travel();

	Event ev;

	ev.generateEvent(this->characters[activeCharacter], this->enemies);
}

void Game::rest()
{
	int restCost = this->characters[this->activeCharacter].getHpMax() -
		this->characters[this->activeCharacter].getHp();
	cout << "= Rest =" << "\n\n";
	cout << "Resting costs you: " << restCost << "\n";
	cout << "Your gold: " << this->characters[this->activeCharacter].getGold() << "\n";
	cout << "HP: " << this->characters[this->activeCharacter].getHp() <<
		" / " << this->characters[this->activeCharacter].getHpMax() << "\n\n";

	if (this->characters[this->activeCharacter].getGold() < restCost)
	{
		cout << "NOT ENOUGH MONEY, SORRY BUDDY!" << "\n\n";
	}
	else if (this->characters[this->activeCharacter].getHp() >= this->characters[this->activeCharacter].getHpMax())
	{
		cout << "ALREADY AT FULL HEALTH BUDDY!" << "\n\n";
	}
	else
	{

		cout << "Rest? (0) Yes, (1) No..." << "\n";

		cin >> this->choice;

		while (cin.fail() || this->choice < 0 || this->choice > 1)
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Rest? (0) Yes, (1) No..." << "\n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (this->choice == 0)
		{
			this->characters[this->activeCharacter].resetHP();
			this->characters[this->activeCharacter].payGold(restCost);
			cout << "RESTED!" << "\n";
		}
		else
		{
			cout << "MAYBE NEXT TIME!" << "\n";
		}
	}
}
