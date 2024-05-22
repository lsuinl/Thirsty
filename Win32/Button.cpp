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
        // DragDrop ∞¥√º∏¶ √ ±‚ ªÛ≈¬∑Œ ¿Áº≥¡§
        this->name = "πŸ±∏¥œ";
        this->setPos(this->originX, this->originY);
        this->width = 150;
        this->height = 100;
        this->isDragging = false;
    }

    DragDrop::DragDrop(int nameTag, const char* name, int x, int y, int width, int height, std::function<void()> onClick)
    {
        this->nameTag = nameTag;
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
    void DragDrop::setYPos(int n)
    {
        this->y = originY - (n * 150);
    }
    void DragDrop::setSize(int w, int h)
    {
        this->width = w;
        this->height = h;
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

    void DragDrop::DrawDeco()
    {
        if (nameTag == 7)
        {
            LoadData::imageManager->DrawPngImage("∞°æ≤ø¿∫ŒΩ√", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 8)
        {
            LoadData::imageManager->DrawPngImage("π›¥ﬁæÓπ¨", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 9)
        {
            LoadData::imageManager->DrawPngImage("∆¢±Ë∞°∑Á", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 10)
        {
            LoadData::imageManager->DrawPngImage("¥Î∆ƒ", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 11)
        {
            LoadData::imageManager->DrawPngImage("«•∞Ìπˆº∏", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 12)
        {
            LoadData::imageManager->DrawPngImage("¡˜»≠∞Ì±‚", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 13)
        {
            LoadData::imageManager->DrawPngImage("Ω„¿Ø∫Œ", x, y, width, height, 1.0f, true);
        }
        else if (nameTag == 14)
        {
            LoadData::imageManager->DrawPngImage("æ¶∞´", x, y, width, height, 1.0f, true);

        }
        else if (nameTag == 15)
        {
            LoadData::imageManager->DrawPngImage("Ω„±Ë(±Ë√§)", x, y, width, height, 1.0f, true);

        }
        else if (nameTag == 16)
        {
            LoadData::imageManager->DrawPngImage("≥≥¿€æÓπ¨", x, y, width, height, 1.0f, true);

        }
        else if (nameTag == 17)
        {
            LoadData::imageManager->DrawPngImage("ªıøÏ∆¢±Ë", x, y, width, height, 1.0f, true);

        }
        else if (nameTag == 18)
        {
            LoadData::imageManager->DrawPngImage("Ω„¥Î∆ƒ", x, y, width, height, 1.0f, true);

        }
        else if (nameTag == 19)
        {
            LoadData::imageManager->DrawPngImage("Ω„√ªæÁ∞Ì√ﬂ", x, y, width, height, 1.0f, true);

        }      
    }  
}