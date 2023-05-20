#include "SingleTrackVehicle.h"
#include <math.h>

int SingleTrackVehicle::getLength() const
{
    return length;
}

int SingleTrackVehicle::getWidth() const
{
    return width;
}

int SingleTrackVehicle::getNrOfWheels() const
{
    return nrOfWheels;
}

Engine Motorbike::getEngine() const
{
    return engine;
}

std::string Motorbike::getRegistrationNo() const
{
    return registrationNo;
}

double Motorbike::turningRadius() const
{
    return (this->getLength() / sin(maxWheelAngle));
}
