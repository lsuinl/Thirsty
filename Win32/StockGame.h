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


	void MoveStop()
	{
		this->x = this->x;
	}
	void MoveRight(float speed, float delta)
	{
		if (this->x + this->width / 2 <= 1800)
		{
			this->x += speed * delta;
		}
	}

	void MoveLeft(float speed, float delta)
	{
		if (this->x - this->width / 2 >= 200)
		{
			this->x += speed * -1 * delta;
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
class StockGame
{
private:
	int score = 0;
	int salinity = 0;
	int targetSalinity;
	float timeLimit = 1000000;  //���� �ð�����
	bool isTimeOver = false;


	//float printTime;
	//const wchar_t* str1[5] = { L"���� �̽¿���  aadwad��� ������ 1234567890 �������� �������� ��������", 
	//	L"���� ���¿���  ��¼�� ��¼��  �ȳ��ϼ��� �����Դϴ٤�����fadwadwad",L"adwadwadd",L"dwadwadwa",L"dwad����������"};  //�ó����� ��縦 �̸� �Է��ص�1
	//wchar_t str2[5][100];  //�� �ó������ϋ� 1���� ī���ؼ� �����ص� 2
	//wchar_t str3[5][100];  //�ϳ��� ����ҋ� �����ص� 3
	//int i = 0;
	//int j = 0;


public:
	StockGame();
	~StockGame();
	boxObject blackBox = { 900 ,900, 1400, 70, 0, RGB(0, 0, 0) };
	boxObject redBox = { 900, 900, 360, 90 ,0.8 ,RGB(255,0 ,0) };
	boxObject yellowBox = { 900, 900, 260, 70 ,0.7 ,RGB(255,255 ,0) };

	//�ڽ��浹Ȯ��
	bool isCollide(boxObject obj1, boxObject obj2);

	//�ڽ��� 70���̻�����ִ��� Ȯ���� ��������
	void Overlab(boxObject obj1, boxObject obj2);

	//������ ���
	int GetSalinity();

	//���ӽð� Ȯ��
	void CheckGameTimeOver(float time);

	//���� ������ ǥ��
	void DrawProgressBar();

	//�̴ϰ��� ����� �׸���
	void DrawBoxs();

	//���������� ����
	void SetGame(int stage);

	//�������� �����ڽ� ������
	void UpdateRedBox(float delta);

	//�Է¹޾Ƽ� ����ڽ� ������
	void UpdateYellowBox(float delta);

	//�� �ڽ��� �浹�˻�� ���а� ����
	void UpdateGame(float delta);

	//StockGame ��ü����
	void RenderStockGame();

	//���� ���ھ� ��ȯ
	int GameScore();



	////Ű�Է½� ������ ������Ʈ or ���� �� ������Ʈ �� �����ٷ�
	//void SkipText(float delta);

	////�ؽ�Ʈ�� �ѱ��ھ� �����ؼ� ������Ʈ
	//void UpdateText();
	//
	////�ؽ�Ʈ ���
	//void PrintText();



};
