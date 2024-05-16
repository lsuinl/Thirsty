

#pragma once
#include "GlobalHeader.h"


namespace button {
    class Button {
        const char* name;
        int x, y;
        std::wstring image;
        std::function<void()> onClickFunction;

    public:
        int width;
        int height;
        Button(const char* name, int x, int y, int width, int height, std::wstring, std::function<void()> function);
        void DrawButton();
        bool CheckClick(int dx, int dy);
        void PlayFunction();
    };
    class DragDrop {
        int originX, originY;
        //std::wstring image;
        int x, y;
        std::function<void()> onClickFunction;


    public:
        std::wstring image;
        int num1 = 0;
        int name;
        int width;
        int height;
        bool isDragging = false;
        bool IsShowing = true;
        bool CanClick = true;
        DragDrop();
        ~DragDrop();
        DragDrop(int, int x, int y, int width, int height, std::wstring, std::function<void()> function);
        void DrawButton();
        bool CheckDrag(int dx, int dy);
        void PlayFunction();
        void setPos(int dx, int dy);
        bool CheckClick(int x, int y);
        void Reset();
        const int getXPos();
        const int getYPos();
        const int getOriginX();
        const int getOriginY();
    };
}

