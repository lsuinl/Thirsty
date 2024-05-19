#include "Ending.h"
#include "ScreenSystem.h"


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
	render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
	endFigure.DrawFigure(_stagenum);
	render::DrawObject(L"resource\\object\\rect.png", 1600, 600, 200, 500, true, 0.8f);
	PrintText();
	

}