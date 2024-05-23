#include "Title.h"

namespace Title
{
	bool isExit = false;
	bool isStart = false;
	bool isTutorial = false;

	button::Button startButton = { "시작버튼", 1230, 480, 360, 200, StartButton };
	button::Button tutorialButton = { "튜토리얼버튼", 1230, 650, 360, 200, TutorialButton };
	button::Button exitButton = { "종료버튼", 1230, 820, 360, 200, ExitButton };

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
		if (exitButton.CheckClick(x, y))
		{
			exitButton.PlayFunction();
		}
	}

	void isEsc()
	{
		if (input::IsKeyDown(27))
		{
			LoadData::soundManager->PlayMusic(Music::eSoundList::click, Music::eSoundChannel::Effect1);
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

	void Title::ExitButton()
	{
		PostQuitMessage(0);
	}

	void Title::TitleRender()
	{
		LoadData::AniManager[2].DrawAnimation();
		LoadData::imageManager->DrawPngImage("제목", 930, 130, 850, 410, 1.0f, false);
		startButton.DrawButton();
		tutorialButton.DrawButton();
		exitButton.DrawButton();

		if (isTutorial)
		{
			LoadData::imageManager->DrawPngImage("규칙", 167, 90, 1600, 900, 1.0f, false);
		}
	}

	void TitleCheckHover(int x, int y)
	{
		if (startButton.CheckClick(x, y))
		{
			startButton.SetSize(1215, 465, 390, 230);
		}
		else
		{
			startButton.SetSize(1230, 480, 360, 200);
		}
		if (tutorialButton.CheckClick(x, y))
		{
			tutorialButton.SetSize(1215, 635, 390, 230);
		}
		else
		{
			tutorialButton.SetSize(1230, 650, 360, 200);
		}
		if (exitButton.CheckClick(x, y))
		{
			exitButton.SetSize(1215, 805, 390, 230);
		}
		else
		{
			exitButton.SetSize(1230, 820, 360, 200);
		}
	}
}