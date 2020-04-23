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

Point DrawGameIcon::DrawQuitGame(GameMap map)
{
	SetWindow setWindow;
	int centerX = (map.GetMinX() + map.GetMaxX()) / 2;
	int centerY = (map.GetMinY() + map.GetMaxY()) / 2;
	setWindow.SetCursorPosition(centerX - 7, centerY + 3);
	std::cout << "�ǣ�ֱ���˳�";
	return Point(centerX - 7, centerY + 3);
}

Point DrawGameIcon::DrawContinueGame(GameMap map)
{
	SetWindow setWindow;
	int centerX = (map.GetMinX() + map.GetMaxX()) / 2;
	int centerY = (map.GetMinY() + map.GetMaxY()) / 2;
	setWindow.SetCursorPosition(centerX + 2, centerY + 3);
	std::cout << "�����¿�ʼ";
	return Point(centerX + 2, centerY + 3);
}
