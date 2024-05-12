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
		salinity++;
	}
	else
	{
		salinity--;
	}
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
bool Stock::IsGameTimeOver()
{
	return gameOverTime >= 2000;
}