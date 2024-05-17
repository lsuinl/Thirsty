#pragma once
#include <windows.h>
#include "RenderSystem.h"
#include "InputSystem.h"
#include "Button.h"
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
    int salinity = 50;
    int targetSalinity;
    float curTime = 0;
    float timeLimit = 20000;  //���� �ð�����
    bool isTimeOver = false;


public:
    StockGame();
    ~StockGame();
    boxObject blackBox = { 900 ,900, 1400, 70, 0, RGB(0, 0, 0) };
    boxObject redBox = { 900, 900, 360, 90 ,0.4 ,RGB(255,0 ,0) };
    boxObject yellowBox = { 900, 900, 260, 70 ,0.7 ,RGB(255,255 ,0) };
    boxObject pot = { 700,300, 500,500, 0, RGB(0,0,0) };

    //�ڽ��浹Ȯ��
    bool isCollide(boxObject obj1, boxObject obj2);

    //�ڽ��� 70���̻�����ִ��� Ȯ���� ��������
    bool Overlab(boxObject obj1, boxObject obj2);

    //������ ���
    int GetSalinity();

    //������ ����
    void UpdateSalinity(float delta);

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

    //���� �׷��� �Լ�
    void DrawPot();

    //��ᰡ ��� �ٱ��� �׸���
    void DrawBasket();
    //���� ���ھ� ��ȯ
    int GameScore();


};