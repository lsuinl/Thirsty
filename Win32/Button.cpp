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

    void DragDrop::DrawDeco()
    {
        if (nameTag == 7)
        {
            LoadData::imageManager->DrawPngImage("∞°æ≤ø¿∫ŒΩ√", x, y-20, 220, 220, 1.0f, true);
        }
        else if (nameTag == 8)
        {
            LoadData::imageManager->DrawPngImage("π›¥ﬁæÓπ¨", x, y, 200, 150, 1.0f, true);
        }
        else if (nameTag == 9)
        {
            LoadData::imageManager->DrawPngImage("∆¢±Ë∞°∑Á", x, y, 220, 150, 1.0f, true);
        }
        else if (nameTag == 11)
        {
            LoadData::imageManager->DrawPngImage("«•∞Ìπˆº∏", x, y, 180, 180, 1.0f, true);
        }
        else if (nameTag == 12)
        {
            LoadData::imageManager->DrawPngImage("¡˜»≠∞Ì±‚", x, y, 250, 150, 1.0f, true);
        }
        else if (nameTag == 13)
        {
            LoadData::imageManager->DrawPngImage("Ω„¿Ø∫Œ", x, y, 200, 200, 1.0f, true);
        }
        else if (nameTag == 14)
        {
            LoadData::imageManager->DrawPngImage("æ¶∞´", x, y, 200, 180, 1.0f, true);
        }
        else if (nameTag == 15)
        {
            LoadData::imageManager->DrawPngImage("Ω„±Ë(±Ë√§)", x, y, 200, 150, 1.0f, true);
        }
        else if (nameTag == 16)
        {
            LoadData::imageManager->DrawPngImage("≥≥¿€æÓπ¨", x, y+20, 250, 120, 1.0f, true);
        }
        else if (nameTag == 17)
        {
            LoadData::imageManager->DrawPngImage("ªıøÏ∆¢±Ë", x, y, 300, 200, 1.0f, true);
        }
        else if (nameTag == 18)
        {
            LoadData::imageManager->DrawPngImage("Ω„¥Î∆ƒ", x, y, 250, 150, 1.0f, true);
        }
        else if (nameTag == 19)
        {
            LoadData::imageManager->DrawPngImage("Ω„√ªæÁ∞Ì√ﬂ", x+15, y, 150, 150, 1.0f, true);
        }
    }

    void DragDrop::DrawPick()
    {
        if (nameTag == 7)
        {
            LoadData::imageManager->DrawPngImage("∞°æ≤ø¿∫ŒΩ√", x, y, 110, 110, 1.0f, true);
        }
        else if (nameTag == 8)
        {
            LoadData::imageManager->DrawPngImage("π›¥ﬁæÓπ¨", x, y, 100, 75, 1.0f, true);
        }
        else if (nameTag == 9)
        {
            LoadData::imageManager->DrawPngImage("∆¢±Ë∞°∑Á", x, y, 110, 75, 1.0f, true);
        }
        else if (nameTag == 11)
        {
            LoadData::imageManager->DrawPngImage("«•∞Ìπˆº∏", x, y, 90, 90, 1.0f, true);
        }
        else if (nameTag == 12)
        {
            LoadData::imageManager->DrawPngImage("¡˜»≠∞Ì±‚", x, y, 125, 75, 1.0f, true);
        }
        else if (nameTag == 13)
        {
            LoadData::imageManager->DrawPngImage("Ω„¿Ø∫Œ", x, y, 100, 100, 1.0f, true);
        }
        else if (nameTag == 14)
        {
            LoadData::imageManager->DrawPngImage("æ¶∞´", x, y, 100, 90, 1.0f, true);
        }
        else if (nameTag == 15)
        {
            LoadData::imageManager->DrawPngImage("Ω„±Ë(±Ë√§)", x, y, 100, 75, 1.0f, true);
        }
        else if (nameTag == 16)
        {
            LoadData::imageManager->DrawPngImage("≥≥¿€æÓπ¨", x, y, 125, 60, 1.0f, true);
        }
        else if (nameTag == 17)
        {
            LoadData::imageManager->DrawPngImage("ªıøÏ∆¢±Ë", x, y, 150, 100, 1.0f, true);
        }
        else if (nameTag == 18)
        {
            LoadData::imageManager->DrawPngImage("Ω„¥Î∆ƒ", x, y, 125, 75, 1.0f, true);
        }
        else if (nameTag == 19)
        {
            LoadData::imageManager->DrawPngImage("Ω„√ªæÁ∞Ì√ﬂ", x, y, 75, 75, 1.0f, true);
        }
    }
}