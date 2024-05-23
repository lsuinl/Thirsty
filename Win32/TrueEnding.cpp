#include "TrueEnding.h"
#include "ScreenSystem.h"
#include "LoadData.h"
#include "FadeinFadeout.h"

int maxTrueEndingScript;
int curTrueEndingScript;
bool trueEnding;
float wait_timer = 2500.0f;
void SetTrueEndingStage(bool _success)
{
	wait_timer = 2500.0f;
	maxTrueEndingScript = 0;
	curTrueEndingScript = 0;
	SetTrueEndingScript(_success);
	maxTrueEndingScript = GetMaxPage();
	trueEnding = _success;
	fadeinfadeout::SetFadeIn();
}

void DrawTrueEndingBack(float delta)
{
	if (trueEnding)
	{
		if (curTrueEndingScript <= 7)
		{
			LoadData::imageManager->DrawBitMapImage("타이틀화면", 0, 0);
			LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
			PrintText(delta);

		}
		else if (curTrueEndingScript > 7 && curTrueEndingScript < maxTrueEndingScript)
		{
			//페이드아웃 넣기필요 배경 페이드아웃 끝나면 출력하게끔
			LoadData::imageManager->DrawBitMapImage("타이틀화면", 0, 0);
			fadeinfadeout::FadeInUpdate();
			fadeinfadeout::RenderFadeIn("페이드");

			PrintTextEnd();
		}
		else
		{
			curTrueEndingScript = 0;
			Screen::SetScreen();
		}
	}
	else
	{
		if (curTrueEndingScript <= 3)
		{
			LoadData::imageManager->DrawBitMapImage("타이틀화면", 0, 0);
			LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
			PrintText(delta);

		}
		else if (curTrueEndingScript > 3 && curTrueEndingScript < maxTrueEndingScript)
		{
			//페이드아웃 넣기필요 배경 페이드아웃 끝나면 출력하게끔
			LoadData::imageManager->DrawBitMapImage("타이틀화면", 0, 0);
			fadeinfadeout::FadeInUpdate();
			fadeinfadeout::RenderFadeIn("페이드");

			PrintTextEnd();
		}
		else 
		{
			LoadData::imageManager->DrawPngImage("페이드", 0, 0, 1935, 1080, 1.0f, false);
			curTrueEndingScript = 0;
			Screen::SetScreen();
		}
	}

}

void ChangeTrueEndingScript(float delta)
{
	maxTrueEndingScript = GetMaxPage();
	curTrueEndingScript = GetCurPage();
	SkipText(delta);
	UpdateText();
}

void EndingCre(float delta)
{
	LoadData::imageManager->DrawPngImage("페이드", 0, 0, 1935, 1080, 1.0f, false);
	fadeinfadeout::FadeInUpdate();
	fadeinfadeout::RenderFadeIn("우동한그릇");
	//LoadData::imageManager->DrawPngImage("우동한그릇", 0, 0, 1935, 1080, 1.0f, false);
	wait_timer -= delta;
	if (wait_timer <= 0)
	{
		static float posY = 0.0f;
		posY = posY - 0.3 * delta;
		LoadData::imageManager->DrawPngImage("엔딩", 0, posY, 1935, 6035, 1.0f, false);
	}
}

void SetCre()
{
	fadeinfadeout::SetFadeIn();
}
void RenderCre(float delta)
{
	EndingCre(delta);
}


void GoTitle()
{  //이 함수가 엔딩크레딧이 다올라가면 실행되게끔
	if (input::IsKeyUp(27))
	{
		Screen::SetScreen();
	}
}