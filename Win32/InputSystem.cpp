#include "WinApp.h"
#include "InputSystem.h"
#include "Button.h"

namespace input
{
    bool isKeyDown[256];
    bool isKeyUp[256];
    bool isKey[256];

    bool isKeyCode = false;

    MouseState curMouse;
    MouseState prevMouse;

    bool IsKeyCode()
    {
        return isKeyCode;
    }

    void SetKeyCode(bool type)
    {
        isKeyCode = type;
    }

    void ResetInput()
    {
        for (int i = 0; i < 256; i++)
        {
            isKeyDown[i] = false;
            isKeyUp[i] = false;
        }
    }

    void KeyDown(unsigned int key)
    {
        isKeyDown[key] = true;
        isKey[key] = true;
    }

    void KeyUp(unsigned int key)
    {
        isKeyUp[key] = true;
        isKey[key] = false;
    }

    bool IsKeyDown(unsigned int key)
    {
        return isKeyDown[key];
    }

    bool IsKeyUp(unsigned int key)
    {
        return isKeyUp[key];
    }

    bool IsKey(unsigned int key)
    {
        return isKey[key];
    }

    void InitMouse()
    {
        curMouse.x = global::GetWinApp().GetWidth() / 2;
        curMouse.y = global::GetWinApp().GetHeight() / 2;
        curMouse.wheel = 0;

        curMouse.left = false;
        curMouse.right = false;
        curMouse.middle = false;

        prevMouse = curMouse;

        SetCursorPos(curMouse.x, curMouse.y);
    }

    void UpdateMouse()
    {
        prevMouse = curMouse;

        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(global::GetWinApp().GetWindow(), &pt);

        curMouse.x = pt.x;
        curMouse.y = pt.y;
        curMouse.wheel = 0;

        curMouse.left = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
        curMouse.right = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
        curMouse.middle = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0;

        curMouse.isDragging = (GetKeyState(VK_LBUTTON) & 0x8001) != 0;
        curMouse.isDragging = (GetKeyState(VK_LBUTTON) & 0x0001) == 0;

    }

    const MouseState& GetMouseState()
    {
        return curMouse;
    }

    const MouseState& GetPrevMouseState()
    {
        return prevMouse;
    }

    void InitInput()
    {
        for (int i = 0; i < 256; i++)
        {
            isKeyDown[i] = false;
            isKeyUp[i] = false;
            isKey[i] = false;
        }

        InitMouse();
    }

    bool IsSame(const MouseState& a, const MouseState& b)
    {
        return a.x == b.x && a.y == b.y && a.wheel == b.wheel && a.left == b.left && a.right == b.right && a.middle == b.middle;
    }

}