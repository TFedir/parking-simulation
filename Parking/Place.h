#pragma once
class Place
{
private:
	int x;
	int y;
	bool isFree;
public:
	explicit Place(int x, int y, bool isFree);
	int getX() const noexcept;
	void setX(int newX) noexcept;
	int getY() const noexcept;
	void setY(int newY) noexcept;
	bool IsFree() const noexcept;
	void changeStatus() noexcept;
};

