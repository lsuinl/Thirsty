#include "Title.h"
#include "LoadData.h"
namespace Title
{
	bool isExit = false;
	bool isStart = false;
	bool isTutorial = false;

	button::Button startButton = { "시작버튼", 1100, 600, 300, 100, StartButton };
	button::Button tutorialButton = { "튜토리얼버튼", 1100, 750, 300, 100, TutorialButton };

	void Title::TitleCheckClick(int x, int y)
	{
		if (startButton.CheckClick(x, y))
		{
			startButton.PlayFunction();
		}
		if (tutorialButton.CheckClick(x, y))
		{
			tutorialButton.PlayFunction();
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
		Screen::SetScreen();
	}

	void Title::TutorialButton()
	{
		isTutorial = true;
	}

	void Title::TitleRender()
	{
		LoadData::imageManager->DrawBitMapImage("타이틀화면",0,0);
		LoadData::imageManager->DrawPngImage("제목", 100, 100, 1000, 500,1.0f);

		startButton.DrawButton();
		tutorialButton.DrawButton();

		if (isTutorial)
		{
			LoadData::imageManager->DrawPngImage("규칙", 500, 500, 750, 300, 1.0f);
		}
	}
}