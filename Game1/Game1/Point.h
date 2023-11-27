#pragma once

struct Point
{
public:
	int x;
	int y;
	
	Point()
		: x(1)
		, y(13)
	{

	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};