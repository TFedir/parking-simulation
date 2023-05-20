#include "Driver.h"
#include "Vehicle.h"
#include "..//ConsoleGUI/Object.h"
#include <windows.h>
#include <memory>

extern void ClearScreen();
void refreshConsole(std::shared_ptr<Drawer> drawer);

std::shared_ptr<Object> Driver::getObject()
{
	return std::static_pointer_cast<Object>(this->mycar);
}


char Driver::getColor()
{
	return color;
}

bool Driver::checkR(int distance = 0)
{
	int x = mycar->getX();
	if (drawer->getScreen()->getPoint(x + mycar->getWidth() + distance, mycar->getY()) != '\n')
	{
		for (int i = mycar->getY(); i < mycar->getY() + mycar->getLength(); i++)
		{
			if (drawer->getScreen()->getPoint(x + mycar->getWidth() + distance, i) != ' ')
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool SupremeDriver::changeDir(Dir changeTo)
{
	while(!(mycar->getDir() == changeTo)) if(!turnL()) break;
	while (!(mycar->getDir() == changeTo)) if (!turnR()) break;
	return mycar->getDir() == changeTo;
}

bool SupremeDriver::parkIn(int x, int y)
{
	changeDir(Dir::east);
	while (this->mycar->getX() < x) { if (!moveF()) break;refreshConsole(drawer); }
	if (this->mycar->getX() > x)
	{
		changeDir(Dir::west);
			while (this->mycar->getX() > x)
			{
				if (!moveB()) break;
				refreshConsole(drawer);
			}
	}
	if (!turnR()) return false;
	refreshConsole(drawer);
	while (this->mycar->getY() < y) { if(!moveF()) break;refreshConsole(drawer); }
	if (this->mycar->getY() > y)
	{
		changeDir(Dir::north);
		while(this->mycar->getY() > y) {if (!moveB()) break;refreshConsole(drawer);}
	}
	return true;
}

bool Driver::checkL(int distance = 0)
{
	int x = mycar->getX();
	if (x != distance)
	{
		for (int i = mycar->getY(); i < mycar->getY() + mycar->getLength(); i++)
		{
			if (drawer->getScreen()->getPoint(x - 1 - distance, i) != ' ')
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Driver::checkU(int distance = 0)
{
	int y = mycar->getY();
	if (y != distance)
	{
		for (int i = mycar->getX(); i < mycar->getX() + mycar->getWidth(); i++)
		{
			if (drawer->getScreen()->getPoint(i, y - 1 - distance) != ' ')
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Driver::checkD(int distance = 0)
{
	int y = mycar->getY();
	if (y + mycar->getLength() + distance != drawer->getScreen()->getHeight())
	{
		for (int i = mycar->getX(); i < mycar->getX() + mycar->getWidth(); i++)
		{
			if (drawer->getScreen()->getPoint(i, y + mycar->getLength() + distance) != ' ')
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Driver::moveF()
{
	int x = mycar->getX();
	int y = mycar->getY();
	bool succeeded = false;
	switch (mycar->getDir())
	{
	case Dir::west:
		if (checkL())
		{
			mycar->setX(x - 1);
			succeeded = true;
		}
		break;
	case Dir::east:
		if (checkR())
		{
			mycar->setX(x + 1);
			succeeded = true;
		}
		break;
	case Dir::north:
		if (checkU())
		{
			mycar->setY(y - 1);
			succeeded = true;
		}
		break;
	case Dir::south:
		if (checkD())
		{
			mycar->setY(y + 1);
			succeeded = true;
		}
		break;
	}
	return succeeded;
}

bool Driver::moveB()
{
	int x = mycar->getX();
	int y = mycar->getY();
	bool succeeded = false;
	switch (mycar->getDir())
	{
	case Dir::east:
		if (checkL())
		{
			mycar->setX(x - 1);
			succeeded = true;
		}
		break;
	case Dir::west:
		if (checkR())
		{
			mycar->setX(x + 1);
			succeeded = true;
		}
		break;
	case Dir::south:
		if (checkU())
		{
			mycar->setY(y - 1);
			succeeded = true;
		}
		break;
	case Dir::north:
		if (checkD())
		{
			mycar->setY(y + 1);
			succeeded = true;
		}
		break;
	}
	return succeeded;
}

bool Driver::turnL()
{
	int x = mycar->getX();
	int y = mycar->getY();
	bool succeeded = false;
	switch (mycar->getDir())
	{
	case Dir::east:
		if (checkD(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::north);
			mycar->turn();
			succeeded = true;
		}
		break;
	case Dir::west:
		if (checkD(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::south);
			mycar->turn();
			succeeded = true;
		}
		break;
	case Dir::north:
		if (checkR(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::west);
			mycar->turn();
			succeeded = true;
		}
		break;
	case Dir::south:
		if (checkR(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::east);
			mycar->turn();
			succeeded = true;
		}
		break;
	}
	return succeeded;
}

bool Driver::turnR()
{
	int x = mycar->getX();
	int y = mycar->getY();
	bool succeeded = false;
	switch (mycar->getDir())
	{
	case Dir::east:
		if (checkD(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::south);
			mycar->turn();
			succeeded = true;
		}
		break;
	case Dir::west:
		if (checkD(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::north);
			mycar->turn();
			succeeded = true;
		}
		break;
	case Dir::north:
		if (checkR(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::east);
			mycar->turn();
			succeeded = true;
		}
		break;
	case Dir::south:
		if (checkR(abs(mycar->getLength() - mycar->getWidth()) - 1) || mycar->getLength() == mycar->getWidth())
		{
			mycar->setDir(Dir::west);
			mycar->turn();
			succeeded = true;
		}
		break;
	}
	return succeeded;
}

