#pragma once

#include "Inventory.h"
#include "Enemy.h"

class Character
{
private:
	double xPos;
	double yPos;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;

	std::string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;


	int hpMax;
	int hp;
	int staminaMax;
	int stamina;
	int damageMin;
	int damageMax;
	int defense;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;

public:
	Character();
	virtual ~Character();

	// Functions
	void initialize(const std::string name);
	void printStats() const;
	void levelUP();
	std::string getAsString() const;

	// Accessors
	inline const double& getX() const { return this->xPos; }
	inline const double& getY() const { return this->yPos; }
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getAccuracy() const { return this->accuracy; }

	// Modifier
};

