#include "Title.h"
#include "LoadData.h"
namespace Title
{
	bool isExit = false;
	bool isStart = false;
	bool isTutorial = false;

	button::Button startButton = { "���۹�ư", 1230, 480, 360, 200, StartButton };
	button::Button tutorialButton = { "Ʃ�丮���ư", 1230, 650, 360, 200, TutorialButton };
	button::Button exitButton = { "�����ư", 1230, 820, 360, 200, ExitButton };

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

	}

	void Title::TitleRender()
	{
		LoadData::AniManager[2].DrawAnimation();
		LoadData::imageManager->DrawPngImage("����", 930, 130, 850, 410, 1.0f, false);
		startButton.DrawButton();
		tutorialButton.DrawButton();
		exitButton.DrawButton();

		if (isTutorial)
		{
			LoadData::imageManager->DrawPngImage("��Ģ", 500, 500, 750, 300, 1.0f, false);
		}
	}
}