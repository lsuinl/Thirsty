#pragma once
#include "InputSystem.h"
#include "RenderSystem.h"
#include "Windows.h"
#include "Button.h"
#include "ScreenSystem.h"

namespace pause
{
    void ReStart();
    void ReTitle();

    bool GetIsPause();

    // ������ �Ͻ������ϰų� �簳�ϴ� �Լ�
    void IsPause();

    void RenderPause();

    void CaptureScreen();

    void DrawReButton();

    void IsCheckReButton(int x, int y);

}