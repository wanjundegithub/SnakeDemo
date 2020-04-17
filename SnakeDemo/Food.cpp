#include "Food.h"

Point Food::GenerateFood(Snake snake,int max,int min)
{
	//设置随机数种子
	srand((int)time(0));
	bool flag = false;
	int tempx = 0,tempy = 0;
	int count = 0;
	//容量有限
	while (count<(max-min)*(max-min))
	{
		//判断生成的食物点是否在蛇内
		tempx = rand() % max;
		tempy = rand() % max;
		if (tempx <= min)
			tempx += 1;
		if (tempy <= min)
			tempy += 1;
		for (auto item : snake.GetSnakePoints())
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
		DrawFood(Point(tempx, tempy));
	else
		throw exception("食物点生成错误");
}

//画出食物
void Food::DrawFood(Point point)
{
	//设置当前食物位置
	SetWindow::SetCursorPosition(point.GetX(), point.GetY());
	SetWindow::SetWindowsTextColor(45);
	cout << "+";
}
