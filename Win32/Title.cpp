#include "Title.h"
#include "LoadData.h"
namespace Title
{
	bool isExit = false;
	bool isStart = false;
	bool isTutorial = false;

	button::Button startButton = { "���۹�ư", 1100, 600, 300, 100, StartButton };
	button::Button tutorialButton = { "Ʃ�丮���ư", 1100, 750, 300, 100, TutorialButton };

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
		LoadData::imageManager->DrawPngImage("����ȭ��", 0, 0, 1935, 1080, 1.0f, false);

		startButton.DrawButton();
		tutorialButton.DrawButton();

		if (isTutorial)
		{
			LoadData::imageManager->DrawPngImage("��Ģ", 500, 500, 750, 300, 1.0f, false);
		}
	}
}