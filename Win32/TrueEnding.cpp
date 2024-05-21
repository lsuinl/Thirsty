#include "TrueEnding.h"
#include "ScreenSystem.h"
#include "LoadData.h"

int maxTrueEndingScript;
int curTrueEndingScript;
bool trueEnding;
void SetTrueEndingStage(bool _success)
{
	maxTrueEndingScript = 0;
	curTrueEndingScript = 0;
	SetTrueEndingScript(_success);
	maxTrueEndingScript = GetMaxPage();
	trueEnding = _success;
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
		else if(curTrueEndingScript > 7 && curTrueEndingScript < maxTrueEndingScript)
		{
			//���̵�ƿ� �ֱ��ʿ� ��� ���̵�ƿ� ������ ����ϰԲ�

			PrintTextEnd();
		}
		else if (curTrueEndingScript == maxTrueEndingScript)
		{
			Endingcre(delta);
			
		}
		if (curTrueEndingScript > maxTrueEndingScript)
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

void Endingcre(float delta)
{
	static float posY = 0.0f;
	posY = posY - 0.3 * delta;
	LoadData::imageManager->DrawPngImage("����", 0, posY, 1935, 6035);

	
}