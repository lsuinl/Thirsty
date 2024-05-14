

#pragma once
#include "GlobalHeader.h"
namespace button {
    class Button {
        const char* name;
        int x, y; 
        const char* image;
        std::function<void()> onClickFunction;
        
    public:
        int width;
        int height;
        Button(const char* name, int x, int y, int width, int height, const char*, std::function<void()> function);
        void DrawButton();
        bool CheckClick(int dx, int dy);
        void PlayFunction();
    };
    class DragDrop {
        const char* name;
        int originX, originY;
        int x, y;
        const char* image;
        std::function<void()> onClickFunction;

    public:
        int width;
        int height;
        bool isDragging = false;
        DragDrop(const char* name, int x, int y, int width, int height, const char*, std::function<void()> function);
        void DrawButton();
        bool CheckDrag(int dx, int dy);
        void PlayFunction();
        void setPos(int dx, int dy);
        const int getXPos();
        const int getYPos();
    };

}

