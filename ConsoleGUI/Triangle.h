#pragma once
#include "Object.h"
class Triangle : public Object
{
private:
	double baseAngle;
	double topAngle;
public:
	explicit Triangle(int x, int y, int width, int height, char symb);
	double getBaseAngle();
	double getTopAngle();
};

