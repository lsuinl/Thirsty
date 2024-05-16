#pragma once

namespace input
{
    // 키 코드 입력됐냐?
    bool IsKeyCode();

    // SET 키 코드
    void SetKeyCode(bool type);

    void InitInput();

    void ResetInput();

    void KeyDown(unsigned int key);

    void KeyUp(unsigned int key);

    bool IsKeyDown(unsigned int key);

    bool IsKeyUp(unsigned int key);

    bool IsKey(unsigned int key);

    void InitMouse();

    struct MouseState
    {
        MouseState()
        {
            x = 0;
            y = 0;
            wheel = 0;
            left = false;
            right = false;
            middle = false;
            isDragging = false;
        }

        int x;
        int y;
        int wheel;
        bool left;
        bool right;
        bool middle;
        bool isDragging;
    };

    void UpdateMouse();

    bool IsSame(const MouseState& a, const MouseState& b);

    const MouseState& GetMouseState();
    const MouseState& GetPrevMouseState();

}