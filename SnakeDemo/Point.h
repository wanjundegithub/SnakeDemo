#pragma once
class Point
{
public :
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}
	Point()
	{

	}
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
private:
	int X;
	int Y;
};

