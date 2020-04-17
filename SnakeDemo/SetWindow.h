#pragma once
#include<stdio.h>
#include<Windows.h>

static class SetWindow
{
public :
	static void  SetWindowsTitleSize(int x, int y);
	static void  SetCursorPosition(int x, int y);
	static void  SetWindowsTextColor(int color);
	static void  SetWindowsTextBackgroundColor();
};

