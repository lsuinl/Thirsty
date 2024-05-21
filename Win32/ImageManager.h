#pragma once
#include <string>
#include <unordered_map>
#include "WinApp.h"

namespace Images
{
    class ImageManager final
    {
    public:
        static ImageManager* GetInstance();
        static void DestroyInstance();

        void LoadBitMapImages(std::string name, const char* path, int width, int height);
        void DrawBitMapImage(std::string name, int x, int y);
        void LoadPngImages(std::string name, const WCHAR* path);
        void DrawPngImage(std::string name, int x, int y, int width, int height, float alpha, bool to = true);

    private:
        ImageManager();
        ~ImageManager();
        static ImageManager* mInstance;

        std::unordered_map<std::string, HBITMAP> mBitMapList;
        std::unordered_map<std::string, Image*> mImageList;
    };
}