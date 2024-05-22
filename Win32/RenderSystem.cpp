#include "WinApp.h"
#include "RenderSystem.h"
#include <string>
#include <Windows.h>

#pragma comment(lib, "msimg32.lib")

namespace render
{
    HWND hWnd;

    HDC frontMemDC;
    HDC backMemDC;

    HBITMAP backBitmap = nullptr;

    void InitRender()
    {
        hWnd = global::GetWinApp().GetWindow();

        frontMemDC = GetDC(hWnd);

        backMemDC = CreateCompatibleDC(frontMemDC);

        backBitmap = CreateCompatibleBitmap(frontMemDC, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight());
    }

    void ClearScreen()
    {
        ::PatBlt(backMemDC, 0, 0, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight(), WHITENESS);
    }

    void BeginDraw()
    {
        ClearScreen();

        ::SelectObject(backMemDC, backBitmap);
    }

    void EndDraw()
    {
        ::BitBlt(frontMemDC, 0, 0, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight(), backMemDC, 0, 0, SRCCOPY);
    }

    void ReleaseRender()
    {
        DeleteObject(backBitmap);

        DeleteDC(backMemDC);

        ReleaseDC(hWnd, frontMemDC);
    }

    void DrawLine(int x1, int y1, int x2, int y2, COLORREF color)
    {
        HPEN hPen = CreatePen(PS_SOLID, 5, color);

        HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

        MoveToEx(backMemDC, x1, y1, NULL);

        LineTo(backMemDC, x2, y2);

        SelectObject(backMemDC, hOldPen);

        DeleteObject(hPen);
    }

    void DrawRect(int x, int y, int width, int height, COLORREF color)
    {
        HPEN hPen = CreatePen(PS_SOLID, 1, color);

        HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

        HBRUSH hBrush = CreateSolidBrush(color);

        HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

        Rectangle(backMemDC, x, y, x + width, y + height);

        SelectObject(backMemDC, hOldPen);
        SelectObject(backMemDC, hOldBrush);

        DeleteObject(hPen);
        DeleteObject(hBrush);
    }

    void DrawTextF(int x, int y, const wchar_t* text, COLORREF color, int fontsize)
    {
        AddFontResource(TEXT("resource//font//ChosunCentennial_ttf.ttf"));
        HFONT currentFont = CreateFont(fontsize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("조선100년체"));

        HFONT oldFont = (HFONT)SelectObject(backMemDC, currentFont);
        SetTextColor(backMemDC, color);
        SetBkMode(backMemDC, TRANSPARENT);

        int currentX = x;
        int currentY = y;

        for (size_t i = 0; i < wcslen(text); ++i)
        {
            wchar_t ch = text[i];
            if (currentX >= 1550)
            {
                currentX = x;
                currentY += 50;
            }

            TextOutW(backMemDC, currentX, currentY, &ch, 1);
            currentX += GetTextWidth(backMemDC, &ch, 1);
        }



        SelectObject(backMemDC, oldFont);
        DeleteObject(currentFont);
    }

    int GetTextWidth(HDC hdc, const wchar_t* text, int length)
    {
        SIZE size;
        GetTextExtentPoint32W(hdc, text, length, &size);
        return size.cx;
    }
    void DrawBitmap(int x, int y, HBITMAP hBitmap)
    {
        static HDC bitmapMemDC = CreateCompatibleDC(frontMemDC);

        HBITMAP hOldBitmap = (HBITMAP)SelectObject(bitmapMemDC, hBitmap);

        BITMAP bm;
        GetObject(hBitmap, sizeof(BITMAP), &bm);



        ::BitBlt(backMemDC, x, y, bm.bmWidth, bm.bmHeight, bitmapMemDC, 0, 0, SRCCOPY);

        SelectObject(bitmapMemDC, hOldBitmap);
    }

    HBITMAP LoadImages(const char* path, int width, int height)
    {
        HBITMAP hBitmap = (HBITMAP)LoadImageA(NULL, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        return hBitmap;
    }

    void ReleaseImage(HBITMAP hBitmap)
    {
        DeleteObject(hBitmap);
    }

    HBITMAP DrawBackGround(const char* name, int width, int height, int x, int y, bool to)
    {
        HBITMAP hBackmap = render::LoadImages(name, width, height);
        render::DrawBitmap(x, y, hBackmap);
        render::ReleaseImage(hBackmap);
        return hBackmap;
    }

    void DrawObjects(Image* name, int width, int height, int x, int y, float alpha, bool to)
    {
        static Gdiplus::Graphics g(backMemDC); // Graphics 객체를 정적으로 생성하여 재사용
        Gdiplus::Color _alpha_Color;
        if (to)
        {
            _alpha_Color = (0, 0, 0, 0);
        }
        else
        {
            _alpha_Color = (0, 255, 98, 32);
        }
        static Gdiplus::ImageAttributes imgAtt; // ImageAttributes 객체를 정적으로 생성하여 재사용
        Gdiplus::ColorMatrix colorMatrix = {
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, alpha, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f
        };
        g.SetSmoothingMode(SmoothingModeNone);
        g.SetPixelOffsetMode(PixelOffsetModeNone);
        g.SetInterpolationMode(InterpolationModeNearestNeighbor);
        imgAtt.SetColorMatrix(&colorMatrix);
        imgAtt.SetColorKey(_alpha_Color, _alpha_Color);
        Gdiplus::Rect destRect(x, y, width, height);
        g.DrawImage(name, destRect, 0, 0, name->GetWidth(), name->GetHeight(), Gdiplus::UnitPixel, &imgAtt);
    }


    void DrawObject(const WCHAR* name, int width, int height, int x, int y,float alpha, bool to)
    {
        Image* img = Image::FromFile(name);
        static Gdiplus::Graphics g(backMemDC); // Graphics 객체를 정적으로 생성하여 재사용
        Gdiplus::Color _alpha_Color(0, 0, 0, 0);
        static Gdiplus::ImageAttributes imgAtt; // ImageAttributes 객체를 정적으로 생성하여 재사용
        Gdiplus::ColorMatrix colorMatrix = {
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, alpha, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f
        };
        g.SetSmoothingMode(SmoothingModeNone);
        g.SetPixelOffsetMode(PixelOffsetModeNone);
        g.SetInterpolationMode(InterpolationModeNearestNeighbor);
        imgAtt.SetColorMatrix(&colorMatrix);
        imgAtt.SetColorKey(_alpha_Color, _alpha_Color);
        Gdiplus::Rect destRect(x, y, width, height);
        g.DrawImage(img, destRect, 0, 0, img->GetWidth(), img->GetHeight(), Gdiplus::UnitPixel, &imgAtt);
    }
}