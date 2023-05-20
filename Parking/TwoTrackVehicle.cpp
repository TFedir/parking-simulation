#include "TwoTrackVehicle.h"
#include <math.h>

std::string TwoTrackVehicle::getRegistrationNo() const
{
	return registrationNo;
}

int TwoTrackVehicle::getNrOfWheels() const
{
	return nrOfWheels;
}

Engine TwoTrackVehicle::getEngine() const
{
	return engine;
}

double TwoTrackVehicle::getMaxWheelAngle() const
{
	return maxWheelAngle;
}

int TwoTrackVehicle::getWidth() const
{
	return width;
}

int TwoTrackVehicle::getLength() const
{
	return length;
}

void TwoTrackVehicle::setRegistrationNo(std::string registrationNo)
{
	this->registrationNo = registrationNo;
}

void TwoTrackVehicle::setEngine(Engine engine)
{
	this->engine = engine;
}

void TwoTrackVehicle::setMaxWheelAngle(double maxWheelAngle)
{
	this->maxWheelAngle = maxWheelAngle;
}

double TwoTrackVehicle::turningRadius() const
{
	return length/sin(maxWheelAngle);
}

double Truck::getCargo() const
{
	return cargo;
}

double Truck::getWeight() const
{
	return weight + cargo;
}

Trailer Car::getTrailer() const
{
	return trailer;
}

int Car::getWeight() const
{
	return weight + trailer.getWeight();
}

int Car::getWidth() const
{
	return width;
}

int Car::getLength() const
{
	return length;
}

int Car::getHeight() const
{
	return height;
}

double Car::turningRadius() const
{
	return (this->getLength() / sin(maxWheelAngle));
}

void Car::setTrailer(Trailer trailer)
{
	this->trailer = trailer;
}
