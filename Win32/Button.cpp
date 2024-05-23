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
        LoadData::imageManager->DrawPngImage(name, x, y, width, height, 1.0f, true);
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
        LoadData::soundManager->PlayMusic(Music::eSoundList::click, Music::eSoundChannel::Effect);
    }
    void Button::SetSize(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
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

    void DragDrop::SetImage(int _width, int _height)
    {
        this->width = originWidth * _width;
        this->height = originHeight * _height;
    }

    DragDrop::DragDrop(int nameTag, const char* name, int x, int y, float width, float height, std::function<void()> onClick)
    {
        this->nameTag = nameTag;
        this->name = name;
        this->x = x;
        this->y = y;
        this->originX = x;
        this->originY = y;
        this->width = width;
        this->height = height;       
        this->originWidth = width;
        this->originHeight = height;
        this->onClickFunction = onClick;
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
    void DragDrop::setYPos(int n)
    {
        this->y = originY - (n * 150);
    }
    void DragDrop::setYXPos(int n,int m)
    {
        this->y -= n;
        this->x -= m;
    }
    void DragDrop::setSize(float w, float h)
    {
        this->originWidth = w;
        this->originHeight = h;
    }

    bool DragDrop::CheckClick(int dx, int dy)
    {
        if (dx >= x && dx <= x + width && dy >= y && dy <= y + height)
        {
            return true;
        }
        return false;
    }

    const int DragDrop::getXPos() { return this->x; }
    const int DragDrop::getYPos() { return this->y; }
    const int DragDrop::getOriginX() { return this->originX; }
    const int DragDrop::getOriginY() { return this->originY; }
    float DragDrop::getOriginWidth() { return this->originWidth; }
    float DragDrop::getOriginHeight() { return this->originHeight; }

    DragDrop::DragDrop(int nameTag, int x, int y, std::function<void()> onClick)
    {
        this->nameTag = nameTag;      
        this->x = x;
        this->y = y;
        this->originX = x;
        this->originY = y;
        this->onClickFunction = onClick;
        isDragging = false;
        if (this->nameTag == 7)
        {
            this->name = "°¡¾²¿ÀºÎ½Ã";
            this->width = 22;
            this->height = 22;
            this->originWidth = 22;
            this->originHeight = 22;
        }
        else if (this->nameTag == 8)
        {
            this->name = "¹Ý´Þ¾î¹¬";
            this->width = 20;
            this->height = 15;
            this->originWidth = 20;
            this->originHeight = 15;
        }
        else if (this->nameTag == 9)
        {
            this->name = "Æ¢±è°¡·ç";
            this->width = 22;
            this->height = 15;
            this->originWidth = 22;
            this->originHeight = 15;
        }
        else if (this->nameTag == 11)
        {
            this->name = "Ç¥°í¹ö¼¸";
            this->width = 18;
            this->height = 18;
            this->originWidth = 18;
            this->originHeight = 18;
        }
        else if (this->nameTag == 12)
        {
            this->name = "Á÷È­°í±â";
            this->width = 25;
            this->height = 15;
            this->originWidth = 25;
            this->originHeight = 15;
        }
        else if (this->nameTag == 13)
        {
            this->name = "½ãÀ¯ºÎ";
            this->width = 20;
            this->height = 20;
            this->originWidth = 20;
            this->originHeight = 20;
        }
        else if (this->nameTag == 14)
        {
            this->name = "¾¦°«";
            this->width = 20;
            this->height = 18;
            this->originWidth = 20;
            this->originHeight = 18;

        }
        else if (this->nameTag == 15)
        {
            this->name = "½ã±è(±èÃ¤)";
            this->width = 20;
            this->height = 15;
            this->originWidth = 20;
            this->originHeight = 15;

        }
        else if (this->nameTag == 16)
        {
            this->name = "³³ÀÛ¾î¹¬";
            this->width = 25;
            this->height = 12;
            this->originWidth = 25;
            this->originHeight = 12;

        }
        else if (this->nameTag == 17)
        {
            this->name = "»õ¿ìÆ¢±è";
            this->width = 30;
            this->height = 20;
            this->originWidth = 30;
            this->originHeight = 20; 

        }
        else if (this->nameTag == 18)
        {
            this->name = "½ã´ëÆÄ";
            this->width = 20;
            this->height = 10;
            this->originWidth = 20;
            this->originHeight = 10; 

        }
        else if (this->nameTag == 19)
        {
            this->name = "½ãÃ»¾ç°íÃß";
            this->width = 12;
            this->height = 12;
            this->originWidth = 12;
            this->originHeight = 12;

        }
    }
}