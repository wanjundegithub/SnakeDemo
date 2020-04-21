#include "Control.h"

//初始化游戏
void Control::InitGame()
{
	//游戏开始界面，欢迎进入游戏，点击Enter进入游戏界面
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
			RunGame();
		}
		else if (ch == EscKey)
			break;
	}
}

//运行游戏
void Control::RunGame()
{
	//画出游戏界面
	std::deque<Point> map= GreedGameMap.CreateMapWall();
	DrawGameIcon DrawObj;
	DrawObj.DrawMap(map);
	KeyWordControl();
}


//键盘响应事件
void Control::KeyWordControl()
{
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
			if (ch == EscKey)
				break;
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
			break;
		}
	}
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
