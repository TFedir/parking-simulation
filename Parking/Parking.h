#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <set>
#include "Place.h"
#include "Vehicle.h"
#include "../ConsoleGUI/Drawer.h"
class Parking
{
private:
	int sizeX;
	int sizeY;
	std::shared_ptr<Drawer> drawer;
public:
	explicit Parking(int sizeX, int sizeY, std::shared_ptr<Drawer> drawer): sizeX(sizeX), sizeY(sizeY), drawer(drawer) {};
	explicit Parking();
	int getSizeX();
	int getSizeY();
	void drawParking();
	void addObject(std::shared_ptr<Object> object);
	std::set<std::pair<int, int>> findOccupied();
private:
	std::vector<std::pair<int, int>> findPoints(double x0, double y0, double x1, double y1);
	std::vector<std::pair<int, int>> lineLow(double x0, double y0, double x1, double y1);
	std::vector<std::pair<int, int>> lineHigh(double x0, double y0, double x1, double y1);
};

