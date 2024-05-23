#pragma once
#include "InputSystem.h"
#include "RenderSystem.h"
#include "Windows.h"
#include "Button.h"
#include "ScreenSystem.h"
#include "LoadData.h"

namespace pause
{
    void Menu();
    void ReStart();
    void ReTitle();

    bool GetIsPause();

    // ������ �Ͻ������ϰų� �簳�ϴ� �Լ�
    void IsPause();

    void RenderPause();

    void DrawMenuButton();

    void CaptureScreen();

    void DrawReButton();

    void IsButton(int x, int y);

    void IsMenuButton(int x, int y);
}