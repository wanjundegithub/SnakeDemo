#include "Food.h"

Point Food::GenerateFood(Snake snake,int max,int min)
{
	//�������������
	srand((int)time(0));
	bool flag = false;
	int tempx = 0,tempy = 0;
	int count = 0;
	//��������
	while (count<(max-min)*(max-min))
	{
		//�ж����ɵ�ʳ����Ƿ�������
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
		throw exception("ʳ������ɴ���");
}

//����ʳ��
void Food::DrawFood(Point point)
{
	//���õ�ǰʳ��λ��
	SetWindow::SetCursorPosition(point.GetX(), point.GetY());
	SetWindow::SetWindowsTextColor(45);
	cout << "+";
}
