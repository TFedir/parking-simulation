#pragma once
#include <vector>
#include <utility>
#include <ostream>
#include "Object.h"
class Screen
{
private:
	static int idx;
	int width;
	int height;
	std::vector<std::shared_ptr<Object>> objects;
	char matrix[100][100];
public:
	explicit Screen(int width, int height);
	explicit Screen();
	int getHeight();
	int getWidth();
	std::vector<std::shared_ptr<Object>> getObjects();
	void setObjects(std::vector<std::shared_ptr<Object>> newObjects);
	void changePoint(int x, int y, char symb);
	char getPoint(int x, int y);
	void addObject(std::shared_ptr<Object> newObject);
	void deleteObject(int x, int y);
	void clearScreen();
};


