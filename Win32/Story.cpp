#include "Story.h"
#include "ScreenSystem.h"


int maxScript= 0;
int curScript = 0;
void SetStoryStage(int _stagenum)
{	
	curScript = 0;
	SetStoryScript(_stagenum);
}
void ChangeScript(float delta)
{
	maxScript = GetMaxPage();
	SkipText(delta);
	UpdateText();
	if(input::IsKeyUp(16))
	{
		if(curScript < maxScript)
			curScript++;
	}
	if (curScript == maxScript)
	{
		Screen::SetScreen();
	}
}
void DrawBack(int _stagenum)
{
	if(_stagenum == 1)
	{
		if (curScript == 0)
		render::DrawBackGround("resource/background/story/1.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 1)
		render::DrawBackGround("resource/background/story/2.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 2)
			render::DrawBackGround("resource/background/story/3.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 3)
		render::DrawBackGround("resource/background/story/4.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 4)
		render::DrawBackGround("resource/background/story/5.bmp", 1920, 1080, 0, 0, false);
	}
	else if(_stagenum == 2)
	{
		if (curScript == 0)
		render::DrawBackGround("resource/background/story/1.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 1)
			render::DrawBackGround("resource/background/story/2.bmp", 1920, 1080, 0, 0, false);
	}
	PrintText();
	


}