#include "DrawGameIcon.h"

void DrawGameIcon::DrawEmpty(Point point)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(point.GetX(), point.GetY());
	std::cout << " ";
}

void DrawGameIcon::DrawSnake(std::deque<Point> snakepoints)
{
	SetWindow setWindow;
	for (auto point : snakepoints)
	{
		setWindow.SetCursorPosition(point.GetX(), point.GetY());
		std::cout << "*";
	}
}

void DrawGameIcon::DrawMap(std::deque<Point> map)
{
	SetWindow setWindow;
	for (auto point : map)
	{
		setWindow.SetCursorPosition(point.GetX(), point.GetY());
		std::cout << "&";
	}
}

void DrawGameIcon::DrawFailure(GameMap map)
{
	SetWindow setWindow;
	int centerX = (map.GetMinX() + map.GetMaxX()) / 2;
	int centerY = (map.GetMinY() + map.GetMaxY()) / 2;
	setWindow.SetCursorPosition(centerX -4, centerY );
	std::cout << "ʧ�ܣ��Ƿ��˳�?";
}

//����ʳ��
void DrawGameIcon::DrawFood(Point point)
{
	SetWindow setWindow;
	//���õ�ǰʳ��λ��
	setWindow.SetCursorPosition(point.GetX(), point.GetY());
	//setWindow.SetWindowsTextColor(45);
	std::cout << "+";
}

void DrawGameIcon::DrawWelcome()
{
	SetWindow setWindow;
	setWindow.SetWindowsTitleSize(30, 30);
	setWindow.SetCursorPosition(7, 15);
	std::cout << "��ӭ���룬���Enter������Ϸ����" << std::endl;
}

//���˳���Ϸ
void  DrawGameIcon::DrawQuitGame(Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(),p.GetY());
	std::cout << "�ǣ�ֱ���˳�";
}

//��������Ϸ
void  DrawGameIcon::DrawContinueGame(Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(), p.GetY());
	std::cout << "�����¿�ʼ";
}

void DrawGameIcon::DrawScore(int score, Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(), p.GetY());
	std::cout << " �� �� : " << score << std::endl;
}

void DrawGameIcon::DrawGameClearance(Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(), p.GetY());
	std::cout << " �� ϲ,�� ͨ �� ";
}
