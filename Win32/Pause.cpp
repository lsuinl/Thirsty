#include "Pause.h"
#include "Button.h"
namespace pause
{
    // 게임 일시정지 상태를 나타내는 변수
    bool isPaused = false;

    HDC hdcWindow = GetDC(NULL);
    HDC hdcScreen;
    button::Button restartButton = { "restart", 1100, 600, 300, 100, L"resource\\object\\start.bmp", ReStart };

    void ReStart()
    {
        Screen::ReScreen();
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
            // 일시정지 상태를 반전시킴
            isPaused = !isPaused;
        }
    }

    void RenderPause()
    {
        render::DrawObject(L"resource\\object\\best.bmp", 500, 500, 650, 400, false);
    }

    // 화면 캡처 함수
    void CaptureScreen() {

        HDC hdcWindow = GetDC(NULL); // 전체 화면의 DC를 가져옴
        BitBlt(hdcScreen, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), hdcWindow, 0, 0, SRCCOPY); // 화면을 캡처하여 hdcScreen에 복사
        ReleaseDC(NULL, hdcWindow); // DC 해제
    }

    void DrawReStart()
    {
        restartButton.DrawButton();
    }

    void IsCheckReStart(int x, int y)
    {
        if (restartButton.CheckClick(x, y))
        {
            restartButton.PlayFunction();
        }
    }
}