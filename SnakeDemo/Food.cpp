#include "Food.h"

Point Food::GenerateFood(std::deque<Point> SnakePoints,GameMap map)
{
	int MaxX = map.GetMaxX() - map.GetMinX();
	int MaxY = map.GetMaxY() - map.GetMinY();
	//�������������
	srand((int)time(0));
	bool flag = false;
	int tempx = 0,tempy = 0;
	int count = 0;
	//�������ޣ������������ظ���
	while (count<MaxX*MaxY)
	{
		//�ж����ɵ�ʳ����Ƿ�������
		tempx = rand() % MaxX,tempy = rand() % MaxY;
		tempx += map.GetMinX(), tempy += map.GetMinY();
		if (tempx <= map.GetMinX())
			tempx += 2;
		else if (tempx >= map.GetMaxX())
			tempx -= 2;
		if (tempy <= map.GetMinY())
			tempy += 2;
		else if (tempy >= map.GetMaxY())
			tempy -= 2;
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
	if ((tempx==map.GetMinX())||(tempx==map.GetMaxX())||(tempy==map.GetMinY())||(tempy==map.GetMaxY()))
		throw std::exception("ʳ������ɴ���");
	Point foodPoint(tempx, tempy);
	return foodPoint;
}

