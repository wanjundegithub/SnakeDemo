#include "Map.h"

void Map::DrawWall()
{
	if (abs(MaxX-MinX) < 50 || abs(MaxY-MinY) < 50)
		throw exception("ǽ̫С");
	std::deque<Point> map;
	for (int x = MinX, y = MinY; x <= MaxX-1; x++)
	{
		map.emplace_back(Point(x, y));
	}
	for (int x = MinX, y = MinY+1; y <= MaxY; y++)
	{
		map.emplace_back(Point(x, y));
	}
	for (int x = MinX+1, y = MaxY; x <= MaxX; x++)
	{
		map.emplace_back(Point(x, y));
	}
	for (int x = MaxX, y = MinY; y <= MaxY - 1; y++)
	{
		map.emplace_back(Point(x, y));
	}
	//
	DrawIcon::DrawMap(map);
}

int Map::GetMinX()
{
	return MinX;
}

int Map::GetMinY()
{
	return MinY;
}

int Map::GetMaxX()
{
	return MaxX;

}

int Map::GetMaxY()
{
	return MaxY;
}

//ײǽ��־
void Map::SetHitWallFlag(bool flag)
{
	HitWallFlag = flag;
}
