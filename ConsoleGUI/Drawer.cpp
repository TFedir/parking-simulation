#include "Drawer.h"
#include "Screen.h"
#include <iostream>
#include <vector>

void Drawer::drawRectangle(int x, int y, int width, int height, char symb)
{
	for (int i = y; i < y + height; i++)
	{
		for (int j = x; j < x + width; j++)
		{
			screen->changePoint(j, i, symb);
		}
	}
}

void Drawer::drawObject(std::shared_ptr<Object> object)
{
	drawRectangle(object->getX(), object->getY(), object->getWidth(), object->getHeight(), object->getSymb());
}

void Drawer::drawVerticalLine(int x, int y, int length, char symb)
{
	drawRectangle(x, y, 1, length, symb);
}

void Drawer::drawHorizontalLine(int x, int y, int length, char symb)
{
	drawRectangle(x, y, length, 1, symb);
}

void Drawer::drawPoint(int x, int y, char symb)
{
	drawRectangle(x, y, 1, 1, symb);
}

void Drawer::eraseRectangle(int x, int y, int width, int height)
{
	for (int i = y; i < y + height; i++)
	{
		for (int j = x; j < x + width; j++)
		{
			screen->changePoint(j, i, ' ');
		}
	}
}

void Drawer::eraseObject(int x, int y)
{
	//stays in list, but not on screen
	std::vector<std::shared_ptr<Object>> tempv = screen->getObjects();
	for (auto i = tempv.begin(); i != tempv.end(); i++)
	{
		std::shared_ptr<Object> temp = *i;
		if (temp->getX() == x && temp->getY() == y)
		{
			eraseRectangle(x, y, temp->getWidth(), temp->getHeight());
		}
	}
}

void Drawer::erasePoint(int x, int y)
{
	screen->changePoint(x, y, ' ');
}

void Drawer::eraseVerticalLine(int x, int y, int length)
{
	eraseRectangle(x, y, 1, length);
}

void Drawer::eraseHorizontalLine(int x, int y, int length)
{
	eraseRectangle(x, y, length, 1);
}

void Drawer::deleteObject(int x, int y)
{
	std::vector<std::shared_ptr<Object>> tempv = screen->getObjects();
	for (auto i = tempv.begin(); i != tempv.end(); i++)
	{
		std::shared_ptr<Object> temp = *i;
		if (temp->getX() == x && temp->getY() == y)
		{
			eraseRectangle(x, y, temp->getWidth(), temp->getHeight());
			screen->deleteObject(x, y);
		}
	}
}

void Drawer::setObjects(std::vector<std::shared_ptr<Object>> newObjects)
{
	screen->setObjects(newObjects);
}

void Drawer::redrawObjects()
{
	screen->clearScreen();
	std::vector<std::shared_ptr<Object>> tempv = screen->getObjects();
	for (auto i = tempv.begin(); i != tempv.end(); i++)
	{
		if (*i != nullptr)
		{
			std::shared_ptr<Object> temp = *i;
			drawObject(temp);
		}
	}
}

std::shared_ptr<Screen> Drawer::getScreen()
{
	return screen;
}

void Drawer::outputScreen()
{
	for (int i = 0; i < screen->getHeight(); i++)
	{
		for (int j = 0; j < screen->getWidth(); j++)
		{
			this->stream << screen->getPoint(j, i);
		}
		this->stream << "\n";
	}
}

