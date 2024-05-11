#include "Button.h"
#include "RenderSystem.h"
#include "GameManager.h"
namespace button {

    Button::Button(const char* name,int x, int y, int width, int height,const char* image, std::function<void()> onClick)
    {
        this->name = name;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->image = image;
        this->onClickFunction = onClick;
    }

    void Button::DrawButton() 
    {
        render::DrawBackGround(image, width, height, x, y, true);
    }

    void Button::CheckClick(int dx, int dy)
    {
        if (dx >= x && dx <= x + width && dy >= y && dy <= y + height) 
        {
            this->onClickFunction();
        }
    }
}