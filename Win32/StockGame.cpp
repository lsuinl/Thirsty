#include "StockGame.h"
#include "time.h"
#include <string.h>
//두 오브젝트 충돌검사
bool StockGame::isCollide(boxObject obj1, boxObject obj2)
{
	if (obj1.x < obj2.x + obj2.width &&
		obj1.x + obj1.width > obj2.x &&
		obj1.y < obj2.y + obj2.height &&
		obj1.y + obj1.height > obj2.y)
	{
		return true;
	}
	return false;
}

//노란상자가 70퍼센트이상 속했는지 확인
void StockGame::Overlab(boxObject obj1, boxObject obj2)
{
	float totalSize = 0.0f;
	boxObject bigObj;
	boxObject smallObj;
	if (obj1.width > obj2.width)
	{
		bigObj = obj1;
		smallObj = obj2;
	}
	else
	{
		bigObj = obj2;
		smallObj = obj1;
	}
	if (isCollide(bigObj, smallObj) == true)
	{
		if (bigObj.x >= smallObj.x)
		{
			totalSize = (bigObj.x + bigObj.width / 2) - (smallObj.x - smallObj.width / 2);
		}
		else
		{
			totalSize = (smallObj.x + smallObj.width / 2) - (bigObj.x - bigObj.width / 2);
		}
	}

	if (isCollide(bigObj, smallObj) && totalSize <= bigObj.width + smallObj.width * 0.3)
	{
		if (salinity < 100)
		{
			salinity++;
		}
	}
	else
	{
		if (salinity > 0)
		{
			salinity--;
		}
	}
}

void StockGame::DrawProgressBar()
{
	render::DrawRect(100, 800, 100, -500, RGB(255, 0, 0));
	render::DrawRect(100, 800, 100, -((500 / 100) * salinity), RGB(255, 255, 0));

}

StockGame::StockGame()
{
}
StockGame::~StockGame()
{
}
int StockGame::GetSalinity()
{
	return salinity;
}
void StockGame::CheckGameTimeOver(float delta)
{
	static ULONGLONG elapsedTime2;
	elapsedTime2 += delta;
	if (elapsedTime2 >= timeLimit)
	{
		isTimeOver = true;
		elapsedTime2 = 0;

	}
}

void StockGame::DrawBoxs()
{
	render::DrawRect(blackBox.x - blackBox.width / 2, blackBox.y - blackBox.height / 2, blackBox.x + blackBox.width / 2, blackBox.height, blackBox.color);
	render::DrawRect(redBox.x - redBox.width / 2, redBox.y - redBox.height / 2, redBox.width, redBox.height, redBox.color);
	render::DrawRect(yellowBox.x - yellowBox.width / 2, yellowBox.y - yellowBox.height / 2, yellowBox.width, yellowBox.height, yellowBox.color);
}

void StockGame::SetGame(int stage)
{
	if (stage == 1)
	{
		salinity = 0;
		targetSalinity = 100; //시나리오에따라 값수정필요
		redBox.SetBox(blackBox.x, blackBox.y, 360, 90, 0, RGB(255, 0, 0));
		yellowBox.SetBox(blackBox.x, blackBox.y, 260, 70, 3, RGB(255, 255, 0));
	}
	if (stage == 2)
	{
		salinity = 0;
		targetSalinity = 100;
		redBox.SetBox(blackBox.x, blackBox.y, 240, 90, 0, RGB(255, 0, 0));
		yellowBox.SetBox(blackBox.x, blackBox.y, 170, 70, 3, RGB(255, 255, 0));
	}
	if (stage == 3)
	{
		salinity = 0;
		targetSalinity = 100;
		redBox.SetBox(blackBox.x, blackBox.y, 160, 90, 0, RGB(255, 0, 0));
		yellowBox.SetBox(blackBox.x, blackBox.y, 100, 70, 3, RGB(255, 255, 0));
	}
}

void StockGame::UpdateYellowBox(float delta)
{
	if (isTimeOver == false)
	{
		if (input::IsKey(32))
		{
			
			yellowBox.MoveRight(yellowBox.speed, delta);
		}
		else
		{
			yellowBox.MoveLeft(0.3, delta);
		}
	}
}


void StockGame::UpdateRedBox(float delta)
{
	srand(time(NULL));
	int ranDir = rand() % 3 + 1;
	int random;
	random = rand() % 5 * 100;

	if (ranDir == 1)
	{
		redBox.MoveLeft(redBox.speed, delta);
	}
	else if (ranDir == 2)
	{
		redBox.MoveStop();
	}
	else if (ranDir == 3)
	{
		redBox.MoveRight(redBox.speed, delta);
	}


}
void StockGame::UpdateGame(float delta)
{
	static ULONGLONG elapsedTime;
	float checktime = 50.0f;
	elapsedTime += delta;
	if (isTimeOver == false)
	{
		if (elapsedTime >= checktime)
		{
			Overlab(yellowBox, redBox);
			UpdateRedBox(delta);
			elapsedTime = 0;
		}
	}
	CheckGameTimeOver(delta);

}
void StockGame::RenderStockGame()
{
	DrawProgressBar();
	DrawBoxs();
}
int StockGame::GameScore()
{
	if (salinity >= targetSalinity - 20 || salinity <= targetSalinity + 20)
	{
		score = 100;
	}
	else
	{
		score = 0;
	}
	return score;
}

//void StockGame::SkipText(float delta)
//{
//	static ULONGLONG elapsedTime;
//	elapsedTime += delta;
//	if (input::IsKey(17))
//	{
//		printTime = 10;
//	}
//	else
//	{
//		printTime = 1000;
//	}
//
//	if (input::IsKeyUp(9))
//	{
//		wcscpy_s(str3[j], str2[j]);
//	}
//
//	if (elapsedTime >= printTime)
//	{
//		if (i < 100)
//		{
//			i++;
//			elapsedTime = 0;
//		}
//	}
//	
//}
//void StockGame::UpdateText()
//{
//	wcscpy_s(str2[j], str1[j]);
//	if (wcscmp(str3[j], str2[j]) == 0)
//	{
//		if (j < 4)
//		{
//			i = 0;
//			j++;
//		}
//	}
//	else
//	{
//		wcsncpy_s(str3[j], str2[j], i);
//	}
//
//}
//void StockGame::PrintText()
//{
//	render::DrawTextF(100, 100, str3[0], RGB(0, 0, 255), 50);
//	render::DrawTextF(100, 200, str3[1], RGB(0, 255, 250), 50);
//	render::DrawTextF(100, 300, str3[2], RGB(0, 255, 250), 50);
//	render::DrawTextF(100, 400, str3[3], RGB(0, 255, 250), 50);
//	render::DrawTextF(100, 500, str3[4], RGB(0, 255, 250), 50);
//}