#include <atlstr.h>
#include "ImageManager.h"
namespace Images {

    ImageManager* ImageManager::mInstance = nullptr;

    ImageManager* ImageManager::GetInstance()
    {
        if (mInstance == nullptr)
        {
            mInstance = new ImageManager();
        }

        return mInstance;
    }

    void ImageManager::DestroyInstance()
    {
        delete mInstance;
        mInstance = nullptr;
    }

    void ImageManager::LoadBitMapImages(std::string name, const char* path, int width, int height)
    {
        mBitMapList[name] = (HBITMAP)LoadImageA(NULL, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    }

    void ImageManager::DrawBitMapImage(std::string name, int x, int y)
    {
        render::DrawBitmap(x, y, mBitMapList.find(name)->second);
    }

    void ImageManager::LoadPngImages(std::string name, const WCHAR* path)
    {
        mImageList[name] = Image::FromFile(path);
    }

    void ImageManager::DrawPngImage(std::string name, int x, int y, int width, int height, float alpha)
    {
        render::DrawObjects(mImageList.find(name)->second, width, height, x, y, true, alpha);
    }

    ImageManager::ImageManager()
    {
    }

    ImageManager::~ImageManager()
    {
        for (auto& pair : mBitMapList) {
            DeleteObject(pair.second);
        }
        for (auto& pair : mImageList) {
            delete pair.second;
        }
    }
}