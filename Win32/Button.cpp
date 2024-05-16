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
    bool Button::CheckClick(int dx, int dy)
    {
        if (dx >= x && dx <= x + width && dy >= y && dy <= y + height) 
        {
            return true;
        }
        return false;
    }
    void Button::PlayFunction() 
    {
        this->onClickFunction();
    }


    DragDrop::DragDrop(const char* name, int x, int y, int width, int height, const char* image, std::function<void()> onClick)
    {
        this->name = name;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->image = image;
        this->onClickFunction = onClick;
        this->originX = x;
        this->originY = y;
        isDragging = false;
    }
    void DragDrop::DrawButton()
    {
        render::DrawBackGround(image, width, height, x, y, true);
    }

    bool DragDrop::CheckDrag(int dx, int dy)
    {
        if (dx >= x && dx <= x + width && dy >= y && dy <= y + height)
        {
            return true;
        }
        return false;
    }
    void DragDrop::PlayFunction()
    {
        this->onClickFunction();
    }
    void DragDrop::setPos(int dx, int dy)
    {
        this->x = dx;
        this->y = dy;
    }
    const int DragDrop::getXPos() { return this->x; }
    const int DragDrop::getYPos() { return this->y; }
}