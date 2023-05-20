#pragma once

class Trailer
{
protected:
	int weight, width, length, height;
public:
	Trailer(int weight, int width, int length, int height)
		: weight(weight), width(width), length(length), height(height) {};
	Trailer() : weight(0), width(0), length(0), height(0) {};

	int getWeight() const;
	int getWidth() const;
	int getLength() const;
	int getHeight() const;

	void setWeight(int weight);
	void setWidth(int width);
	void setLength(int length);
	void setHeight(int height);
};

class Engine
{
private:
	double horsepower, capacity, litersPer100Kilometers;
public:
	Engine(double horsepower, double capacity, double litersPer100Kilometers) :
		horsepower(horsepower), capacity(capacity), litersPer100Kilometers(litersPer100Kilometers) {};
	Engine() : horsepower(0.0), capacity(0.0), litersPer100Kilometers(0.0) {};

	double getHorsepower() const;
	double getCapacity() const;
	double getLitersPer100Kilometers() const;

	void setHorsepower(double horsepower);
	void setCapacity(double capacity);
	void setLitersPer100Kilometers(double litersPer100Kilometers);
};
