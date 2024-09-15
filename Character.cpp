#include "Character.h"

Character::Character()
{
	this->distanceTraveled = 0;

	this->gold = 0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defense = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::Character(string name, int distanceTraveled,
	int gold, int level, int exp, int strength,
	int vitality, int dexterity, int intelligence,
	int hp, int stamina, int statPoints, int skillPoints)
{
	this->distanceTraveled = distanceTraveled;

	this->gold = gold;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defense = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = statPoints;
	this->skillPoints = skillPoints;

	this->updateStats();
}

Character::~Character()
{
}

// Functions
void Character::initialize(const string name)
{
	this->distanceTraveled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->statPoints = 0;
	this->skillPoints = 0;

	this->updateStats();
}

void Character::printStats() const
{
	cout << "= Character Sheet =" << "\n";
	cout << "\n";
	cout << "= Name: " << this->name << "\n";
	cout << "= Level: " << this->level << "\n";
	cout << "= Exp: " << this->exp << "\n";
	cout << "= Exp to next level: " << this->expNext << "\n";
	cout << "\n";
	cout << "= Strength: " << this->strength << "\n";
	cout << "= Vitality: " << this->vitality << "\n";
	cout << "= Dexterity: " << this->dexterity << "\n";
	cout << "= Intelligence: " << this->intelligence << "\n";
	cout << "\n";
	cout << "= HP: " << this->hp << " / " << this->hpMax << "\n";
	cout << "= Stamina: " << this->stamina << " / " << this->staminaMax << "\n";
	cout << "= Damage: " << this->damageMin<< " - " << this->damageMax << "\n";
	cout << "= Defense: " << this->defense << "\n";
	cout << "= Accuracy: " << this->accuracy << "\n";
	cout << "= Luck: " << this->luck << "\n";
	cout << "\n";
}

string Character::getAsString() const
{
	return name + " "
		+ to_string(distanceTraveled) + " "
		+ to_string(gold) + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(strength) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(hp) + " "
		+ to_string(stamina) + " "
		+ to_string(statPoints) + " "
		+ to_string(skillPoints);
}

void Character::levelUP()
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) -
			6 * pow(level, 2)) +
			17 * level - 12)) + 100;

		this->statPoints++;
		this->skillPoints++;

		this->updateStats();

		cout << "YOU ARE NOW LEVEL " << this->level << "!\n\n";
	}
	else
	{
		cout << "NOT ENOUGH EXP!\n\n";
	}
}

void Character::updateStats()
{
	this->expNext = static_cast<int>(
		(50 / 3) * ((pow(level, 3)
			- 6 * pow(level, 2)) +
			17 * level - 12)) + 100;

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->hp = this->hpMax;
	this->staminaMax = (this->vitality) + (this->strength / 2) + (this->dexterity / 3);
	this->stamina = this->staminaMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defense = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2) + this->intelligence;
	this->luck = this->intelligence;
}

void Character::addToStat(int stat, int value)
{
	if (this->statPoints < value)
		cout << "ERROR! NOT ENOUGHT STATPOINTS!\n";
	else
	{
		switch (stat)
		{
		case 0:
			this->strength += value;
			cout << "STRENGTH INCREASED!\n";
			break;

		case 1:
			this->vitality += value;
			cout << "VITALITY INCREASED!\n";
			break;

		case 2:
			this->dexterity += value;
			cout << "DEXTERITY INCREASED!\n";
			break;

		case 3:
			this->intelligence += value;
			cout << "INTELLIGENCE INCREASED!\n";
			break;

		default:
			cout << "NO SUCH STAT!\n";
			break;
		}

		this->statPoints -= value;
	}
}

void Character::takeDamage(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp <= 0;
	}
}
