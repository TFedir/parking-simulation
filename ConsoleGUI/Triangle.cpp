#include "Triangle.h"
#include "Object.h"
#include <cmath>
Triangle::Triangle(int x, int y, int width, int height, char symb) : Object(x, y, width, height, symb)
{
	baseAngle = atan(double(height/(0.5*width)));
	topAngle = 180 - 2 * baseAngle;
}

double Triangle::getBaseAngle()
{
	return baseAngle;
}

double Triangle::getTopAngle()
{
	return topAngle;
}