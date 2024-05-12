#pragma once
#include <windows.h>

class Stock
{
private:

	int salinity = 0;

public:
	Stock();

	~Stock();

	float gameOverTime;

	struct boxObject
	{
		float x;
		float y;
		float width;
		float height;
		float speed;

		COLORREF color;

		void SetPos(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		void Move(float x, float y)
		{
			this->x += x;
			this->y += y;
		}
	};
	//박스충돌확인
	bool isCollide(boxObject obj1, boxObject obj2);

	//박스가 70퍼이상속해있는지 확인후 염도조절
	void Overlab(boxObject obj1, boxObject obj2);
	
	//염도값 얻기
	int GetSalinity();

	//게임시간 확인값
	bool IsGameTimeOver();

};
