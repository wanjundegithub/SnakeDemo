#include "Control.h"
//��ʼ����Ϸ
void Control::PlayGame()
{
	//��Ϸ��ʼ���棬��ӭ������Ϸ�����Enter������Ϸ����
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

//������Ӧ�¼�
bool Control::KeyWordControl()
{
	//�˳���־
	bool ExitFlag = false;
	//ʧ�ܱ�־
	bool IsFailureFlag = false;
	Food food;
	DrawGameIcon DrawObj;
	//�����ʳ���
	Point foodPoint=food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
	DrawObj.DrawFood(foodPoint);
	while (true)//�˳�
	{
		//��⵽�м�����
		if (_kbhit() == 1)
		{
			int ch = _getch();
			if (ch == PauseSpaceKey)//��ͣ
			{
				while (true)
				{
					int key = _getch();
					if (key == PauseSpaceKey)//�����¿ո�ָ��˶�
						break;
					else if (key == EscKey)//��ͣʱ�˳�
					{
						ch = key;
						ExitFlag = true;
						break;
					}
					continue;
				}
			}
			else if (ch == DoubleDirectionKey) //�����
			{
				switch (_getch())
				{
				case UpKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Up,&foodPoint);
					break;
				case DownKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Down,&foodPoint);
					break;
				case LeftKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Left,&foodPoint);
					break;
				case RightKey:
					//�����˶�
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
		//�޼�����,�߱����˶�
		else
		{
			//��ײǽ
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
		//��ײǽ����Ϸʧ�ܻ�õ�����ͨ��
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

//����ָ���ƶ�
bool Control::AccordingCommandMove(Direction direction,Point *foodPoint)
{
	Food food;
	DrawGameIcon DrawObj;
	if (IsSnakeCurrentOrOppositeDirection(direction)) //���ߵ�ǰ�˶�ͬ�����
	{
		if (GreedSnake.SnakeMove(Speed,GreedGameMap) == true)//��ײǽ
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
	else //���ߵ�ǰ�˶�������һ��ֱ����
	{
		if (GreedSnake.ChangeSnakeDirectionMove(direction,Speed,GreedGameMap) == true)//ײǽ
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

//�жϵ�ǰ���˶�������ָ�������Ƿ�ͬ�����
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
	//��ʼ��Snake����
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

