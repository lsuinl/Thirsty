#include "Title.h"

namespace Title
{
	bool isExit = false;
	bool isStart = false;
	bool isTutorial = false;

	button::Button startButton = { "start", 1100, 600, 300, 100, "resource/object/start.bmp", StartButton };
	button::Button tutorialButton = { "tutorial", 1100, 750, 300, 100, "resource/object/tutorial.bmp", TutorialButton };


	void Title::TitleCheckClick(int x, int y)
	{
		if (startButton.CheckClick(x, y))
		{
			startButton.PlayFunction();
		}
		if (tutorialButton.CheckClick(x, y))
		{
			tutorialButton	.PlayFunction();
		}
	}

	void isEsc()
	{
		if (input::IsKeyDown(27))
		{
			isTutorial = false;
		}
	}

	void Title::StartButton()
	{
		isStart = true;
		Screen::SetScreen(Screen::ScreenName::ChooseFoodScreen);
	}

	void Title::TutorialButton()
	{
		isTutorial = true;
	}

	void Title::TitleRender()
	{
		render::DrawBackGround("resource\\background\\back.bmp", 0, 0, 0, 0, false);
		render::DrawObject(L"resource\\object\\Logo.png", 1000, 500, 100, 100, false);

		startButton.DrawButton();
		tutorialButton.DrawButton();

		/*if (isStart)
		{
			render::DrawBackGround("resource\\background\\back.bmp", 500, 500, 0, 0, false);
		}*/

		if (isTutorial)
		{
			render::DrawObject(L"resource\\object\\rule.png", 500, 500, 750, 300, false);
		}
	}
}