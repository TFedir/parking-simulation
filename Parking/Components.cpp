#include "Components.h"

int Trailer::getWeight() const
{
	return weight;
}

int Trailer::getWidth() const
{
	return width;
}

int Trailer::getLength() const
{
	return length;
}

int Trailer::getHeight() const
{
	return height;
}

void Trailer::setWeight(int weight)
{
	this->weight = weight;
}

void Trailer::setWidth(int width)
{
	this->width = width;
}

void Trailer::setLength(int length)
{
	this->length = length;
}

void Trailer::setHeight(int height)
{
	this->height = height;
}

double Engine::getHorsepower() const
{
	return horsepower;
}

double Engine::getCapacity() const
{
	return capacity;
}

double Engine::getLitersPer100Kilometers() const
{
	return litersPer100Kilometers;
}

void Engine::setHorsepower(double horsepower)
{
	this->horsepower = horsepower;
}

void Engine::setCapacity(double capacity)
{
	this->capacity = capacity;
}

void Engine::setLitersPer100Kilometers(double litersPer100Kilometers)
{
	this->litersPer100Kilometers = litersPer100Kilometers;
}
