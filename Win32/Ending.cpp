#include "Ending.h"
#include "ScreenSystem.h"
#include "LoadData.h"
int maxEndingScript = 0; //�ִ� ��� ��ȣ
int curEndingScript = 0;
void SetEndingStage(int _stagenum, bool success)
{
	curEndingScript=0;
	SetEndingScript(_stagenum, success);
}



void ChangeEndingBack(float delta)
{
	maxEndingScript = GetMaxPage();
	SkipText(delta);
	UpdateText();
	if (input::IsKeyUp(16))
	{
		if (curEndingScript < maxEndingScript)
			curEndingScript++;
	}
	if (curEndingScript == maxEndingScript)
	{
		Screen::SetScreen();
	}
}

void DrawEndingBack(int _stagenum)
{

	if (_stagenum == 1)//�ϋ� ��������1�� ������������
	{
		if (curEndingScript == 0)
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1",0,0);
		else if (curEndingScript == 1)
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��2", 0, 0);
		else if (curEndingScript == 2)
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��3", 0, 0);
		else if (curEndingScript == 3)
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��4", 0, 0);
	}
	PrintText();

}