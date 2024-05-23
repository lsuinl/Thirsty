#include "Pause.h"

namespace pause
{
    // 게임 일시정지 상태를 나타내는 변수
    bool isPaused = false;

    HDC hdcWindow = GetDC(NULL);
    HDC hdcScreen;

    // 메뉴버튼
    button::Button menuButton = { "메뉴", 1800, 30, 75, 70, Menu };

    // restart 버튼 생성
    button::Button restartButton = { "재시작버튼", 960, 500, 210, 65, ReStart };

    // title 버튼 생성
    button::Button reTitleButton = { "타이틀버튼", 960, 670, 210, 65,  ReTitle };

    void Menu()
    {
        // 반전시키기
        isPaused = !isPaused;
    }

    void ReStart()
    {
        Screen::ReStartScreen();
        isPaused = false;
    }

    void ReTitle()
    {
        Screen::ReTitleScreen();
        isPaused = false;
    }

    bool GetIsPause()
    {
        return isPaused;
    }

    // 퍼즈 상태 반전 함수
    void IsPause()
    {
        if (input::IsKeyDown(27))
        {
            LoadData::soundManager->PlayMusic(Music::eSoundList::click, Music::eSoundChannel::Effect1);
            // 일시정지 상태를 반전시킴
            isPaused = !isPaused;
        }
    }

    void RenderPause()
    {
        LoadData::imageManager->DrawPngImage("일시정지", 667, 240, 600, 600, true);
    }

    void DrawMenuButton()
    {
        menuButton.DrawButton();
    }

    // 화면 캡처 함수
    void CaptureScreen() {

        HDC hdcWindow = GetDC(NULL); // 전체 화면의 DC를 가져옴
        BitBlt(hdcScreen, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), hdcWindow, 0, 0, SRCCOPY); // 화면을 캡처하여 hdcScreen에 복사
        ReleaseDC(NULL, hdcWindow); // DC 해제
    }

    void DrawReButton()
    {
        restartButton.DrawButton();
        reTitleButton.DrawButton();
    }

    void IsButton(int x, int y)
    {
        if (restartButton.CheckClick(x, y))
        {
            restartButton.PlayFunction();
        }
        if (reTitleButton.CheckClick(x, y))
        {
            reTitleButton.PlayFunction();
        }
        if (menuButton.CheckClick(x, y))
        {
            menuButton.PlayFunction();
        }
    }

    void IsMenuButton(int x, int y)
    {
        if (menuButton.CheckClick(x, y))
        {
            menuButton.PlayFunction();
        }
    }
}