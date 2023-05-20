#include "Place.h"

Place::Place(int x, int y, bool isFree)
{
	this->x = x;
	this->y = y;
	this->isFree = isFree;
}

int Place::getX() const noexcept
{
	return x;
}

void Place::setX(int newX) noexcept
{
	x = newX;
}

int Place::getY() const noexcept
{
	return y;
}

void Place::setY(int newY) noexcept
{
	y = newY;
}

bool Place::IsFree() const noexcept
{
	return isFree;
}

void Place::changeStatus() noexcept
{
	isFree = !isFree;
}

