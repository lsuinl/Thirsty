#pragma once
#include "SoundManager.h"
#include "ImageManager.h"

namespace LoadData
{
	extern Music::SoundManager* soundManager;
	void LoadMusic();

	extern Images::ImageManager* imageManager;
	void LoadImages();

	void LoadAnimation();
};
