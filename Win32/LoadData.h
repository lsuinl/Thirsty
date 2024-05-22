#pragma once
#include "SoundManager.h"
#include "ImageManager.h"
#include "Animator.h"
namespace LoadData
{
	extern Music::SoundManager* soundManager;
	void LoadMusic();

	extern Images::ImageManager* imageManager;
	void LoadImages();

	extern Animator* AniManager;
	void LoadAni();

	void LoadAnimation();
};
