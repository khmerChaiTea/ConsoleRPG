#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpmax = level * 10;
	this->hp = this->hpmax;
	this->damageMin = this->level * 4;
	this-> damageMax = this->level * 5;
	this->dropChance = rand() % 100;
	this->defense = rand() % 100;
	this->accuracy = rand() % 100;
}

Enemy::~Enemy()
{
}

std::string Enemy::getAsString() const
{
	return "Level: " + std::to_string(this->level) + "\n" +
		"Hp: " + std::to_string(this->hp) + " / " + std::to_string(this->hpmax) + "\n" +
		"Damage: " + std::to_string(this->damageMin) + " - " + std::to_string(this->damageMax) + "\n" +
		"Defense: " + std::to_string(this->defense) + "\n" +
		"Accuracy: " + std::to_string(this->accuracy) + "\n" +
		"Drop chance: " + std::to_string(this->dropChance) + "\n";
}
