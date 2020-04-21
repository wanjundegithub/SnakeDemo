#pragma once
#include"Point.h"
#include<deque>
#include<iostream>

class GameMap
{
public :
	GameMap(int minx, int miny, int maxx, int maxy,bool flag=false)
	{
		MinX = minx, MinY = miny, MaxX = maxx, MaxY = maxy,HitWallFlag=flag;
	}
	GameMap(const GameMap& obj)
	{
		MinX = obj.MinX,MinY=obj.MinY,MaxX=obj.MaxX,MaxY=obj.MaxY,HitWallFlag=obj.HitWallFlag;
	}
	GameMap()
	{

	}
	std::deque<Point> CreateMapWall();
	int GetMinX();
	int GetMinY();
	int GetMaxX();
	int GetMaxY();
	void SetHitWallFlag(bool flag);
private:
	int MinX;
	int MinY;
	int MaxX;
	int MaxY;
    bool HitWallFlag ;
};

