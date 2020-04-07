#include "Map.h"

//point墙起始点坐标，rows墙的行数，cols墙的列数
void Map::DrawWall(Point point,int rows,int cols)
{
	deque<Point> map;
	int initialX = point.GetX(), initialY = point.GetY();
	for (int x = initialX, y = initialY; x <= cols; x++)
	{
		map.emplace_back(Point(x, y));
	}
	for (int x = initialX, y = initialY+1; y <= rows - 1; y++)
	{
		map.emplace_back(Point(x, y));
	}
	for (int x = initialX, y = rows; x <= cols; x++)
	{
		map.emplace_back(Point(x, y));
	}
	for (int x = cols, y = initialY+1; y <= rows - 1; y++)
	{
		map.emplace_back(Point(x, y));
	}
	//
	SetWindow set;
	for (auto &point : map)
	{
		set.SetCursorPosition(point.GetX(), point.GetY());
		cout << "*";
	}
}
