#pragma once

#include<iostream>
#include<iomanip>
#include<string>

class Item
{
private:
	std::string name;
	int buyValue;
	int sellValue;

public:
	Item();
	virtual ~Item();

	inline std::string debugPrint() const { return this->name; }
};

