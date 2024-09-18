#pragma once

#include<stdlib.h>
#include<string>

class Enemy
{
private:
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	float dropChance;
	int defense;
	int accuracy;

public:
	Enemy(int level = 0);
	virtual ~Enemy();

	inline bool isAlive() { return this->hp > 0; }
	std::string getAsString() const;
	void takeDamage(int damage);

	inline int getLevel() const { return this->level; }
	inline int getDamageMin() const { return this->damageMin; }
	inline int getDamageMax() const { return this->damageMax; }
	inline int getDamage() const { return this->damageMin + rand() % (this->damageMax - this->damageMin + 1);	}
	inline int getExp() const { return this->level * 100; }
	inline int getHp() const { return this->hp; }
	inline int getHpMax() const { return this->hpMax; }
	inline int getDefense() const { return this->defense; }
	inline int getAccuracy() const { return this->accuracy; }
};
