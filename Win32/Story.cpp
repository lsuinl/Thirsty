#include "Story.h"
#include "ScreenSystem.h"

int maxScript= 0; //최대 대사 번호
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
	SkipText(delta);
	UpdateText();
	if(input::IsKeyUp(16))               //스크립트 페이지전환 이랑  다음시나리오 전환 버튼분리
	{
		if(curScript < maxScript)
			curScript++;
	}
	if (curScript == maxScript)
	{
		Screen::SetScreen();
	}
}
void DrawStoryBack(int _stagenum)
{
	if(_stagenum == 1)//일떄 스테이지1의 배경순차적으로
	{
		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5 || curScript == 6 || curScript == 7 || curScript == 8)   //1스테이지 회상1
		{
			figure.isDraw = false;
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 9 || curScript == 10 ) //1스테이지 회상 2
		{
			render::DrawBackGround("resource/object/best.bmp", 1920, 1080, 0, 0, false);
		}
		else  //1 스테이지 회상 끝
		{
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
	}
	else if(_stagenum == 2)
	{
		if (curScript == 0)
		{
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 1 || curScript == 2)
		{   //억울한 표정때문에 일단나눠둠 표정시간없다하면 합치면됨
			figure.expression = 2;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5)
		{
			figure.isDraw = false;
			//회상씬
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 6)
		{ 
			//두번쨰 회상씬
			render::DrawBackGround("resource/object/basket.bmp", 1920, 1080, 0, 0, false);
		}
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
	}
	else
	{


		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 3)
		{
			//캐릭터 씁쓿한표정 없어질수도있
			figure.expression = 2;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 4 || curScript == 5 || curScript ==  6)
		{
			figure.isDraw = false;
			//첫번째 회상씬
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		}
		else if(curScript == 7 || curScript == 8)
		{
			//두번째 회상씬
			render::DrawBackGround("resource/object/basket.bmp", 1920, 1080, 0, 0, false);
		}
		//이후 추가필요
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		
	}
	figure.DrawFigure(_stagenum);
	render::DrawObject(L"resource\\object\\rect.png", 1600, 600, 200, 500, true, 0.8f);
	PrintText();
	


}


