#pragma once
#include <windows.h>
#include "RenderSystem.h"
#include "InputSystem.h"
struct boxObject
{
	float x;
	float y;
	float width;
	float height;
	float speed;

	COLORREF color;


	void Move(float delta)
	{
		if (this->x + this->width /2 <= 1700)
		{
			this->x += speed * delta;
		}
	}

	void Moveleft(float delta)
	{
		if (this->x - this->width / 2>= 200)
		{
			this->x += 0.15 * -1 * delta;
		}
	}

	void SetBox(float x, float y, float width, float height, float speed, COLORREF color)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->speed = speed;
		this->color = color;
	}
};
class Stock
{
private:

	int salinity = 0;
	float timeLimit = 5000;
	
	

public:
	Stock();
	~Stock();

	boxObject blackBox = { 900 ,900, 1400, 70, 0, RGB(0, 0, 0) };
	boxObject redBox;
	boxObject yellowBox;
	
	//박스충돌확인
	bool isCollide(boxObject obj1, boxObject obj2);

	//박스가 70퍼이상속해있는지 확인후 염도조절
	void Overlab(boxObject obj1, boxObject obj2);
	
	//염도값 얻기
	int GetSalinity();

	
	//게임시간 확인값
	bool IsGameTimeOver(float time);

	//염도 게이지 표시
	void DrawProgressBar();

	//미니게임 막대들 그리기
	void DrawBoxs();

	//스테이지별 설정
	void SetGame(int stage);
	
	void UpdateGame(float delta);
};
