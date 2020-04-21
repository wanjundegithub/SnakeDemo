#pragma once
class Point
{
public :
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}
	//拷贝构造函数，用于传递或返回point对象
	Point(const Point& obj)
	{
		X = obj.X;
		Y = obj.Y;
	}
	Point()
	{

	}
	int GetX();
	int GetY();
private:
	int X;
	int Y;
};

