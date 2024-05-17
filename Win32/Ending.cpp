#include "Ending.h"
#include "ScreenSystem.h"

int maxEndingScript = 0; //최대 대사 번호
int curEndingScript = 0;
void SetEndingStage(int _stagenum, bool success)
{
	maxEndingScript = 0;
	curEndingScript = 0;
	SetEndingScript(_stagenum, success);
}


void ChangeEndingScript(float delta)
{
	maxEndingScript = GetMaxPage();
	SkipText(delta);
	UpdateText();
	if (input::IsKeyUp(16))
	{
		if (curEndingScript < maxEndingScript)
			curEndingScript++;
	}
	if (curEndingScript == maxEndingScript)
	{
		Screen::SetScreen();
	}
}

void DrawEndingBack(int _stagenum)
{

	if (_stagenum == 1)//일떄 스테이지1의 배경순차적으로
	{
		if (curEndingScript == 0)
			render::DrawBackGround("resource/object/best.bmp", 1920, 1080, 0, 0, false);
		else if (curEndingScript == 1)
			render::DrawBackGround("resource/object/basket.bmp", 1920, 1080, 0, 0, false);
		else if (curEndingScript == 2)
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		else if (curEndingScript == 3)
			render::DrawBackGround("resource/object/down.bmp", 1920, 1080, 0, 0, false);
		else if (curEndingScript == 4)
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
	}
	else if(_stagenum == 2)
	{
		if (curEndingScript == 0)
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
	}
	else if (_stagenum == 3)
	{
		if (curEndingScript == 0)
			render::DrawBackGround("resource/background/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
	}
	PrintText();

}