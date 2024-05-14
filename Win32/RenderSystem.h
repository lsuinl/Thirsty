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

    void DrawCircle(int x, int y, int radius, COLORREF color);

    void DrawPolygon(POINT points[], int count, COLORREF color);

    void DrawTextF(int x, int y, const char* text, COLORREF color, int fontsize);

    void DrawFont(int x, int y, const char* text, COLORREF color, int fontSize, const wchar_t* fontName, int fontStyle);
    //��������
    void DrawBitmap(int x, int y, HBITMAP hBitmap);
    void DrawBitmapTo(int x, int y, HBITMAP hBitmap);

    void ArrowDraw();

    HBITMAP LoadImages(const char* path, int width, int height);

    void ReleaseImage(HBITMAP hBitmap);
    HBITMAP DrawBackGround(const char* name, int width, int height, int x, int y, bool to);
    void DrawObject(std::wstring name, int width, int height, int x, int y, bool to, float alpha = 1.0f);
}


/*
����ڽ� �׸��� ��ɾ�
render::DrawObject(L"resource\\object\\rect.png", 1000, 500, 483, 500, true, 0.8f);
render::DrawTextF(550, 700, "�ȳ��ϼ��� ����� �Դϴ�.", RGB(255, 255, 255), 30);
*/