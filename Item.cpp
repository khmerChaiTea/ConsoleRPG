#include "Item.h"



Item::Item(int level)
{
	this->name = "NONE";
	this->level = rand() % level;
	this->rarity = rand() % 5;
	this->buyValue = level* this->rarity * 10;
	this->sellValue = this->buyValue / 2;
}

Item::Item(std::string name, int level, int buyValue, int sellValue, int rarity)
{
	this->name = name;
	this->level = level;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->rarity = rarity;
}

Item::~Item()
{
}
