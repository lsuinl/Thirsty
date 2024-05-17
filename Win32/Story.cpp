#include "Story.h"
#include "ScreenSystem.h"

int i;
int stagenum;     //스테이지num 받아와야함 
void SetStage(int num)
{
	i = 0;
		stagenum = num;
		SetScript(num);
	
}
void ChangeBack(float delta)
{
	SkipText(delta);
	UpdateText();
	if(input::IsKeyUp(16))
	{
		if(i < 5)
		i++;
	}

	if (i == 5)
	{
		Screen::SetScreen();
	}
}
void DrawBack()
{
	//if stagenum == 1  일떄 스테이지1의 배경순차적으로
	if(i ==0)
	render::DrawBackGround("resource/background/story/1.bmp", 1920, 1080, 0, 0, false);
	else if(i ==1)
	render::DrawBackGround("resource/background/story/2.bmp", 1920, 1080, 0, 0, false);
	else if (i == 2)
		render::DrawBackGround("resource/background/story/3.bmp", 1920, 1080, 0, 0, false);
	else if (i == 3)
		render::DrawBackGround("resource/background/story/4.bmp", 1920, 1080, 0, 0, false);
	else if (i == 4)
		render::DrawBackGround("resource/background/story/5.bmp", 1920, 1080, 0, 0, false);
	
	PrintText();

}