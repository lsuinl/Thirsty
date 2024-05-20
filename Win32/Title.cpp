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
		LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��",0,0);
		LoadData::imageManager->DrawPngImage("����", 100, 100, 1000, 500,1.0f);

		startButton.DrawButton();
		tutorialButton.DrawButton();

		if (isTutorial)
		{
			LoadData::imageManager->DrawPngImage("��Ģ", 500, 500, 750, 300, 1.0f);
		}
	}
}