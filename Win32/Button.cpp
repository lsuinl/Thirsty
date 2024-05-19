#include "Button.h"
#include "RenderSystem.h"
#include "GameManager.h"
#include "LoadData.h"

namespace button {

    Button::Button(const char* name, int x, int y, int width, int height, std::function<void()> onClick)
    {
        this->name = name;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->onClickFunction = onClick;
    }
    void Button::DrawButton()
    {
        LoadData::imageManager->DrawPngImage(name, x, y, width, height, 1.0f);
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

    DragDrop::DragDrop()
    {

    }
    DragDrop::~DragDrop() {}

    bool DragDrop::CheckRightClick(int x, int y)
    {
        const input::MouseState& mouse = input::GetMouseState();
        if (mouse.right && x >= this->x && x <= (this->x + this->width) &&
            y >= this->y && y <= (this->y + this->height)) {
            return true;
        }
        return false;
    }

    void DragDrop::Reset()
    {
        // DragDrop 객체를 초기 상태로 재설정
        this->name = "바구니";
        this->setPos(this->originX, this->originY);
        this->width = 150;
        this->height = 100;
        this->isDragging = false;
    }

    DragDrop::DragDrop(const char* name, int x, int y, int width, int height, std::function<void()> onClick)
    {
        this->name = name;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->onClickFunction = onClick;
        this->originX = x;
        this->originY = y;
        isDragging = false;
    }
    void DragDrop::DrawButton()
    {
        LoadData::imageManager->DrawPngImage(name, x, y, width, height, 1.0f);
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
    const int DragDrop::getOriginX() { return this->originX; }
    const int DragDrop::getOriginY() { return this->originY; }
}