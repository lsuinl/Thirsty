#include "FadeinFadeout.h"

namespace fadeinfadeout
{
	float alpha;
	float fifo_timer = 0;

	void SetFadeIn()
	{
		alpha = 0.0f;
	}

	void SetFadeOut()
	{
		alpha = 1.0f;
	}

	void FadeInUpdate()
	{
		fifo_timer += TimeSystem::GetDeltaTime();

		if (fifo_timer > 100)
		{
			if (alpha < 1.0f)
				alpha += 0.1f;
			fifo_timer -= 100;
		}
	}

	void FadeOutUpdate()
	{
		fifo_timer += TimeSystem::GetDeltaTime();

		if (fifo_timer > 100)
		{
			if (alpha > 0.0f)
				alpha -= 0.1f;
			fifo_timer -= 100;
		}
	}

	void RenderFadeIn(const char* name)
	{
		LoadData::imageManager->DrawPngImage(name, 0, 0, 1935, 1080, alpha, false);
	}
	
	void RenderFadeOut()
	{
		LoadData::imageManager->DrawPngImage("페이드아웃", 0, 0, 1935, 1080, alpha,false);
	}

}