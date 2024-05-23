

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
        void SetSize(int x, int y, int width, int height);
    };
    class DragDrop {
        int originX, originY;
        int x, y;
        std::function<void()> onClickFunction;

    public:
        int nameTag = 31;
        const char* name;
        int width;
        int height;
        bool isDragging = false;//드래그 되고 있는 객체가 있을시에 겹치는 좌표의 객체들에 영향을 받지 않도록 추가된 값.
        bool isShowing = true;  // 이미지가 보이고 있는지
        bool canClick = true;
        DragDrop();
        ~DragDrop();
        DragDrop(int nameTag, const char* name, int x, int y, int width, int height, std::function<void()> function);
        void DrawButton();
        bool CheckDrag(int dx, int dy);
        void PlayFunction();
        void setPos(int dx, int dy);
        void setYPos(int n);
        void setSize(int w, int h);
        bool CheckRightClick(int x, int y);
        bool CheckClick(int dx, int dy);
        void Reset();
        const int getXPos();
        const int getYPos();
        const int getOriginX();
        const int getOriginY();
        void DrawDeco();
    };

}

