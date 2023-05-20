#pragma once
#include <string>
#include "..//ConsoleGUI/Object.h"
constexpr double PI = 3.14159;

class Vehicle: public Object
{
protected:
	int length, weight;
	std::string name;
	bool needsPlaceForTurn;
public:
	Vehicle(int x, int y, int weight, int width, int length, int height, char symb, Dir dir, std::string name="", bool needsPlace = false)
		: Object(x, y, width, height, symb, dir), weight(weight), length(length), name(name),needsPlaceForTurn(needsPlace) {}
	double getWeight() const;
	virtual int getLength() const = 0;
	std::string getName() const;

	void setWeight(int weight);
	void setWidth(int width);
	void setLength(int length);
	void setName(std::string name);
	void turn();
};