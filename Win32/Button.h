#pragma once
namespace button {
    class Button {
        const char* name;
        int x, y;
        int width, height;
        const char* image;
    public:
        Button(const char* name, int x, int y, int width, int height, const char*);
        void DrawButton();
        void CheckClick(int dx, int dy);
    };

}

