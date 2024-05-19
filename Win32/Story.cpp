#include "Story.h"
#include "ScreenSystem.h"
#include "LoadData.h"

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
			LoadData::imageManager->DrawBitMapImage("스토리화면1",0,0);
		else if (curScript == 1)
			LoadData::imageManager->DrawBitMapImage("스토리화면2", 0, 0); 
		else if (curScript == 2)
			LoadData::imageManager->DrawBitMapImage("스토리화면3", 0, 0);
		else if (curScript == 3)
			LoadData::imageManager->DrawBitMapImage("스토리화면4", 0, 0); 
		else if (curScript == 4)
			LoadData::imageManager->DrawBitMapImage("스토리화면5", 0, 0);
	}
	else if(_stagenum == 2)
	{
		if (curScript == 0)
			LoadData::imageManager->DrawBitMapImage("스토리화면1", 0, 0);
		else if (curScript == 1)
			LoadData::imageManager->DrawBitMapImage("스토리화면2", 0, 0);
	}
	PrintText();
	


}