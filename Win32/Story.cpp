#include "Story.h"
#include "ScreenSystem.h"
#include "LoadData.h"

int maxScript= 0;
int curScript = 0;
Figure figure;
void SetStoryStage(int _stagenum)
{
	maxScript = 0;
	curScript = 0;
	SetStoryScript(_stagenum);
	maxScript = GetMaxPage();
}
void ChangeStoryScript(float delta)
{
	curScript = GetCurPage();
	SkipText(delta);
	UpdateText();
	
	if (curScript == maxScript)
	{
		LoadData::soundManager->SetVolume(0);
		Screen::SetScreen();
		LoadData::soundManager->PlayMusic(Music::eSoundList::moveani, Music::eSoundChannel::Effect);
		LoadData::soundManager->SetVolume(1);
	}
}
void DrawStoryBack(int _stagenum)
{
	if(_stagenum == 1)
	{
		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5 || curScript == 6 || curScript == 7 || curScript == 8)   //1스테이지 회상1
		{
			figure.isDraw = false;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
			LoadData::imageManager->DrawBitMapImage("스테이지1_1", 150, 100);
		}
		else if (curScript == 9 || curScript == 10 ) //1스테이지 회상 2
		{
			LoadData::imageManager->DrawBitMapImage("스테이지1_2", 0, 0);
		}
		else  //1 스테이지 회상 끝
		{
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
	}
	else if(_stagenum == 2)
	{
		if (curScript == 0)
		{
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else if (curScript == 1 || curScript == 2)
		{   //억울한 표정때문에 일단나눠둠 표정시간없다하면 합치면됨
			figure.expression = 2;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5)
		{
			figure.isDraw = false;
			//회상씬
			LoadData::imageManager->DrawBitMapImage("스테이지2_1", 0, 0);
		}
		else if (curScript == 6)
		{ 
			//두번쨰 회상씬
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
	}
	else
	{

		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else if (curScript == 3)
		{
			//캐릭터 씁쓿한표정 없어질수도있
			figure.expression = 2;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else if (curScript == 4 || curScript == 5 || curScript ==  6)
		{
			figure.isDraw = false;
			//첫번째 회상씬
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
		else if(curScript == 7 || curScript == 8)
		{
			//두번째 회상씬
			LoadData::imageManager->DrawBitMapImage("스테이지3_2", 0, 0);
		}
		//이후 추가필요
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
		}
	}
	figure.DrawFigure(_stagenum);
	LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.98f);
	PrintText();
	


}


