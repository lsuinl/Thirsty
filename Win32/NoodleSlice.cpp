#include "NoodleSlice.h"
#include <time.h>
#include "LoadData.h"
#include "Pause.h"
// 게임 세팅
void NoodleSlice::SetGame(int _stage, int _noodle)
{
    clearState = 0;

    LoadData::soundManager->PlayMusic(Music::eSoundList::noodleslice, Music::eSoundChannel::BGM);
    input::SetKeyCode(false);
    srand(time(NULL));

    // 플레이 시간
    playTimer = 0;

    // 종료
    endTimer = 0;

    // 게임 진행 성공 여부
    isSuccess = false;

    // 맞춘 횟수
    cnt = 0;

    // 세트 카운트
    setCnt = 0;

    // 스코어
    playerScore = 0;

    // 초기화 여부
    isReset = false;

    // 변수 대입
    if (_stage == 1) stage = 4;
    else if (_stage == 2) stage = 6;
    else stage = 8;

    if (_noodle == 1) noodle = 4;
    else if (_noodle == 2) noodle = 6;
    else noodle = 8;

    // 최대 사이즈
    arrSize = stage * noodle;

    // 배열 생성
    CreatArrowArr();
}

void NoodleSlice::SetClearCheck(int n)
{
    clearState = n;
}

// 게임루프
void NoodleSlice::UpdateGame()
{
    playTimer += TimeSystem::GetDeltaTime();

    if (playTimer <= 220000)
    {
        if (isReset)
        {
            resetTimer += TimeSystem::GetDeltaTime();
            if (resetTimer > 300)
            {
                isReset = false;
            }
        }
        else
        {
            InputArrow();
        }
    }
}

// 배열 해제
void NoodleSlice::ReleaseGame()
{
    delete[] arrowArr;
}

// 방향키 배열 생성
void NoodleSlice::CreatArrowArr()
{
    // 배열 생성
    // (랜덤으로.. 38 = ↑, 37 = ←, 40 = ↓, 39 = →)
    arrowArr = new Arrow * [noodle]; // 행 수만큼의 포인터를 가리키는 배열 생성

    for (int i = 0; i < noodle; ++i) {
        arrowArr[i] = new Arrow[stage];
    }

    for (int i = 0; i < noodle; i++)
    {
        for (int j = 0; j < stage; j++)
        {
            (arrowArr[i][j].arrowType = rand() % 4 + 37);
            (arrowArr[i][j].isTrue = false);
        }
    }
}

// 방향키 맞게 쳤는지 검사
void NoodleSlice::CompareArrow(ArrowType keyCode)
{
    // 맞았다면?
    if (arrowArr[setCnt][cnt % stage].arrowType == (int)keyCode)
    {
        arrowArr[setCnt][cnt % stage].isTrue = true;

        if (cnt < arrSize - 1)
        {
            cnt++;
        }
        else
        {
            isSuccess = true;
        }

        playerScore++;
        if (cnt != 0 && cnt < arrSize)
        {
            if (cnt % stage == 0)
            {
                LoadData::soundManager->PlayMusic(Music::eSoundList::slice, Music::eSoundChannel::Effect1);
                setCnt++;
            }
        }
    }
    else // 못맞췄을 시 처음부터 다시
    {
        LoadData::soundManager->PlayMusic(Music::eSoundList::wrong, Music::eSoundChannel::Effect);
        resetTimer = 0;
        isReset = true;
        playerScore = 0;
        cnt = setCnt * stage;

        for (int i = setCnt; i < noodle; i++)
        {
            for (int j = 0; j < stage; j++)
            {
                arrowArr[i][j].isTrue = false;
            }
        }
    }
}

// 방향키 입력받은 후 처리 시스템
void NoodleSlice::InputArrow()
{
    if (input::IsKeyCode()) {
        if (input::IsKeyUp(37) || input::IsKeyUp(38) || input::IsKeyUp(39) || input::IsKeyUp(40))
        {
            input::SetKeyCode(false);
        }
    }
    else {
        if (input::IsKeyDown(38)) // up
        {
            LoadData::soundManager->PlayMusic(Music::eSoundList::right, Music::eSoundChannel::Effect);
            CompareArrow(UPARROW);
            input::SetKeyCode(true);
        }
        else if (input::IsKeyDown(37)) // left
        {
            LoadData::soundManager->PlayMusic(Music::eSoundList::right, Music::eSoundChannel::Effect);
            CompareArrow(LEFTARROW);
            input::SetKeyCode(true);
        }
        else if (input::IsKeyDown(40)) // down
        {
            LoadData::soundManager->PlayMusic(Music::eSoundList::right, Music::eSoundChannel::Effect);
            CompareArrow(DOWNARROW);
            input::SetKeyCode(true);
        }
        else if (input::IsKeyDown(39)) // right
        {
            LoadData::soundManager->PlayMusic(Music::eSoundList::right, Music::eSoundChannel::Effect);
            CompareArrow(RIGHTARROW);
            input::SetKeyCode(true);
        }
    }
}

// cnt 반환
int NoodleSlice::GetCnt()
{
    return cnt;
}

// setcnt 반환
int NoodleSlice::GetSetCnt()
{
    return setCnt;
}

// arrsize 반환
int NoodleSlice::GetArrSize()
{
    return arrSize;
}

// render
void NoodleSlice::NoodleSliceScreen()
{
    LoadData::imageManager->DrawBitMapImage("미니게임", 0, 0);
    SliceAni();

    // 치기 전
    for (int i = setCnt; i < setCnt + 1; i++)
    {
        for (int j = 0; j < stage; j++)
        {
            if (arrowArr[i][j].arrowType == UPARROW)
            {
                if (arrowArr[i][j].isTrue == true)
                {
                    LoadData::imageManager->DrawPngImage("위", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else
                {
                    LoadData::imageManager->DrawPngImage("회색위", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
            }
            else if (arrowArr[i][j].arrowType == DOWNARROW)
            {
                if (arrowArr[i][j].isTrue == true)
                {
                    LoadData::imageManager->DrawPngImage("아래", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else
                {
                    LoadData::imageManager->DrawPngImage("회색아래", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
            }
            else if (arrowArr[i][j].arrowType == RIGHTARROW)
            {
                if (arrowArr[i][j].isTrue == true)
                {
                    LoadData::imageManager->DrawPngImage("오른쪽", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else
                {
                    LoadData::imageManager->DrawPngImage("회색오른쪽", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
            }
            else if (arrowArr[i][j].arrowType == LEFTARROW)
            {
                if (arrowArr[i][j].isTrue == true)
                {
                    LoadData::imageManager->DrawPngImage("왼쪽", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else
                {
                    LoadData::imageManager->DrawPngImage("회색왼쪽", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
            }
        }
    }

    // 틀렸을 때 잠깐 색 바꾸기
    if (isReset == true)
    {
        for (int i = setCnt; i < setCnt + 1; i++)
        {
            for (int j = 0; j < stage; j++)
            {
                if (arrowArr[i][j].arrowType == UPARROW)
                {
                    LoadData::imageManager->DrawPngImage("빨간위", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else if (arrowArr[i][j].arrowType == DOWNARROW)
                {
                    LoadData::imageManager->DrawPngImage("빨간아래", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else if (arrowArr[i][j].arrowType == RIGHTARROW)
                {
                    LoadData::imageManager->DrawPngImage("빨간오른쪽", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
                else if (arrowArr[i][j].arrowType == LEFTARROW)
                {
                    LoadData::imageManager->DrawPngImage("빨간왼쪽", 967 - ((stage / 2) * 100) + (j % stage) * 100, 200, 100, 100, true);
                }
            }
        }
    }

    LoadData::imageManager->DrawPngImage("시간", 807, 30, 320, 100, true);
    std::wstring S = std::to_wstring((int)(22 - playTimer / 1000) / 10);
    std::wstring s = std::to_wstring((int)(22 - playTimer / 1000) % 10);
    render::DrawTextF(940, 40, S.c_str(), RGB(59, 34, 18), 78);
    render::DrawTextF(986, 40, s.c_str(), RGB(59, 34, 18), 78);

    /*if (clearState == 1)
    {
        endTimer += TimeSystem::GetDeltaTime();

        pause::CaptureScreen();
        LoadData::imageManager->DrawPngImage("성공", 967 - 250, 540 - 100, 500, 200, 1.0f, true);

        if (endTimer >= 5000)
        {
            isSuccess = true;
        }
    }
    else if (clearState == 2)
    {
        endTimer += TimeSystem::GetDeltaTime();

        pause::CaptureScreen();
        LoadData::imageManager->DrawPngImage("타임오버", 967 - 300, 540 - 100, 600, 200, 1.0f, true);

        if (endTimer >= 5000)
        {
            isSuccess = true;
        }
    }*/
}

// 게임 성공 여부
bool NoodleSlice::NoodleSuccess()
{
    if (cnt == arrSize )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void NoodleSlice::SliceAni()
{
    if (setCnt > 0)
    {
        if (noodle == 4)
        {
            LoadData::imageManager->DrawPngImage("납작면" + std::to_string(setCnt), 717, 550, 500, 500, true);
        }
        else if (noodle == 6)
        {
            LoadData::imageManager->DrawPngImage("중면" + std::to_string(setCnt), 717, 550, 500, 500, true);
        }
        else if (noodle == 8)
        {
            LoadData::imageManager->DrawPngImage("소면" + std::to_string(setCnt), 717, 550, 500, 500, true);
        }
    }
    else
    {
        LoadData::imageManager->DrawPngImage("면반죽", 717, 550, 500, 500, true);
    }

    if (noodle == 4)
    {
        LoadData::imageManager->DrawPngImage("칼든손", 900 - (100 * setCnt), 500, 450, 900, true);
    }
    if (noodle == 6)
    {
        LoadData::imageManager->DrawPngImage("칼든손", 900 - (64 * setCnt), 500, 450, 900, true);
    }
    if (noodle == 8)
    {
        LoadData::imageManager->DrawPngImage("칼든손", 900 - (50 * setCnt), 500, 450, 900, true);
    }
}