#pragma once

#include "Inventory.h"
#include "Enemy.h"

using namespace std;

class Character
{
private:
	int distanceTraveled;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
	int gold;

	string name;
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
	Character(string name, int distanceTraveled,
		int gold, int level, int exp, int strength,
		int vitality, int dexterity, int intelligence,
		int hp, int stamina, int statPoints, int skillPoints);
	virtual ~Character();

	// Functions
	void initialize(const string name);
	void printStats() const;
	string getAsString() const;
	void levelUP();
	void updateStats();
	void addToStat(int stat, int value);

	// Accessors
	inline const int& getDistTravel() const { return this->distanceTraveled; }
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getStatPoints() const { return this->statPoints; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const bool isAlive() { return this->hp > 0; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getAccuracy() const { return this->accuracy; }

	// Modifier
	inline void setDistTraveled(const int& distance) { this->distanceTraveled = distance; }
	inline void travel() { this->distanceTraveled++; }
	inline void gainExp(const int& exp) { this->exp += exp; }
	void takeDamage(const int damage);
};
