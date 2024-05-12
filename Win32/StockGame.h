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
	//�ڽ��浹Ȯ��
	bool isCollide(boxObject obj1, boxObject obj2);

	//�ڽ��� 70���̻�����ִ��� Ȯ���� ��������
	void Overlab(boxObject obj1, boxObject obj2);
	
	//������ ���
	int GetSalinity();

	//���ӽð� Ȯ�ΰ�
	bool IsGameTimeOver();

};
