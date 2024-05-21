#include "Ending.h"
#include "ScreenSystem.h"
#include "LoadData.h"

int maxEndingScript = 0; //최대 대사 번호
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
	//우동그림 추가필요 우동별로
	if (success) //성공장면들
	{
		if (_stagenum == 1)//일떄 스테이지1의 배경순차적으로
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
	LoadData::imageManager->DrawBitMapImage("배경화면", 0, 0);
	endFigure.DrawFigure(_stagenum);
	LoadData::imageManager->DrawPngImage("텍스트박스", 200, 500, 1600, 600, 0.8f);
	PrintText();


}