#include "Ending.h"
#include "ScreenSystem.h"
#include "LoadData.h"

int maxEndingScript = 0; //�ִ� ��� ��ȣ
int curEndingScript = 0;
bool success;
Figure endFigure;
void SetEndingStage(int _stagenum, bool _success)
{
	maxEndingScript = 0;
	curEndingScript = 0;
	SetEndingScript(_stagenum, _success);
	success = _success;
}
void ChangeEndingScript(float delta)
{
	maxEndingScript = GetMaxPage();
	curEndingScript = GetCurPage();
	SkipText(delta);
	UpdateText();
	
	if (curEndingScript == maxEndingScript)
	{
		Screen::SetScreen();
	}
}

void DrawEndingBack(int _stagenum)
{
	//�쵿�׸� �߰��ʿ� �쵿����
	if (success) //��������
	{
		if (_stagenum == 1)//�ϋ� ��������1�� ������������
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 3;
				
			}
			else
			{
				endFigure.expression = 1;
			}
			
		}
		else if (_stagenum == 2)
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 3;

			}
			else
			{
				endFigure.expression = 1;
			}
		}
		else
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 3;

			}
			else
			{
				endFigure.expression = 1;
			}
		}
	}
	else
	{
		if (_stagenum == 1)
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 2;
			}

		}
		else if (_stagenum == 2)
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 3;

			}
			else
			{
				endFigure.expression = 2;
			}
		}
		else
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 3;

			}
			else
			{
				endFigure.expression = 2;
			}
		}
	}
	LoadData::imageManager->DrawBitMapImage("���ȭ��", 0, 0);
	endFigure.DrawFigure(_stagenum);
	LoadData::imageManager->DrawPngImage("�ؽ�Ʈ�ڽ�", 284, 750, 1366, 300, 0.8f);
	PrintText();
	

}