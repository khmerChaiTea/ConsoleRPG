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
	createNewCharacter();
}

void Game::mainMenu()
{
	if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
	{
		cout << "LEVEL UP AVAILABLE!\n\n";
	}

	cout << "= Main Menu =" << endl << endl;

	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;
	cout << "6: Create new character" << endl;
	cout << "7: Save characters" << endl;
	cout << "8: Load characters" << endl;
	cout << endl;

	cout << endl << "Choice: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 0: // Quit
		playing = false;
		break;

	case 1: // Travel

		Travel();

		break;

	case 2: // Shop
	
		break;

	case 3: // Level Up
		this->characters[activeCharacter].levelUP();
		break;

	case 4: // Rest

		break;

	case 5: // Character sheet
		characters[activeCharacter].printStats();
		break;

	case 6: // Create character
		cin.ignore();
		createNewCharacter();
		saveCharacter();
		break;

	case 7: // Save character
		saveCharacter();
		break;

	case 8: // Load character
		loadCharacter();
		break;

	default:
		break;
	}
}

void Game::createNewCharacter()
{
	string name = "";
	cout << "Character name: ";
	getline(cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
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
	stringstream str;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			str.str() = line;
			// Read from the file as long as the input operation succeeds
			str >> name;
			str >> distanceTraveled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;
			str	>> skillPoints;

			Character temp(name, distanceTraveled, gold, level,
				exp, strength, vitality, dexterity, intelligence,
				hp, stamina, statPoints, skillPoints);
			this->characters.push_back(Character(temp));

			cout << "Character" << name << "loaded!\n";
			str.clear();
		}
	}
	else
	{
		cerr << "Unable to open file!" << endl;
	}

	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw "ERROR! NO CHARACTER LOADED! OR EMPTY FILE!";
	}
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event ev;

	ev.generateEvent(this->characters[activeCharacter]);
}
