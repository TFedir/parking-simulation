#define _USE_MATH_DEFINES
#include <cmath>
#include "Object.h"
#include <iostream>
#include <vector>

Object::Object(double x, double y, int width, int height, char symb, Dir dir, double angle)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->dir = dir;
	this->symb = symb;
		if (angle < 0) while (abs(angle) > M_PI)
			angle += M_PI;
		else while (abs(angle) > M_PI)
			angle -= M_PI;
		this->angle = angle;}

int Object::getX()
{
	return int(floor(x));
}

int Object::getY()
{
	return int(floor(y));
}

int Object::getWidth()
{
	return width;
}

int Object::getHeight()
{
	return height;
}

void Object::setX(int newX)
{
	x = newX;
}

void Object::setY(int newY)
{
	y = newY;
}

void Object::setHeight(int newHeight)
{
	height = newHeight;
}

Dir Object::getDir()
{
	return dir;
}

void Object::setDir(Dir newDir)
{
	this->dir = newDir;
}

void Object::setWidth(int newWidth)
{
	width = newWidth;
}

char Object::getSymb()
{
	return symb;
}

void Object::setSymb(char newSymb)
{
	symb = newSymb;
}

double Object::getAngle()
{
	return angle;
}

void Object::setAngle(double angle)
{
	this->angle = angle;
}

std::vector<std::pair<double, double>> Object::getEdges()
{
	double angle = this->angle;
	if (angle > 0) angle -= M_PI; // "turning" the car
	std::pair<double, double> leftTop, rightTop, leftBottom, rightBottom;
	double dx=0, dy=0;
	if (angle < -M_PI_2) {
		dx = cos(angle) * (double(width) / 2);
		dy = sin(angle) * (double(width) / 2);
	}
	else
	{
		dx =(sin(angle)) * (double(width) / 2);
		if (angle != -M_PI_2) dy = (cos(angle)) * (double(width) / 2);
	}
	double bottomX;
	//if (angle < -M_PI_2)
	double newangle = -M_PI - angle;
	double offset = 0;
	if (newangle!=-M_PI_2) offset = height * cos(newangle);;
	bottomX = x - offset;
	//else bottomX = x + height * floor(cos(M_PI - angle));
	double bottomY = y - height * (sin(newangle));

	leftTop.first = x + dx; leftTop.second = y - dy;
	rightTop.first = x - dx; rightTop.second = y + dy;
	leftBottom.first = bottomX + dx; leftBottom.second = bottomY - dy;
	rightBottom.first = bottomX - dx; rightBottom.second = bottomY + dy;
	if (angle <= -M_PI_2) {
		leftTop.second = y + dy;
		rightTop.second = y - dy;
		leftBottom.second = bottomY + dy;
		rightBottom.second = bottomY - dy;
	}
	return std::vector< std::pair<double, double>> { leftTop, rightTop, leftBottom, rightBottom };
}
