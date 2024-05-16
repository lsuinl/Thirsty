#include "Pause.h"
#include "Button.h"
namespace pause
{
    // ���� �Ͻ����� ���¸� ��Ÿ���� ����
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

    // ���� ���� ���� �Լ�
    void IsPause()
    {
        if (input::IsKeyDown(27))
        {
            // �Ͻ����� ���¸� ������Ŵ
            isPaused = !isPaused;
        }
    }

    void RenderPause()
    {
        render::DrawObject(L"resource\\object\\best.bmp", 500, 500, 650, 400, false);
    }

    // ȭ�� ĸó �Լ�
    void CaptureScreen() {

        HDC hdcWindow = GetDC(NULL); // ��ü ȭ���� DC�� ������
        BitBlt(hdcScreen, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), hdcWindow, 0, 0, SRCCOPY); // ȭ���� ĸó�Ͽ� hdcScreen�� ����
        ReleaseDC(NULL, hdcWindow); // DC ����
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