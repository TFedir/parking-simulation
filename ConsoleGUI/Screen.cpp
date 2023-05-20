#include "Screen.h"
#include "Object.h"
#include <iostream>
int Screen::idx = 0;

Screen::Screen(int width, int height)
{
	this->idx = 0;
	this->width = width;
	this->height = height;
	std::vector<std::shared_ptr<Object>> objects(width*height, nullptr);
	this->objects = objects;
	clearScreen();
}

void Screen::clearScreen()
{
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (j != width)
			{
				matrix[i][j] = ' ';
			}
			else
			{
				matrix[i][j] = '\n';
			}
		}
	}
}

Screen::Screen()
{
	width = 99;
	height = 100;
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (j != width)
			{
				matrix[i][j] = ' ';
			}
			else
			{
				matrix[i][j] = '\n';
			}
		}
	}
}

std::vector<std::shared_ptr<Object>> Screen::getObjects()
{
	return objects;
}

void Screen::changePoint(int x, int y, char symb)
{
	matrix[y][x] = symb;
}

int Screen::getHeight()
{
	return height;
}

int Screen::getWidth()
{
	return width;
}

void Screen::addObject(std::shared_ptr<Object> newObject)
{
	//coordinates of an object are coordinates of its left top corner
	objects[idx++] = newObject;
}


void Screen::deleteObject(int x, int y)
{
	for (auto i : objects)
	{
		if (i != nullptr) {
			if (i->getX() == x && i->getY() == y)
			{
				remove(objects.begin(), objects.end(), i);
			}
		}
	}
}

void Screen::setObjects(std::vector<std::shared_ptr<Object>> newObjects)
{
	objects.clear();
	std::vector<std::shared_ptr<Object>> vtemp = newObjects;
	for (auto i = vtemp.begin(); i != vtemp.end(); i++)
	{
		std::shared_ptr<Object> temp = *i;
		objects.push_back(temp);
	}
}

char Screen::getPoint(int x, int y)
{
	return matrix[y][x];
}
