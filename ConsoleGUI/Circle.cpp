#include "Circle.h"
#include "Object.h"
#include <algorithm>
Circle::Circle(int x, int y, int width, int height, char symb) : Object(x, y, width, height, symb)
{
	width = std::max(width, height);
	height = std::max(width, height);
	radius = width / 2;
}

int Circle::getRadius()
{
	return radius;
}