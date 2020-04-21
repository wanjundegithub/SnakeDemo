#pragma once
#include<stdio.h>
#include<Windows.h>

class SetWindow
{
public :
	SetWindow()
	{

	}
	void  SetWindowsTitleSize(int x, int y);
	void  SetCursorPosition(int x, int y);
	void  SetWindowsTextColor(int color);
	void  SetWindowsTextBackgroundColor();
};

