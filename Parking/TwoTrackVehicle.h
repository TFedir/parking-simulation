#pragma once
#include "./Vehicle.h"
#include "Components.h"

class TwoTrackVehicle : public Vehicle
{
protected:
	std::string registrationNo;
	int nrOfWheels;
	Engine engine;
	double maxWheelAngle;
public:
	TwoTrackVehicle(int x, int y, int weight, int width, int length, int height, char symb, Dir dir, std::string name, std::string registrationNo, double maxWheelAngle, Engine engine=Engine())
		: Vehicle(x, y, weight, width, length, height, symb, dir, name, true),
		registrationNo(registrationNo), nrOfWheels(4), engine(engine), maxWheelAngle(maxWheelAngle) {};
	std::string getRegistrationNo() const;
	int getNrOfWheels() const;
	Engine getEngine() const;
	double getMaxWheelAngle() const;
	int getWidth() const;
	int getLength() const;

	void setRegistrationNo(std::string registrationNr);
	void setEngine(Engine engine);
	void setMaxWheelAngle(double maxWheelAngle);

	double turningRadius() const;
};


class Truck : public TwoTrackVehicle
{
private:
	double cargo;
public:
	Truck(int x, int y, int weight, int width, int length, int height, char symb, Dir dir, std::string name,
		std::string registrationNo, double maxWheelAngle, Engine engine = Engine(), double cargo = 0.0) :
		TwoTrackVehicle(x, y, weight, width, length, height,symb, dir, name, registrationNo, maxWheelAngle, engine), cargo(cargo) {};
	double getCargo() const;
	double getWeight() const;
};


class Car : public TwoTrackVehicle
{
private:
	Trailer trailer;
public:
	Car(int x, int y, int weight, int width, int length, int height, char symb, Dir dir, std::string name,
		std::string registrationNo, double maxWheelAngle, Engine engine = Engine(), Trailer trailer = Trailer()) : TwoTrackVehicle
		(x, y, weight, width, length, height, symb, dir, name, registrationNo, maxWheelAngle, engine), trailer(trailer) {};
	Trailer getTrailer() const;
	int getWeight() const;
	int getWidth() const;
	int getLength() const;
	int getHeight() const;
	double turningRadius() const;

	void setTrailer(Trailer trailer);
};