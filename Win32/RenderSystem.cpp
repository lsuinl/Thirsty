#include "WinApp.h"
#include "RenderSystem.h"
#include <string>
#include <Windows.h>

#pragma comment(lib, "msimg32.lib")

namespace render
{
    HWND hWnd;

    HDC frontMemDC;    // �ո� DC
    HDC backMemDC;     // �޸� DC

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


    void DrawCircle(int x, int y, int radius, COLORREF color)
    {
        HPEN hPen = CreatePen(PS_SOLID, 1, color);

        HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

        HBRUSH hBrush = CreateSolidBrush(color);

        HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

        Ellipse(backMemDC, x - radius, y - radius, x + radius, y + radius);

        SelectObject(backMemDC, hOldPen);
        SelectObject(backMemDC, hOldBrush);

        DeleteObject(hPen);
        DeleteObject(hBrush);

    }

    void DrawPolygon(POINT points[], int count, COLORREF color)
    {
        HPEN hPen = CreatePen(PS_SOLID, 1, color);

        HPEN hOldPen = (HPEN)SelectObject(backMemDC, hPen);

        HBRUSH hBrush = CreateSolidBrush(color);

        HBRUSH hOldBrush = (HBRUSH)SelectObject(backMemDC, hBrush);

        Polygon(backMemDC, points, count);

        SelectObject(backMemDC, hOldPen);
        SelectObject(backMemDC, hOldBrush);

        DeleteObject(hPen);
        DeleteObject(hBrush);

    }

    void DrawTextF(int x, int y, const char* text, COLORREF color, int fontsize)
    {
        // ��Ʈ �߰� ����
        AddFontResource(TEXT("resource//font//BlackHanSans-Regular.ttf"));
        HFONT currentFont = CreateFont(fontsize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Black Han Sans"));

        // �� ���ۿ� �ؽ�Ʈ �׸���
        HFONT oldFont = (HFONT)SelectObject(backMemDC, currentFont);
        SetTextColor(backMemDC, color);
        SetTextColor(backMemDC, color);
        SetBkMode(backMemDC, TRANSPARENT); // ����� �������� ����
        TextOutA(backMemDC, x, y, text, strlen(text));
        SelectObject(backMemDC, oldFont);
        SelectObject(backMemDC, oldFont);

        DeleteObject(currentFont);
    }

    void DrawBitmap(int x, int y, HBITMAP hBitmap)
    {
        HDC bitmapMemDC = CreateCompatibleDC(frontMemDC);

        HBITMAP hOldBitmap = (HBITMAP)SelectObject(bitmapMemDC, hBitmap);

        BITMAP bm;
        GetObject(hBitmap, sizeof(BITMAP), &bm);

        HWND hWnd = global::GetWinApp().GetWindow();
        // �������� ũ�⸦ ����
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        int windowWidth = clientRect.right - clientRect.left;
        int windowHeight = clientRect.bottom - clientRect.top;

        ::BitBlt(backMemDC, x, y, windowWidth, windowHeight, bitmapMemDC, 0, 0, SRCCOPY);

        SelectObject(bitmapMemDC, hOldBitmap);  // ���� ��Ʈ�� ����
        DeleteObject(hBitmap);  // ��Ʈ�� ����
        DeleteDC(bitmapMemDC);

    }
    void DrawBitmapTo(int x, int y, HBITMAP hBitmap)
    {
        HDC bitmapMemDC = CreateCompatibleDC(frontMemDC);

        HBITMAP hOldBitmap = (HBITMAP)SelectObject(bitmapMemDC, hBitmap);

        BITMAP bm;
        GetObject(hBitmap, sizeof(BITMAP), &bm);

        int imageWidth = bm.bmWidth;
        int imageHeight = bm.bmHeight;

        // DIB�� ���� ������ ������ BITMAPINFO ����ü ����
        BITMAPINFO bmi;
        ZeroMemory(&bmi, sizeof(BITMAPINFO));
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = imageWidth;
        bmi.bmiHeader.biHeight = -imageHeight;  // top-down DIB
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32;  // 32��Ʈ �÷� (RGB + Alpha)
        bmi.bmiHeader.biCompression = BI_RGB;

        // �̹����� �ȼ� �����͸� ������ �޸� ���� ����
        BYTE* pBits;
        HBITMAP hBitmap32 = CreateDIBSection(bitmapMemDC, &bmi, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);

        // �̹����� 32��Ʈ �������� ��ȯ�Ͽ� �޸� ���ۿ� ����
        HDC hdcTemp = CreateCompatibleDC(NULL);
        HBITMAP hOldBitmapTemp = (HBITMAP)SelectObject(hdcTemp, hBitmap32);
        BitBlt(hdcTemp, 0, 0, imageWidth, imageHeight, bitmapMemDC, 0, 0, SRCCOPY);
        SelectObject(hdcTemp, hOldBitmapTemp);
        DeleteDC(hdcTemp);

        // TransparentBlt �Լ��� ����Ͽ� �̹��� �׸���
        TransparentBlt(backMemDC, x, y, imageWidth, imageHeight, bitmapMemDC, 0, 0, imageWidth, imageHeight, RGB(255, 255, 255));

        // ����� ���ҽ� ����
        SelectObject(bitmapMemDC, hOldBitmap);
        DeleteObject(hBitmap32);
        DeleteDC(bitmapMemDC);
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
        if (to)
            render::DrawBitmapTo(x, y, hBackmap);
        else
            render::DrawBitmap(x, y, hBackmap);
        render::ReleaseImage(hBackmap);
        return hBackmap;
    }
}