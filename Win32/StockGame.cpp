#include "StockGame.h"

//두 오브젝트 충돌검사
bool Stock::isCollide(boxObject obj1, boxObject obj2)
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
void Stock::Overlab(boxObject obj1, boxObject obj2)
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
		if(salinity > 0)
		{
			salinity--;
		}
	}
}

void Stock::DrawProgressBar()
{
	render::DrawRect(100, 800, 100, -500, RGB(255, 0, 0));
	render::DrawRect(100, 800, 100, -((500 / 100) * salinity), RGB(255, 255, 0));

}

Stock::Stock()
{
}
Stock::~Stock()
{
}
int Stock::GetSalinity()
{
	return salinity;
}
bool Stock::IsGameTimeOver(float time)
{
	return timeLimit <= time;
	
}

void Stock::DrawBoxs()
{
	render::DrawRect(blackBox.x - blackBox.width / 2, blackBox.y - blackBox.height / 2, blackBox.x + blackBox.width / 2,  blackBox.height, blackBox.color);
	render::DrawRect(redBox.x - redBox.width / 2, redBox.y - redBox.height / 2, redBox.width, redBox.height, redBox.color);
	render::DrawRect(yellowBox.x - yellowBox.width / 2, yellowBox.y - yellowBox.height / 2, yellowBox.width, yellowBox.height, yellowBox.color);
}

void Stock::SetGame(int stage)
{
	if (stage == 1)
	{
		salinity = 0;
		redBox.SetBox(blackBox.x, blackBox.y, 360, 90, 0, RGB(255, 0, 0));
		yellowBox.SetBox(blackBox.x, blackBox.y, 260, 70, 0.5, RGB(255, 255, 0));
	}
}

void Stock::UpdateGame(float delta)
{
	static ULONGLONG elapsedTime;
	elapsedTime += delta;
	if(IsGameTimeOver(elapsedTime)==false)
	{
		if (input::IsKeyDown(32))
		{
			yellowBox.Move(delta);
		}
		else
		{
			yellowBox.Moveleft(delta);
		}

		Overlab(yellowBox, redBox);

		
		
	}


	
}

