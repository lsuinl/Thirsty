#include "EndingCredit.h"

namespace end
{
	float end_timer = 0;
	int i = 0;

	bool end::SetCredit()
	{
	}

	void end::EndingCredit()
	{
		while (end_timer > 1000 || i >= -6035)
		{
			end_timer += TimeSystem::GetDeltaTime();
			i--;
			end_timer -= 1000;
		}

		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, i, false);
	}
}
