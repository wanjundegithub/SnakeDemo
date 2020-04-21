#include "SetWindow.h"

void  SetWindow::SetWindowsTitleSize(int x, int y)
{
	system("title,̰����");
	//���ô��ڴ�С����
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", 2*x, y);
	system(cmd);
}

void SetWindow::SetCursorPosition(int x, int y)
{
	//���ù��λ��
	COORD pos;
	pos.X = 2*x;
	pos.Y = y;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outputHandle, pos);
}

void SetWindow::SetWindowsTextColor(int color)
{
	//�����ı���ɫ
	HANDLE colorHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colorHandle, color);
}

void SetWindow::SetWindowsTextBackgroundColor()
{
	//�����ı�����ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}
