#include "Control.h"
//初始化游戏
void Control::PlayGame()
{
	//游戏开始界面，欢迎进入游戏，点击Enter进入游戏界面
	while (true)
	{
		system("cls");
		DrawGameIcon DrawObj;
		bool ExitFlag = false;
		DrawObj.DrawWelcome();
		int ch = _getch();
		if (ch == EnterKey)
		{
			system("cls");
			std::deque<Point> map= GreedGameMap.CreateMapWall();
			DrawObj.DrawMap(map);
			DrawObj.DrawScore(Score, GetScorePoint());
			ExitFlag= KeyWordControl();
		}
		if (ch == EscKey||ExitFlag==true)
		{
			break;
		}
		else if (ExitFlag == false)
		{
			GreedSnake = Snake(GetSnakePoints());
			GreedGameMap = GameMap(5, 5, 25, 25, false);
			Speed = 2;
			Score = 0;
			continue;
		}
	}
	_getch();
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
					Score++;
					DrawObj.DrawScore(Score, GetScorePoint());
					foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(), GreedGameMap);
					DrawObj.DrawFood(foodPoint);
				}
			}
		}
		//蛇撞墙，游戏失败或得到满分通关
		if (IsFailureFlag == true)
		{
			DrawObj.DrawFailure(GreedGameMap);
			if (IsContinueGame()==true)
			{
				ExitFlag = false;
			}
			else
			{
				ExitFlag = true;
			}
			break;
		}
		else if (Score == FullMark)
		{
			DrawObj.DrawGameClearance(GetFinishGamePoint());
			if (IsContinueGame() == true)
			{
				ExitFlag = false;
			}
			else
			{
				ExitFlag = true;
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

bool Control::IsContinueGame()
{
	DrawGameIcon DrawObj;
	Point p1 = GetQuitPoint();
	Point p2 = GetContinuePoint();
	DrawObj.DrawQuitGame(p1);
	DrawObj.DrawContinueGame(p2);
	SetWindow setwindow;
	setwindow.SetCursorPosition((p1.GetX() + p2.GetX()) / 2+3, (p1.GetY() + p2.GetY()) / 2);
	bool IsContinueFlag = false;
	bool flag=false;
	int ch = 0;
	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case LeftKey:
				IsContinueFlag = false;
				DrawObj.DrawQuitGame(p1);
				setwindow.SetCursorPosition(p1.GetX() + 3, p1.GetY());
				break;
			case RightKey:
				IsContinueFlag = true;
				DrawObj.DrawContinueGame(p2);
				setwindow.SetCursorPosition(p2.GetX() + 3, p2.GetY());
				break;
			case EnterKey:
				flag = true;
				break;
			default:
				break;
			}
		}
		if (flag == true)
			break;
	}
	return IsContinueFlag;
}

Point Control::GetQuitPoint()
{
	int centerX = (GreedGameMap.GetMinX() + GreedGameMap.GetMaxX()) / 2;
	int centerY = (GreedGameMap.GetMinY() + GreedGameMap.GetMaxY()) / 2;
	return Point(centerX - 7, centerY + 3);
}

Point Control::GetContinuePoint()
{
	int centerX = (GreedGameMap.GetMinX() + GreedGameMap.GetMaxX()) / 2;
	int centerY = (GreedGameMap.GetMinY() + GreedGameMap.GetMaxY()) / 2;
	return Point(centerX + 2, centerY + 3);
}

std::deque<Point> Control::GetSnakePoints()
{
	//初始化Snake对象
	std::deque<Point> snakePoints;
	snakePoints.emplace_front(Point(10, 10));
	snakePoints.emplace_front(Point(10, 11));
	snakePoints.emplace_front(Point(10, 12));
	return snakePoints;
}

Point Control::GetScorePoint()
{
	int x = (GreedGameMap.GetMinX() + GreedGameMap.GetMaxX()) / 2 - 3;
	int y = GreedGameMap.GetMinY() - 3;
	return Point(x, y);
}

Point Control::GetFinishGamePoint()
{
	int x = (GreedGameMap.GetMinX() + GreedGameMap.GetMaxX()) / 2 - 3;
	int y = (GreedGameMap.GetMinY() + GreedGameMap.GetMaxY()) / 2 - 3;
	return Point(x, y);
}

