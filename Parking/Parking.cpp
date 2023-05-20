#define _USE_MATH_DEFINES
#include <cmath>
#include "Parking.h"
#include "../ConsoleGUI/Drawer.h"
#include <ostream>
#include <memory>
#include <algorithm>
#include <tuple>
#include <functional>
#include <set>

Parking::Parking()
{
	sizeX = 100;
	sizeY = 100;
	this->drawer = std::make_shared<Drawer>(sizeX, sizeY, std::cout);
}

int Parking::getSizeX()
{
	return sizeX;
}

int Parking::getSizeY()
{
	return sizeY;
}

void Parking::drawParking()
{
	std::shared_ptr<Object> nwall = std::make_shared<Object>(0, 0, sizeY, 1, '-');
	std::shared_ptr<Object> swall = std::make_shared<Object>(0, sizeY - 1, sizeY, 1, '-');
	std::shared_ptr<Object> wwall = std::make_shared<Object>(0, 5, 1, sizeY - 6, '|');
	std::shared_ptr<Object> ewall = std::make_shared<Object>(sizeX - 1, 1, 1, sizeY - 2, '|');
	addObject(nwall);
	addObject(swall);
	addObject(wwall);
	addObject(ewall);
	drawer->redrawObjects();
	drawer->outputScreen();
}

void Parking::addObject(std::shared_ptr<Object> object)
{
	drawer->getScreen()->addObject(object);
}

std::set<std::pair<int, int>> Parking::findOccupied()
{
	std::vector<std::pair<int, int>> occupied;
	std::vector<int> sides = { 0, 1, 1, 3, 3, 2, 2, 0 };
	for (auto obj : drawer->getScreen()->getObjects())
	{
		if (obj!=nullptr)
		{
			if (obj->getSymb() != '-' && obj->getSymb() != '|') {
				auto edges = obj->getEdges();
				std::vector<std::pair<int, int>> result;
				//int mod = (int(obj->getAngle()*180))%45;
				for (int i = 0; i < 8; i+=2)
				{
					auto firstEdge = edges[sides[i]];
					auto secondEdge = edges[sides[i+1]];

					result = findPoints(firstEdge.first, firstEdge.second, secondEdge.first, secondEdge.second);
					occupied.insert(occupied.end(), result.begin(), result.end());
				}
				// finding confines of a rectangle - max x and max y
				int x = int(floor(edges[0].first));
				int y = int(floor(edges[0].second));
				for (auto edge : edges) {
					if (edge.first > x) x = int(floor(edge.first));
					if (edge.second > y) y = int(floor(edge.second));
				}
				// finding squares located inside the borders
				for (int i = 0; i <= x; ++i)
					for (int j = 0; j <= y; ++j)
					{
						bool inside = true;
						for (int idx = 0; idx < 8; idx += 2)
						{
							auto firstEdge = edges[sides[idx]];
							auto secondEdge = edges[sides[idx + 1]];
							float d = ((secondEdge.first - firstEdge.first) * (j - firstEdge.second)) - ((i - firstEdge.first) * (secondEdge.second - firstEdge.second));
							if (d < 0 /* || (d == 0 && mod == 0)*/) inside = false;
						}
						if (inside) occupied.push_back(std::pair<int, int>(i, j));
					}
			}
		}
	}
	std::set<std::pair<int, int>> resultSet;
	for (auto pair : occupied) resultSet.insert(pair);
	return resultSet;
}

std::vector<std::pair<int, int>> Parking::findPoints(double x0, double y0, double x1, double y1)
{
	std::vector<std::pair<int, int>> points;
	if (abs(y1 - y0) <= abs(x1 - x0))
	{
		if (x0 > x1) points = lineLow(x1, y1, x0, y0);
		else points = lineLow(x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1) points = lineHigh(x1, y1, x0, y0);
		else points = lineHigh(x0, y0, x1, y1);
	}
	return points;
}

std::vector<std::pair<int, int>> Parking::lineLow(double x0, double y0, double x1, double y1)
{
	std::vector<std::pair<int, int>> points = {};
	double dx = x1 - x0;
	double dy = y1 - y0;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	double d = (2 * dy) - dx;
	int y = int(floor(y0));
	std::pair<int, int> coords;
	for (int x = int(floor(x0)); x <= int(floor(x1)); ++x) {
			coords.first = x;
			coords.second = y;
			points.push_back(coords);
			if (d > 0) {
				y = y + yi;
				d = d + (2 * (dy - dx));
			}
			else d = d + 2 * dy;
		}
	return points;
}

std::vector<std::pair<int, int>> Parking::lineHigh(double x0, double y0, double x1, double y1)
{
	std::vector<std::pair<int, int>> points = {};
	double dx = x1 - x0;
	double dy = y1 - y0;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	double d = (2 * dx) - dy;
	double x = int(floor(x0));
	std::pair<int, int> coords;
	for (int y = int(floor(y0)); y <= int(floor(y1)); ++y) {
		coords.first = x;
		coords.second = y;
		points.push_back(coords);
		if (d > 0) {
			x = x + xi;
			d = d + (2 * (dx - dy));
		}
		else d = d + 2 * dx;
	}
	return points;
}
