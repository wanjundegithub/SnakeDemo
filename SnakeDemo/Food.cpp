#include "Food.h"

Point Food::GenerateFood(deque<Point> SnakePoints)
{
	int MaxX = Map::GetMaxX() - Map::GetMinX();
	int MaxY = Map::GetMaxY() - Map::GetMinY();
	//设置随机数种子
	srand((int)time(0));
	bool flag = false;
	int tempx = 0,tempy = 0;
	int count = 0;
	//容量有限，不允许生成重复点
	while (count<MaxX*MaxY)
	{
		//判断生成的食物点是否在蛇内
		tempx = rand() % MaxX,tempy = rand() % MaxY;
		tempx += Map::GetMinX(), tempy += Map::GetMinY();
		if (tempx <= Map::GetMinX())
			tempx += 1;
		else if (tempx >= Map::GetMaxX())
			tempx -= 1;
		if (tempy <= Map::GetMinY())
			tempy += 1;
		else if (tempy >= Map::GetMaxY())
			tempy -= 1;
		for (auto item :SnakePoints)
		{
			if (item.GetX() == tempx && item.GetY() == tempy)
				flag = true;
			else
				continue;
		}
		if (flag == false)
			break;
		count++;
	}
	if (tempx != 0 && tempy != 0)
		DrawIcon::DrawFood(Point(tempx, tempy));
	else
		throw exception("食物点生成错误");
}

