

#pragma once
#include "GlobalHeader.h"
namespace button {
    class Button {
        const char* name;
        int x, y;
        std::function<void()> onClickFunction;

    public:
        int width;
        int height;
        Button(const char* name, int x, int y, int width, int height, std::function<void()> function);
        void DrawButton();
        bool CheckClick(int dx, int dy);
        void PlayFunction();
    };
    class DragDrop {
        int originX, originY;
        int x, y;
        std::function<void()> onClickFunction;

    public:
        const char* name;
        int width;
        int height;
        bool isDragging = false;
        DragDrop();
        ~DragDrop();
        DragDrop(const char* name, int x, int y, int width, int height, std::function<void()> function);
        void DrawButton();
        bool CheckDrag(int dx, int dy);
        void PlayFunction();
        void setPos(int dx, int dy);
        bool CheckRightClick(int x, int y);
        void Reset();
        const int getXPos();
        const int getYPos();
        const int getOriginX();
        const int getOriginY();
    };

}

