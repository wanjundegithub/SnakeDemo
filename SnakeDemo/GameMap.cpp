#include "GameMap.h"

std::deque<Point> GameMap::CreateMapWall()
{
	if (abs(MaxX-MinX) < 10 || abs(MaxY-MinY) < 10)
		throw std::exception("ǽ̫С");
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
	return map;
}

int GameMap::GetMinX()
{
	return MinX;
}

int GameMap::GetMinY()
{
	return MinY;
}

int GameMap::GetMaxX()
{
	return MaxX;

}

int GameMap::GetMaxY()
{
	return MaxY;
}

//ײǽ��־
void GameMap::SetHitWallFlag(bool flag)
{
	HitWallFlag = flag;
}
