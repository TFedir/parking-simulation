#pragma once
#include "Vehicle.h"
#include "Components.h"

class SingleTrackVehicle : public Vehicle
{
private:
	int nrOfWheels;
public:
	SingleTrackVehicle(int x, int y, int weight, int width, int length, int height, char symb, Dir dir, std::string name="", bool needsPlace = false) :
		Vehicle(x, y, weight, width, length, height, symb, dir, name, needsPlace), nrOfWheels(2){};
	int getLength() const;
	int getWidth() const;
	int getNrOfWheels() const;
};

class Motorbike : public SingleTrackVehicle
{
private:
	std::string registrationNo;
	Engine engine;
	double maxWheelAngle;
public:
	Motorbike(int x, int y, int weight, int width, int length, int height, char symb, Dir dir, std::string name,
	std::string registrationNo, Engine engine, double maxWheelAngle) : 
		SingleTrackVehicle(x, y, weight, width, length, height, symb, dir, name, true),
		registrationNo(registrationNo), engine(engine), maxWheelAngle(maxWheelAngle) {}

	Engine getEngine() const;
	std::string getRegistrationNo() const;

	double turningRadius() const;
};

class Bicycle : public SingleTrackVehicle
{};

class Scooter : public SingleTrackVehicle
{};
