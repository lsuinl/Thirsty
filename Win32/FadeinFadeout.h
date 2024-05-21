#pragma once
#include "RenderSystem.h"
#include "LoadData.h"
#include "TimeSystem.h"

namespace fadeinfadeout
{
	void SetFadeIn();
	void SetFadeOut();
	void FadeInUpdate();
	void FadeOutUpdate();
	void RenderFadeIn(const char* name);
	void RenderFadeOut();
}