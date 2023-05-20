#pragma once
#include "Object.h"
class Circle : public Object
{
private:
	int radius;
public:
	Circle(int x, int y, int width, int height, char symb);
	int getRadius();
};

