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
	
	//�ڽ��浹Ȯ��
	bool isCollide(boxObject obj1, boxObject obj2);

	//�ڽ��� 70���̻�����ִ��� Ȯ���� ��������
	void Overlab(boxObject obj1, boxObject obj2);
	
	//������ ���
	int GetSalinity();

	
	//���ӽð� Ȯ�ΰ�
	bool IsGameTimeOver(float time);

	//���� ������ ǥ��
	void DrawProgressBar();

	//�̴ϰ��� ����� �׸���
	void DrawBoxs();

	//���������� ����
	void SetGame(int stage);
	
	void UpdateGame(float delta);
};
