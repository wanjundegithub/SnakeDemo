#pragma once
class Point
{
public :
	Point(int x, int y)
	{
		X = x;
		Y = y;
	}
	//�������캯�������ڴ��ݻ򷵻�point����
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

