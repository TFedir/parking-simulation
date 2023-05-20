#include "Vehicle.h"
#include <iostream>

double Vehicle::getWeight() const
{
    return weight;
}

int Vehicle::getLength() const
{
    return length;
}

std::string Vehicle::getName() const
{
    return name;
}

void Vehicle::setWeight(int weight)
{
    this->weight = weight;
}

void Vehicle::setWidth(int width)
{
    this->width = width;
}

void Vehicle::setLength(int length)
{
    this->length = length;
}

void Vehicle::setName(std::string name)
{
    this->name = name;
}

void Vehicle::turn()
{
    int bufWid = getWidth();
    setWidth(getHeight());
    setHeight(bufWid);
}
