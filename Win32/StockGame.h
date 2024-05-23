#pragma once
#include <windows.h>
#include "RenderSystem.h"
#include "InputSystem.h"
#include "Button.h"
#include "Types.h"
#include <vector>
struct boxObject
{
    float x;
    float y;
    float width;
    float height;
    float speed;

    COLORREF color;

    int num;

    void MoveStop()
    {
        this->x = this->x;
    }
    void MoveRight(float speed, float delta)
    {
        if (this->x + this->width  <= 1635 )
        {
            this->x += speed * delta;
        }
    }

    void MoveLeft(float speed, float delta)
    {
        if (this->x  >= 280 )
        {
            this->x += speed * -1 * delta;
        }
    }

    void SetBox(float x, float y, float width, float height, float speed, COLORREF color, int _num)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->speed = speed;
        this->color = color;
        this->num = _num;
    }

    void DrawObj();
};
struct StockGarnish  //��� �׷�����
{
    float x = 1535;
    float y = 200;
    float width = 150;
    float height = 100;
    int garnish_num; //��� ��

    void DrawGarnish();

    void SetGarnish(float y, int garnish_num);

};
class StockGame
{
private:
    int score = 0;


    int salinity = 50;
    int targetSalinity; //1��������       2�������� 40 60            3��������
    float curTime = 0;
    float timeLimit = 30000;  //���� �ð�����
    bool isTimeOver = false;
    float redBoxSpeed = 0.6;
    float yelloBoxSpeed = 0.7;
    float renewalTime = 80.0f;  //���� �׷����ٰ� �������� �ӵ� �������� ������ �Ƹ� 
    std::vector<Types::Soup> soupdeco;
            
public:
    StockGame();
    ~StockGame();
    boxObject blackBox = { 260 ,950, 1400, 70, 0, RGB(0, 0, 0), 3 };
    boxObject redBox;
    boxObject yellowBox;
    boxObject pot = { 550,150, 700,700, 0, RGB(0,0,0), 8 };
    boxObject singerum;
    boxObject singerum2;
    boxObject zzamword;
    boxObject singerumword;
    boxObject zzzam;
    boxObject bestline;
    boxObject bestword;
    boxObject brim={ 500, 150, 50, 50 ,0 ,RGB(0,0,0), 11};

 
    StockGarnish garnishList[4];
    //�ڽ��浹Ȯ��
    bool isCollide(boxObject obj1, boxObject obj2);

    //�ڽ��� 60���̻�����ִ��� Ȯ���� ��������
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
    void RenderStockGame(float delta);

    //���� �׷��� �Լ�
    void DrawPot(float delta);

    //��ᰡ ��� �ٱ��� �׸���
    void DrawBasket();

    //���� ���ھ� ��ȯ
    int GameScore();

    //������� Ŭ���� ���ι�ȯ
    bool IsStockClear();

}; 
