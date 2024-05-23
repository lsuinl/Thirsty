

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
        float originWidth, originHeight;
        int x, y;
        std::function<void()> onClickFunction;

    public:
        int nameTag = 31;
        const char* name;
        float width;
        float height;
        bool isDragging = false;//�巡�� �ǰ� �ִ� ��ü�� �����ÿ� ��ġ�� ��ǥ�� ��ü�鿡 ������ ���� �ʵ��� �߰��� ��.
        bool isShowing = true;  // �̹����� ���̰� �ִ���
        bool canClick = true;
        DragDrop();
        ~DragDrop();
        DragDrop(int nameTag, const char* name, int x, int y, float width, float height, std::function<void()> function);
        DragDrop(int nameTag, int x, int y, std::function<void()> onClick);
        void DrawButton();
        bool CheckDrag(int dx, int dy);
        void PlayFunction();
        void setPos(int dx, int dy);
        void setYPos(int n);
        void setSize(float w, float h);
        bool CheckRightClick(int x, int y);
        bool CheckClick(int dx, int dy);
        void SetImage(int width, int height);
        const int getXPos();
        const int getYPos();
        const int getOriginX();
        const int getOriginY();
        float getOriginWidth();
        float getOriginHeight();
        void DrawDeco();
    };

}

