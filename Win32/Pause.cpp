#include "Pause.h"

namespace pause
{
    // ���� �Ͻ����� ���¸� ��Ÿ���� ����
    bool isPaused = false;

    HDC hdcWindow = GetDC(NULL);
    HDC hdcScreen;

    // �޴���ư
    button::Button menuButton = { "�޴�", 1800, 30, 75, 70, Menu };

    // restart ��ư ����
    button::Button restartButton = { "����۹�ư", 960, 500, 210, 65, ReStart };

    // title ��ư ����
    button::Button reTitleButton = { "Ÿ��Ʋ��ư", 960, 670, 210, 65,  ReTitle };

    void Menu()
    {
        // ������Ű��
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

    // ���� ���� ���� �Լ�
    void IsPause()
    {
        if (input::IsKeyDown(27))
        {
            LoadData::soundManager->PlayMusic(Music::eSoundList::click, Music::eSoundChannel::Effect1);
            // �Ͻ����� ���¸� ������Ŵ
            isPaused = !isPaused;
        }
    }

    void RenderPause()
    {
        LoadData::imageManager->DrawPngImage("�Ͻ�����", 667, 240, 600, 600, true);
    }

    void DrawMenuButton()
    {
        menuButton.DrawButton();
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