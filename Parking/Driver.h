#pragma once
#include "Vehicle.h"
#include "..//ConsoleGUI/Object.h"
#include "..//ConsoleGUI/Drawer.h"
class Driver
{
protected:
	std::shared_ptr<Vehicle> mycar;
	char color;
	std::shared_ptr<Drawer> drawer;
public:
	Driver(std::shared_ptr<Vehicle> car, char color, std::shared_ptr<Drawer> drawer) : mycar(car), color(color), drawer(drawer) {};
	std::shared_ptr<Object> getObject();
	char getColor();
	bool moveF();
	bool moveB();
	bool turnL();
	bool turnR();
	bool checkU(int distance);
	bool checkD(int distance);
	bool checkL(int distance);
	bool checkR(int distance);
};

class SupremeDriver: public Driver
{
public:
	SupremeDriver(std::shared_ptr<Vehicle> car, char color, std::shared_ptr<Drawer> drawer) : Driver(car, color, drawer) {};
	bool changeDir(Dir changeTo);
	bool parkIn(int x, int y);
};

