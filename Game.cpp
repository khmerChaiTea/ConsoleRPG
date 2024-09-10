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
		std::cout << "LEVEL UP AVAILABLE!\n\n";
	}

	std::cout << "= Main Menu =" << std::endl << std::endl;

	std::cout << "0: Quit" << std::endl;
	std::cout << "1: Travel" << std::endl;
	std::cout << "2: Shop" << std::endl;
	std::cout << "3: Level up" << std::endl;
	std::cout << "4: Rest" << std::endl;
	std::cout << "5: Character sheet" << std::endl;
	std::cout << "6: Create new character" << std::endl;
	std::cout << "7: Save characters" << std::endl;
	std::cout << "8: Load characters" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Choice: ";
	std::cin >> choice;
	std::cout << std::endl;

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
		std::cin.ignore();
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
	std::string name = "";
	std::cout << "Character name: ";
	std::getline(std::cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}

void Game::saveCharacter()
{
	std::ofstream outFile(fileName);

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

}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event ev;

	ev.generateEvent(this->characters[activeCharacter]);
}
