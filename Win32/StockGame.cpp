#include "StockGame.h"
#include "time.h"
#include <string.h>
#include "Button.h"
#include "ChooseFood.h"
#include "Animator.h"
#include "ScreenSystem.h"
#include "LoadData.h"
//두 오브젝트 충돌검사

bool StockGame::isCollide(boxObject obj1, boxObject obj2)
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
bool StockGame::Overlab(boxObject obj1, boxObject obj2)
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

    if (isCollide(bigObj, smallObj) && totalSize <= bigObj.width + smallObj.width * 0.4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void StockGame::UpdateSalinity(float delta)
{
    static ULONGLONG elapsedTime;
    elapsedTime += delta;
    if (Overlab(yellowBox, redBox) == true)
    {
        if (elapsedTime >= renewalTime)
        {
            if (salinity < 100)
            {
                salinity++;
                elapsedTime = 0;
            }
        }
    }
    else
    {
        if (elapsedTime >= renewalTime)
        {
            if (salinity > 0)
            {
                salinity--;
                elapsedTime = 0;
            }
        }
    }

}
void StockGame::DrawProgressBar()
{
    render::DrawRect(100, 700, 100, -500, RGB(251, 206, 177));
    render::DrawRect(100, 700, 100, -((500 / 100) * salinity), RGB(255, 0, 0));
}

StockGame::StockGame()
{
}
StockGame::~StockGame()
{
}
int StockGame::GetSalinity()
{
    return salinity;
}
void StockGame::CheckGameTimeOver(float delta)
{
    if (isTimeOver != true)
    {
        curTime += delta;
    }

    if (curTime >= timeLimit)
    {
        curTime = curTime;
        isTimeOver = true;
    }
}

void StockGame::DrawBoxs()
{
    render::DrawRect(blackBox.x - blackBox.width / 2, blackBox.y - blackBox.height / 2, blackBox.x + blackBox.width / 2, blackBox.height, blackBox.color);
    render::DrawRect(redBox.x - redBox.width / 2, redBox.y - redBox.height / 2, redBox.width, redBox.height, redBox.color);
    render::DrawRect(yellowBox.x - yellowBox.width / 2, yellowBox.y - yellowBox.height / 2, yellowBox.width, yellowBox.height, yellowBox.color);
}

void StockGame::SetGame(int stage)
{
    if (stage == 1)
    {
        isTimeOver = false;
        curTime = 0;
        salinity = 50;
        targetSalinity = 30; //시나리오에따라 값수정필요 25 35  20 40
        redBox.SetBox(blackBox.x, blackBox.y, 360, 90, 0.5, RGB(255, 0, 0)); 
        yellowBox.SetBox(blackBox.x, blackBox.y, 260, 70, 0.6, RGB(255, 255, 0));
    }
    else if (stage == 2)
    {
        isTimeOver = false;
        curTime = 0;
        salinity = 50;
        targetSalinity = 50;
        redBox.SetBox(blackBox.x, blackBox.y, 240, 90, redBoxSpeed, RGB(255, 0, 0));
        yellowBox.SetBox(blackBox.x, blackBox.y, 170, 70, yelloBoxSpeed, RGB(255, 255, 0));
    }
    else if (stage == 3)
    {
        isTimeOver = false;
        curTime = 0;
        salinity = 50;
        targetSalinity = 90;                
        redBox.SetBox(blackBox.x, blackBox.y, 210, 90, 0.4, RGB(255, 0, 0));
        yellowBox.SetBox(blackBox.x, blackBox.y, 140, 70, yelloBoxSpeed, RGB(255, 255, 0));
    }
}

void StockGame::UpdateYellowBox(float delta)
{
    if (isTimeOver == false)
    {
        if (input::IsKey(32))
        {
            yellowBox.MoveRight(yellowBox.speed, delta);
        }
        else
        {
            yellowBox.MoveLeft(yellowBox.speed, delta);
        }
    }

    if(input::IsKey(16))
    {
        salinity = targetSalinity;
        isTimeOver = true;
    }

}


void StockGame::UpdateRedBox(float delta)
{
    srand(time(NULL));
    static int ranDir = 0;
    static ULONGLONG elapsedTime;
    elapsedTime += delta;
    float movetime = 15.0f;
    if (elapsedTime >= movetime)
    {
        ranDir = rand() % 8 + 1;
    }

    if (ranDir == 1 || ranDir == 2 || ranDir == 3)
    {
        redBox.MoveLeft(redBox.speed, delta);
    }
    else if (ranDir == 4 || ranDir == 5)
    {
        redBox.MoveStop();
    }
    else if (ranDir == 6 || ranDir == 7 || ranDir == 8)
    {
        redBox.MoveRight(redBox.speed, delta);
    }

}
void StockGame::UpdateGame(float delta)
{

    if (isTimeOver == false)
    {
        UpdateSalinity(delta);
        UpdateRedBox(delta);

    }
    else
    {
        Screen::SetScreen();
    }
    CheckGameTimeOver(delta);


}
void StockGame::RenderStockGame()
{
    LoadData::imageManager->DrawBitMapImage("배경화면",0,0);

    DrawProgressBar();
    DrawBoxs();
    DrawPot();
    std::wstring time = L"남은 시간  " + std::to_wstring((int)(40 - curTime / 1000)) + L" 초";
    render::DrawTextF(0, 0, time.c_str(), RGB(255, 255, 255), 50);
    render::DrawTextF(125, 130, L"짬", RGB(251, 206, 177),60);
    render::DrawTextF(85, 720, L"싱거움", RGB(255, 0, 0), 60);
    render::DrawRect(100, 700 - ((500/ 100) * targetSalinity), 100, 5, RGB(0, 0, 0));
                   
    render::DrawTextF(200, (700 - ((500 / 100) * targetSalinity)) - 20, L"BEST", RGB(0, 255, 0), 50);


    DrawBasket();
}

void StockGame::DrawBasket()
{
    for (int i = 0; i < 5; i++)
    {
        LoadData::imageManager->DrawPngImage("바구니", 1485, 200 + (i * 150), 150, 100,  1.0f);
    }
}
void StockGame::DrawPot()
{
    //일단 배경그리는걸로 냄비그림 수정필요
    if ((Overlab(yellowBox, redBox) == true))
    {
        LoadData::imageManager->DrawPngImage("짱",pot.x, pot.y, pot.width, pot.height, 1.0f);
    }
    else
    {
        LoadData::imageManager->DrawPngImage("바구니", pot.x, pot.y, pot.width, pot.height, 1.0f);
    }
}
int StockGame::GameScore()
{
    if (salinity >= targetSalinity - 20 || salinity <= targetSalinity + 20)
    {
        score = 100;
    }
    else
    {
        score = 0;
    }
    return score;
}

bool StockGame::IsStockClear()
{
    return salinity >= targetSalinity - 10 && salinity <= targetSalinity + 10;
}

