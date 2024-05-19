#include "Pause.h"
#include "Button.h"
#include "ScreenSystem.h"
#include "LoadData.h"
namespace pause
{
    // ���� �Ͻ����� ���¸� ��Ÿ���� ����
    bool isPaused = false;

    HDC hdcWindow = GetDC(NULL);
    HDC hdcScreen;

    // restart ��ư ����
    button::Button restartButton = { "����۹�ư", 700, 600, 500, 130, ReStart };

    // title ��ư ����
    button::Button reTitleButton = { "Ÿ��Ʋ��ư", 700, 800, 500, 130,  ReTitle };

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
        LoadData::imageManager->DrawBitMapImage("�Ͻ�����,", 450, 50);
    }

    // ȭ�� ĸó �Լ�
    void CaptureScreen() {

        HDC hdcWindow = GetDC(NULL); // ��ü ȭ���� DC�� ������
        BitBlt(hdcScreen, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), hdcWindow, 0, 0, SRCCOPY); // ȭ���� ĸó�Ͽ� hdcScreen�� ����
        ReleaseDC(NULL, hdcWindow); // DC ����
    }

    void DrawReButton()
    {
        restartButton.DrawButton();
        reTitleButton.DrawButton();
    }

    void IsCheckReButton(int x, int y)
    {
        if (restartButton.CheckClick(x, y))
        {
            restartButton.PlayFunction();
        }
        if (reTitleButton.CheckClick(x, y))
        {
            reTitleButton.PlayFunction();
        }
    }
}