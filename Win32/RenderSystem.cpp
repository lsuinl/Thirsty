#include "WinApp.h"
#include "RenderSystem.h"
#include <string>
#include <Windows.h>

#pragma comment(lib, "msimg32.lib")

namespace render
{
    HWND hWnd;

    HDC frontMemDC;    // 앞면 DC
    HDC backMemDC;     // 뒷면 DC

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
        // 폰트 추가 생성
        AddFontResource(TEXT("resource//font//BlackHanSans-Regular.ttf"));
        HFONT currentFont = CreateFont(fontsize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Black Han Sans"));
        // 백 버퍼에 텍스트 그리기
        HFONT oldFont = (HFONT)SelectObject(backMemDC, currentFont);
        SetTextColor(backMemDC, color);
        SetBkMode(backMemDC, TRANSPARENT); // 배경을 투명으로 설정


        int currentX = x;
        int currentY = y;

        // 문자열 출력
        for (size_t i = 0; i < wcslen(text); ++i)
        {
            wchar_t ch = text[i];
            if (currentX >= 1500)
            {
                currentX = x; // x 위치 초기화
                currentY += 50; // y 위치 증가
            }

            TextOutW(backMemDC, currentX, currentY, &ch, 1);
            currentX += GetTextWidth(backMemDC, &ch, 1); // 문자 폭만큼 x 증가
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
        HDC bitmapMemDC = CreateCompatibleDC(frontMemDC);

        HBITMAP hOldBitmap = (HBITMAP)SelectObject(bitmapMemDC, hBitmap);

        BITMAP bm;
        GetObject(hBitmap, sizeof(BITMAP), &bm);

        HWND hWnd = global::GetWinApp().GetWindow();
        // 윈도우의 크기를 얻음
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        int windowWidth = clientRect.right - clientRect.left;
        int windowHeight = clientRect.bottom - clientRect.top;

        ::BitBlt(backMemDC, x, y, windowWidth, windowHeight, bitmapMemDC, 0, 0, SRCCOPY);

        SelectObject(bitmapMemDC, hOldBitmap);  // 이전 비트맵 복원
        DeleteObject(hBitmap);  // 비트맵 해제
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
        render::DrawBitmap(x, y, hBackmap);
        render::ReleaseImage(hBackmap);
        return hBackmap;
    }

    void DrawObject(std::wstring name, int width, int height, int x, int y, bool to, float alpha)
    {
        Gdiplus::Graphics g(backMemDC);
        Image* image = Image::FromFile(name.c_str());
        // 투명화 시킬 픽셀의 색 범위
        Gdiplus::Color _alpha_Color(0, 0, 0, 0);
        Gdiplus::ImageAttributes imgAtt;
        Gdiplus::ColorMatrix colorMatrix = {
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, alpha, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f
        };

        imgAtt.SetColorMatrix(&colorMatrix);
        imgAtt.SetColorKey(_alpha_Color, _alpha_Color);
        //크기 조정
        Gdiplus::Rect destRect(x, y, width, height); // 화면에 그릴 영역   
        // 원본 이미지의 크기를 가져옵니다.
        g.DrawImage(image, destRect, 0, 0, image->GetWidth(), image->GetHeight(), Gdiplus::UnitPixel, &imgAtt);

        delete image; // 이미지 객체 삭제
    }

}