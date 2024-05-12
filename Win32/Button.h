#include "WinApp.h"
#include <functional> 

#pragma once
namespace button {
    class Button {
        const char* name;
        int x, y;
        int width, height;
        const char* image;
        std::function<void()> onClickFunction;
    public:
        Button(const char* name, int x, int y, int width, int height, const char*, std::function<void()> function);
        void DrawButton();
        void CheckClick(int dx, int dy);
    };

}

