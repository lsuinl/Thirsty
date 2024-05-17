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

    // 게임을 일시정지하거나 재개하는 함수
    void IsPause();

    void RenderPause();

    void CaptureScreen();

    void DrawReButton();

    void IsCheckReButton(int x, int y);

}