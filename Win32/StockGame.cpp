#include "StockGame.h"
#include "time.h"
#include <string.h>
#include "Button.h"
#include "ChooseFood.h"
#include "Animator.h"
#include "ScreenSystem.h"
#include "LoadData.h"
#include <vector>

//두 오브젝트 충돌검사
int k = 0;
void boxObject::DrawObj()
{
    if (num == 1)
    {
        LoadData::imageManager->DrawPngImage("싱거움", this->x,this->y,80,520,1.0f);
    }
    else if (num == 2)
    {
        LoadData::imageManager->DrawPngImage("짬", this->x, this->y, 80, 520, 1.0f);
    }
    else if (num == 3)
    {
        LoadData::imageManager->DrawPngImage("검은막대", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 4)
    {
        LoadData::imageManager->DrawPngImage("빨간막대", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 5)
    {
        LoadData::imageManager->DrawPngImage("노란막대", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 6)
    {
        LoadData::imageManager->DrawPngImage("베스트선", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 7)
    {
        LoadData::imageManager->DrawPngImage("베스트글자", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 8)
    {
        LoadData::imageManager->DrawPngImage("냄비", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 9)
    {
        LoadData::imageManager->DrawPngImage("약불냄비", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 10)
    {
        LoadData::imageManager->DrawPngImage("강불냄비", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 11)
    {
        LoadData::imageManager->DrawPngImage("넘치는냄비", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 12)
    {
        LoadData::imageManager->DrawPngImage("연기", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 13)
    {
        LoadData::imageManager->DrawPngImage("연기", this->x, this->y, this->width, this->height, 0.5f);
    }
    else if (num == 14)
    {
        LoadData::imageManager->DrawPngImage("연기", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 15)
    {
        LoadData::imageManager->DrawPngImage("싱거움2", this->x, this->y, this->width, this->height, 1.0f);
    }
    else if (num == 16)
    {
        LoadData::imageManager->DrawPngImage("짬글자", this->x, this->y, 38, 46, 1.0f);
    }
    else if (num == 17)
    {
        LoadData::imageManager->DrawPngImage("싱거움글자", this->x, this->y, 105, 45, 1.0f);
    }
}

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
  
    singerum.DrawObj();

    //63, (-(420 / 100) * salinity),
    singerum2.SetBox(119, 200, 80, (((float)520 / (float)100) * (100 - salinity)), 0, RGB(251, 206, 177), 15);
    zzzam.DrawObj();
    singerum2.DrawObj();
    bestline.DrawObj();
    bestword.DrawObj();
    zzamword.DrawObj();
    singerumword.DrawObj();
   
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
    blackBox.DrawObj();
    redBox.DrawObj();
    yellowBox.DrawObj();
}

void StockGame::SetGame(int stage)
{
    LoadData::soundManager->PlayMusic(Music::eSoundList::stock, Music::eSoundChannel::Effect);
    LoadData::soundManager->PlayMusic(Music::eSoundList::stockbgm, Music::eSoundChannel::BGM);


    zzamword.SetBox(138, 160, 80, 520, 0, RGB(255, 0, 0), 16);
    singerumword.SetBox(115, 720, 80, 520, 0, RGB(255, 0, 0), 17);
    zzzam.SetBox(119, 200, 80, 520, 0, RGB(255, 0, 0), 2);
    singerum.SetBox(119, 200, 80, 520, 0, RGB(251, 206, 177), 1);

    soupdeco = PlayerData::player.GetSoup();

    for (int i = 0; i < 4; i++)
    {
        garnishList[i].SetGarnish( i * 150+ 200, soupdeco[i]);
    }
    if (stage == 1)
    {
        isTimeOver = false;
        curTime = 0;
        salinity = 50;
        targetSalinity = 30; //시나리오에따라 값수정필요 25 35  20 40
        redBox.SetBox(blackBox.x + blackBox.width / 2, blackBox.y -10, 360, 90, 0.4, RGB(255, 0, 0), 4);
        yellowBox.SetBox(blackBox.x + blackBox.width / 2, blackBox.y, 260, 70, 0.5, RGB(255, 255, 0), 5);

       
    }
    else if (stage == 2)
    {
        isTimeOver = false;
        curTime = 0;
        salinity = 50;
        targetSalinity = 50;
        redBox.SetBox(blackBox.x + blackBox.width /2, blackBox.y - 10, 240, 90, 0.45, RGB(255, 0, 0), 4);
        yellowBox.SetBox(blackBox.x + blackBox.width / 2, blackBox.y, 170, 70, 0.55, RGB(255, 255, 0), 5);
    }
    else if (stage == 3)
    {
        isTimeOver = false;
        curTime = 0;
        salinity = 50;
        targetSalinity = 90;
        redBox.SetBox(blackBox.x + blackBox.width / 2, blackBox.y - 10, 210, 90, 0.45, RGB(255, 0, 0), 4);
        yellowBox.SetBox(blackBox.x + blackBox.width / 2, blackBox.y, 140, 70, 0.55, RGB(255, 255, 0), 5);
    }
    bestline.SetBox(105, 720 - ((520 / 100) * targetSalinity), 100, 50, 0, RGB(0, 0, 0), 6);
    bestword.SetBox(200, (720 - ((520 / 100) * targetSalinity) + 20) - 20, 154, 50, 0, RGB(0, 255, 0), 7);
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

    if(input::IsKey(13))
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
void StockGame::RenderStockGame(float delta)
{
    LoadData::imageManager->DrawBitMapImage("미니게임",0,0);

    DrawProgressBar();
    DrawBoxs();
    DrawPot(delta);
    std::wstring time = L"남은 시간  " + std::to_wstring((int)(30 - curTime / 1000)) + L" 초";
    render::DrawTextF(0, 0, time.c_str(), RGB(255, 255, 255), 50);
    DrawBasket();

    for (size_t i = 0; i < 4; i++)
    {
        garnishList[i].DrawGarnish();
    }
}

void StockGame::DrawBasket()
{
    for (int i = 0; i < 5; i++)
    {
        LoadData::imageManager->DrawPngImage("바구니", 1455, 170 + (i * 150), 330, 150, 1.0f, true);
    }
}
void StockGame::DrawPot(float delta)
{
    int a[3] = { 9,10,11 };
    int b[3] = { 12,13,14 };
    static ULONGLONG elapsedTime;
    elapsedTime += delta;
    float drawtime = 100.0f;
    if ((Overlab(yellowBox, redBox) == true))
    {
        if (elapsedTime >= drawtime)
        {
            pot.num = a[k % 3];
            brim.num = b[k % 3];
            k++;
            elapsedTime = 0;
        }
    }
    else
    { 
        pot.num = 9;
    }
    pot.DrawObj();
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


void StockGarnish::SetGarnish(float y, int garnish_num)
{
    this->y = y;
    this->garnish_num = garnish_num;
}

void StockGarnish::DrawGarnish()
{
    if (garnish_num == 3)
    {
        LoadData::imageManager->DrawPngImage("멸치", x, y, width, height, 1.0f);
    }
    else if (garnish_num == 4)
    {
        LoadData::imageManager->DrawPngImage("쯔유", x, y, width, height, 1.0f);
    }
    else if (garnish_num == 6)
    {
        LoadData::imageManager->DrawPngImage("무", x, y, width, height, 1.0f);
    }
    else if (garnish_num == 5)
    {
        LoadData::imageManager->DrawPngImage("건다시마", x, y, width, height, 1.0f);
    }
}

