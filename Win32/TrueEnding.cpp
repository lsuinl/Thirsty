#include "TrueEnding.h"
#include "ScreenSystem.h"
#include "LoadData.h"
#include "FadeinFadeout.h"

int maxTrueEndingScript;
int curTrueEndingScript;
bool trueEnding;
float wait_timer = 5000.0f;
void SetTrueEndingStage(bool _success)
{
	wait_timer = 5000.0f;
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
			LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��", 0, 0);
			LoadData::imageManager->DrawPngImage("�ؽ�Ʈ�ڽ�", 284, 750, 1366, 300, 0.8f);
			PrintText();

		}
		else if (curTrueEndingScript > 7 && curTrueEndingScript < maxTrueEndingScript)
		{
			//���̵�ƿ� �ֱ��ʿ� ��� ���̵�ƿ� ������ ����ϰԲ�
			LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��", 0, 0);
			fadeinfadeout::FadeInUpdate();
			fadeinfadeout::RenderFadeIn("���̵�");

			PrintTextEnd();
		}
		else if (curTrueEndingScript == maxTrueEndingScript)
		{
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
	wait_timer -= delta;
	if (wait_timer <= 0)
	{
		static float posY = 0.0f;
		posY = posY - 0.3 * delta;
		LoadData::imageManager->DrawPngImage("����", 0, posY, 1935, 6035, 1.0f, false);
	}
}

void SetCre()
{
	//���⿡ ����ũ������ ���̵���

}
void RenderCre(float delta)
{

	EndingCre(delta);
}


void GoTitle()
{  //�� �Լ��� ����ũ������ �ٿö󰡸� ����ǰԲ�
	if (input::IsKeyUp(27))
	{
		Screen::SetScreen();
	}
}