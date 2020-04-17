#pragma once
#include<deque>
#include"Point.h"
#include"SetWindow.h"
#include"DrawIcon.h"
#include<iostream>

using namespace std;

class Map
{
public :
	Map(int minx, int miny, int maxx, int maxy,bool flag=false)
	{
		MinX = minx, MinY = miny, MaxX = maxx, MaxY = maxy,HitWallFlag=flag;
	}
	static void DrawWall();
	static int GetMinX();
	static int GetMinY();
	static int GetMaxX();
	static int GetMaxY();
	static void SetHitWallFlag(bool flag);
private:
	static int MinX;
	static int MinY;
	static int MaxX;
	static int MaxY;
	static bool HitWallFlag ;
};

