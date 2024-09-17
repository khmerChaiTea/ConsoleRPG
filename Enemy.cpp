#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;
	this->damageMin = this->level * 1;
	this-> damageMax = this->level * 3;
	this->dropChance = rand() % 100 + 1;
	this->defense = rand() % level * 5 + 1;
	this->accuracy = rand() % level * 5 + 1;
}

Enemy::~Enemy()
{
}

std::string Enemy::getAsString() const
{
	return "Level: " + std::to_string(this->level) + "\n" +
		"Hp: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"Damage: " + std::to_string(this->damageMin) + " - " + std::to_string(this->damageMax) + "\n" +
		"Defense: " + std::to_string(this->defense) + "\n" +
		"Accuracy: " + std::to_string(this->accuracy) + "\n" +
		"Drop chance: " + std::to_string(this->dropChance) + "\n";
}

void Enemy::takeDamage(int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;


	}
}
