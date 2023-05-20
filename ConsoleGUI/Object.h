#pragma once
#include <vector>
enum class Dir {
	north, south, west, east
};

class Object
{
protected:
	double x, y;
	int width, height;
	Dir dir;
	char symb;
	double angle;
public:
	explicit Object(double x, double y, int width, int height, char symb = '*', Dir dir = Dir::west, double angle = 0.0);
	explicit Object() : x(0.0), y(0.0), width(1), height(1), symb('d'), dir(Dir::west), angle(0.0) {};
	int getX();
	void setX(int newX);
	int getY();
	void setY(int newY);
	int getWidth();
	void setWidth(int newWidth);
	int getHeight();
	void setHeight(int newHeight);
	Dir getDir();
	void setDir(Dir newDir);
	char getSymb();
	void setSymb(char newSymb);
	double getAngle();
	void setAngle(double angle);
	std::vector<std::pair<double, double>> getEdges();
};

