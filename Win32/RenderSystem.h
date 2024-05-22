#pragma once
#include "GlobalHeader.h"

namespace render
{
    void InitRender();

    void BeginDraw();

    void EndDraw();

    void ReleaseRender();

    void DrawLine(int x1, int y1, int x2, int y2, COLORREF color);

    void DrawRect(int x, int y, int width, int height, COLORREF color);

    void DrawTextF(int x, int y, const wchar_t* text, COLORREF color, int fontsize);

    int GetTextWidth(HDC hdc, const wchar_t* text, int length);

    void DrawFont(int x, int y, const char* text, COLORREF color, int fontSize, const wchar_t* fontName, int fontStyle);

    void DrawBitmap(int x, int y, HBITMAP hBitmap);

    HBITMAP LoadImages(const char* path, int width, int height);

    void ReleaseImage(HBITMAP hBitmap);
    HBITMAP DrawBackGround(const char* name, int width, int height, int x, int y, bool to);
    
   void DrawObjects(Gdiplus::Image* name, int width, int height, int x, int y, float alpha = 1.0f, bool to=true);
   void DrawObject(const WCHAR* name, int width, int height, int x, int y, float alpha = 1.0f, bool to=true);
}