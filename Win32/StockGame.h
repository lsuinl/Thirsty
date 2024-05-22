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

    int num;

    void MoveStop()
    {
        this->x = this->x;
    }
    void MoveRight(float speed, float delta)
    {
        if (this->x + this->width / 2 <= 1740)
        {
            this->x += speed * delta;
        }
    }

    void MoveLeft(float speed, float delta)
    {
        if (this->x - this->width / 2 >= 170)
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
struct StockGarnish  //고명 그려진거
{
    float x = 1485;
    float y = 200;
    float width = 150;
    float height = 100;
    int garnish_num; //고명 값

    void DrawGarnish();

    void SetGarnish(float y, int garnish_num);

};
class StockGame
{
private:
    int score = 0;
    int salinity = 50;
    int targetSalinity; //1스테이지       2스테이지 40 60            3스테이지
    float curTime = 0;
    float timeLimit = 40000;  //게임 시간제한
    bool isTimeOver = false;
    float redBoxSpeed = 0.6;
    float yelloBoxSpeed = 0.7;
    float renewalTime = 80.0f;  //옆에 그래프바가 차오르는 속도 낮을수록 빨리참 아마 

public:
    StockGame();
    ~StockGame();
    boxObject blackBox = { 900 ,900, 1400, 70, 0, RGB(0, 0, 0),0 };
    boxObject redBox;
    boxObject yellowBox;
    boxObject pot = { 700,300, 500,500, 0, RGB(0,0,0),0 };
    boxObject singerum;
    boxObject zzzam;
    
    StockGarnish garnishList[4];
    //박스충돌확인
    bool isCollide(boxObject obj1, boxObject obj2);

    //박스가 60퍼이상속해있는지 확인후 염도조절
    bool Overlab(boxObject obj1, boxObject obj2);

    //염도값 얻기
    int GetSalinity();

    //염도값 조절
    void UpdateSalinity(float delta);

    //게임시간 확인
    void CheckGameTimeOver(float time);

    //염도 게이지 표시
    void DrawProgressBar();

    //미니게임 막대들 그리기
    void DrawBoxs();

    //스테이지별 설정
    void SetGame(int stage);

    //랜덤으로 빨간박스 움직임
    void UpdateRedBox(float delta);

    //입력받아서 노란박스 움직임
    void UpdateYellowBox(float delta);

    //두 박스간 충돌검사밑 염분값 조정
    void UpdateGame(float delta);

    //StockGame 전체렌더
    void RenderStockGame();

    //냄비 그려줄 함수
    void DrawPot();

    //재료가 담길 바구니 그리기
    void DrawBasket();

    //게임 스코어 반환
    int GameScore();

    //스톡게임 클리어 여부반환
    bool IsStockClear();

}; 
