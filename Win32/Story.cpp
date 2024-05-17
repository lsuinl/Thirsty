#include "Story.h"
#include "ScreenSystem.h"

int maxScript= 0; //�ִ� ��� ��ȣ
int curScript = 0;
void SetStoryStage(int _stagenum)
{
	maxScript = 0;
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
	if(_stagenum == 1)//�ϋ� ��������1�� ������������
	{
		if (curScript == 0)
			render::DrawBackGround("resource/object/best.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 1)
			render::DrawBackGround("resource/object/basket.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 2)
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 3)
			render::DrawBackGround("resource/object/down.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 4)
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
	}
	else if(_stagenum == 2)
	{
		if (curScript == 0)
			render::DrawBackGround("resource/object/shrimp.bmp", 1920, 1080, 0, 0, false);
		else if (curScript == 1)
			render::DrawBackGround("resource/object/basket.bmp", 1920, 1080, 0, 0, false);
	}
	else
	{
		render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
	}
	PrintText();
	


}