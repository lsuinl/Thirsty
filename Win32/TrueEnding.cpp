#include "TrueEnding.h"
#include "ScreenSystem.h"
#include "LoadData.h"
#include "FadeinFadeout.h"

int maxTrueEndingScript;
int curTrueEndingScript;
bool trueEnding;
float waitTime = 4000.0f;
float wait_timer = 2500.0f;
static float posY = 0.0f;
//int scale;
void SetTrueEndingStage(bool _success)
{	

	//scale = 1;
	posY = 0.0f;
	waitTime = 4000.0f;
	wait_timer = 2500.0f;
	maxTrueEndingScript = 0;
	curTrueEndingScript = 0;
	SetTrueEndingScript(_success);
	maxTrueEndingScript = GetMaxPage();
	trueEnding = _success;
	fadeinfadeout::SetFadeIn();
	if (_success)
	{
		LoadData::soundManager->PlayMusic(Music::eSoundList::realEnding, Music::eSoundChannel::BGM);
	}
	else
	{
		LoadData::soundManager->PlayMusic(Music::eSoundList::normalEnding, Music::eSoundChannel::BGM);
	}
}

void DrawTrueEndingBack(float delta)
{
	if (trueEnding)
	{
		if (curTrueEndingScript <= 7)
		{
			LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��", 0, 0);
			LoadData::imageManager->DrawPngImage("�ؽ�Ʈ�ڽ�", 284, 750, 1366, 300, 0.8f);
			PrintText(delta);

		}
		else if (curTrueEndingScript > 7 && curTrueEndingScript < maxTrueEndingScript)
		{
			//���̵�ƿ� �ֱ��ʿ� ��� ���̵�ƿ� ������ ����ϰԲ�
			LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��", 0, 0);
			fadeinfadeout::FadeInUpdate();
			fadeinfadeout::RenderFadeIn("���̵�");

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
			LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��", 0, 0);
			LoadData::imageManager->DrawPngImage("�ؽ�Ʈ�ڽ�", 284, 750, 1366, 300, 0.8f);
			PrintText(delta);

		}
		else if (curTrueEndingScript > 3 && curTrueEndingScript < maxTrueEndingScript)
		{
			//���̵�ƿ� �ֱ��ʿ� ��� ���̵�ƿ� ������ ����ϰԲ�
			LoadData::imageManager->DrawBitMapImage("Ÿ��Ʋȭ��", 0, 0);
			fadeinfadeout::FadeInUpdate();
			fadeinfadeout::RenderFadeIn("���̵�");

			PrintTextEnd();
		}
		else
		{
			LoadData::imageManager->DrawPngImage("���̵�", 0, 0, 1935, 1080, 1.0f, false);
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
	LoadData::imageManager->DrawPngImage("���̵�", 0, 0, 1935, 1080, 1.0f, false);
	fadeinfadeout::FadeInUpdate();
	fadeinfadeout::RenderFadeIn("�쵿�ѱ׸�");
	//LoadData::imageManager->DrawPngImage("�쵿�ѱ׸�", 0, 0, 1935, 1080, 1.0f, false);
	wait_timer -= delta;
	if (wait_timer <= 0 && posY >= -4955)
	{
		posY = posY - 0.3 * delta;
	}
	LoadData::imageManager->DrawPngImage("����", 0, posY, 1935, 6035, 1.0f, false);
	GoTitle(delta);

}

void SetCre()
{
	LoadData::soundManager->StopMusic(Music::eSoundChannel::Effect);
	fadeinfadeout::SetFadeIn();
}
void RenderCre(float delta)
{
	EndingCre(delta);
}


void GoTitle(float delta)
{  //�� �Լ��� ����ũ������ �ٿö󰡸� ����ǰԲ�
	/*if (input::IsKeyUp(27))
	{
		Screen::SetScreen();
	}*/
	if (posY <= -4955)
	{
		waitTime -= delta;
		if (waitTime <= 0)
		{
			Screen::SetScreen();
		}
	}
}