#include "Control.h"

//初始化游戏
void Control::InitGame()
{
	//游戏开始界面，欢迎进入游戏，点击Enter进入游戏界面
	DrawGameIcon DrawObj;
	bool ExitFlag = false;
	SetWindow setWindow;
	setWindow.SetWindowsTitleSize(30, 30);
	setWindow.SetCursorPosition(7,15);
	std::cout << "欢迎进入，点击Enter进入游戏界面" <<std::endl;
	while (true)
	{
		int ch = _getch();
		if (ch == EnterKey)
		{
			system("cls");
			std::deque<Point> map= GreedGameMap.CreateMapWall();
			DrawObj.DrawMap(map);
			ExitFlag= KeyWordControl();
		}
		if (ch == EscKey||ExitFlag==true)
			break;
	}
}


//键盘响应事件
bool Control::KeyWordControl()
{
	//退出标志
	bool ExitFlag = false;
	//失败标志
	bool IsFailureFlag = false;
	Food food;
	DrawGameIcon DrawObj;
	//最初的食物点
	Point foodPoint=food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
	DrawObj.DrawFood(foodPoint);
	while (true)//退出
	{
		//检测到有键按下
		if (_kbhit() == 1)
		{
			int ch = _getch();
			if (ch == PauseSpaceKey)//暂停
			{
				while (true)
				{
					int key = _getch();
					if (key == PauseSpaceKey)//按两下空格恢复运动
						break;
					else if (key == EscKey)//暂停时退出
					{
						ch = key;
						ExitFlag = true;
						break;
					}
					continue;
				}
			}
			else if (ch == DoubleDirectionKey) //方向键
			{
				switch (_getch())
				{
				case UpKey:
					//向上运动
					IsFailureFlag = AccordingCommandMove(Direction::Up,&foodPoint);
					break;
				case DownKey:
					//向下运动
					IsFailureFlag = AccordingCommandMove(Direction::Down,&foodPoint);
					break;
				case LeftKey:
					//向左运动
					IsFailureFlag = AccordingCommandMove(Direction::Left,&foodPoint);
					break;
				case RightKey:
					//向右运动
					IsFailureFlag = AccordingCommandMove(Direction::Right,&foodPoint);
					break;
				default:
					break;
				}
			}
			if (ch == EscKey)
			{
				ExitFlag = true;
				break;
			}
		}
		//无键按下,蛇保持运动
		else
		{
			//蛇撞墙
			if (GreedSnake.SnakeMove(Speed,GreedGameMap) == true)
				IsFailureFlag = true;
			else
			{
				if (GreedSnake.EatFood(foodPoint))
				{
					foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(), GreedGameMap);
					DrawObj.DrawFood(foodPoint);
				}
			}
		}
		//蛇撞墙，游戏失败
		if (IsFailureFlag == true)
		{
			DrawObj.DrawFailure(GreedGameMap);
			Point continuePoint=DrawObj.DrawContinueGame(GreedGameMap);
			Point quitPoint=DrawObj.DrawQuitGame(GreedGameMap);
			if (IsContinueGame(continuePoint, quitPoint))
			{
				Control GameControl;
				GameControl.InitGame();
			}
			break;
		}
	}
	return ExitFlag;
}

//根据指令移动
bool Control::AccordingCommandMove(Direction direction,Point *foodPoint)
{
	Food food;
	DrawGameIcon DrawObj;
	if (IsSnakeCurrentOrOppositeDirection(direction)) //与蛇当前运动同向或反向
	{
		if (GreedSnake.SnakeMove(Speed,GreedGameMap) == true)//蛇撞墙
			return true;
		else
		{
			if (GreedSnake.EatFood(*foodPoint))
			{
				*foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
				DrawObj.DrawFood(*foodPoint);
			}
			return false;
		}
	}
	else //与蛇当前运动方向不在一条直线上
	{
		if (GreedSnake.ChangeSnakeDirectionMove(direction,Speed,GreedGameMap) == true)//撞墙
			return true;
		else
			if (GreedSnake.EatFood(*foodPoint))
			{
				*foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
				DrawObj.DrawFood(*foodPoint);
			}
			return false;
	}
}

//判断当前蛇运动方向与指定方向是否同向或方向
bool Control::IsSnakeCurrentOrOppositeDirection(Direction direction)
{
	if (GreedSnake.GetSnakeDirection() == direction||GreedSnake.GetSnakeOppositeDirection()==direction)
		return true;
	else
		return false;
}

bool Control::IsContinueGame(const Point& p1, const Point& p2)
{
	SetWindow setwindow;
	bool continueFlag = false;
	while (true)
	{
		int ch = _getch();
		Point testpoint = setwindow.GetConsoleCursorPosition();
		if (ch == EnterKey && setwindow.GetConsoleCursorPosition() == p1)
		{
			continueFlag = true;
			break;
		}
		else if (ch == EnterKey && setwindow.GetConsoleCursorPosition() == p2)
		{
			continueFlag = false;
			break;
		}
		else
			continue;
	}
	return continueFlag;
}
