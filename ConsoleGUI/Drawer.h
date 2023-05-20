#pragma once
#include "Screen.h"
#include <iostream>
#include <memory>
class Drawer
{
private:
	std::shared_ptr<Screen> screen;
	std::ostream& stream;
public:
	Drawer(int width, int height, std::ostream& stream): stream(stream){ std::shared_ptr<Screen> screenPtr = std::make_shared<Screen>(width, height);
	this->screen = screenPtr;};
	void drawRectangle(int x, int y, int width, int height, char symb);
	void drawVerticalLine(int x, int y, int length, char symb);
	void drawHorizontalLine(int x, int y, int length, char symb);
	void drawPoint(int x, int y, char symb);
	void eraseObject(int x, int y);
	void deleteObject(int x, int y);
	void eraseRectangle(int x, int y, int width, int height);
	void erasePoint(int x, int y);
	void eraseVerticalLine(int x, int y, int length);
	void eraseHorizontalLine(int x, int y, int length);
	void setObjects(std::vector<std::shared_ptr<Object> > newObjects);
	void drawObject(std::shared_ptr<Object> object);
	void redrawObjects();
	std::shared_ptr<Screen> getScreen();
	void outputScreen();
};

