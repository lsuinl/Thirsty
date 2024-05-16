#pragma once
#include "GlobalHeader.h"
namespace render
{
    enum class BitMap
    {
        BGM,
        Effect,
        Size
    };
    enum class Png
    {
        BGM,
        Effect,
        Size
    };

    class ImageManager;  // 클래스 전방 선언

    class ImageManager final
    {
    public:
        static ImageManager* GetInstance();
        static void DestroyInstance();

        //static LoadImages();

        //그리기..는 따로..
       // void PlayMusic(eSoundList list, eSoundChannel channel);

    private:
        ImageManager();
        ~ImageManager();

    private:
        static ImageManager* mInstance;

       //FMOD::System* mSystem;
        //FMOD::Channel* mChannel[static_cast<int>(eSoundChannel::Size)];
        //FMOD::Sound* mSoundList[static_cast<int>(eSoundList::Size)];
        float mVolume;
    };
    //----------------------
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
    void DrawObject(std::wstring name, int width, int height, int x, int y, bool to, float alpha = 1.0f);
}


/*
투명박스 그리는 명령어
render::DrawObject(L"resource\\object\\rect.png", 1000, 500, 483, 500, true, 0.8f);
render::DrawTextF(550, 700, "안녕하세요 김수인 입니다.", RGB(255, 255, 255), 30);
*/