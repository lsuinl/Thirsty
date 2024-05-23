#include "Ending.h"
#include "ScreenSystem.h"
#include "LoadData.h"
#include <vector>
int maxEndingScript = 0; //최대 대사 번호
int curEndingScript = 0;
bool success;
Figure endFigure;
Decoudong decoudong[9];
Decoudong udong;
void SetEndingStage(int _stagenum, bool _success,int* _decolist)
{
	maxEndingScript = 0;
	curEndingScript = 0;
	SetEndingScript(_stagenum, _success);
	success = _success;
	endFigure.expression = 0;
	udong.udongnum = PlayerData::player.GetNoodle();
	for (int i = 0; i < 2; i++) // 0부터 2까지 반복
	{
		decoudong[i].SetDecoudong(i * 70 + 820, 800);

	}
	for (int i = 0; i < 4; i++) // 0부터 2까지 반복
	{
		decoudong[i + 2].SetDecoudong(i * 30 + 810, 820);

	}
	for (int i = 0; i < 3; i++) // 0부터 2까지 반복
	{
		decoudong[i + 6].SetDecoudong(i * 70 + 820, 825);

	}

	for (int i = 0; i < 9; i++)
	{
		decoudong[i].SetDeco(_decolist[i]);
	}


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

void DrawEndingBack(int _stagenum,float delta)
{

	LoadData::imageManager->DrawPngImage("배경화면", 0, 0, 1920, 1080, 1.0f, false);
	endFigure.DrawFigure(_stagenum);

	udong.Drawudong();

	for (int i = 0; i < 9; i++)
	{

		decoudong[i].DrawDeco();
	}

	//우동그림 추가필요 우동별로
	if (success) //성공장면들
	{
		if (_stagenum == 1)//일떄 스테이지1의 배경순차적으로
		{

			if (curEndingScript == 0)
			{
				endFigure.expression = 0;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);
			}
			else if (curEndingScript == 1)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 1;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);

			}

		}
		else if (_stagenum == 2)
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 0;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);
			}
			else if (curEndingScript == 1)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 1;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);

			}
		}
		else
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 0;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);
			}
			else if (curEndingScript == 1)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 4;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);

			}
		}
	}
	else
	{
		if (_stagenum == 1)
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 0;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);
			}
			else if (curEndingScript == 1)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 2;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);

			}

		}
		else if (_stagenum == 2)
		{

			if (curEndingScript == 0)
			{
				endFigure.expression = 0;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);
			}
			else if (curEndingScript == 1)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 2;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);

			}
		}
		else
		{
			if (curEndingScript == 0)
			{
				endFigure.expression = 0;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);
			}
			else if (curEndingScript == 1)
			{
				endFigure.expression = 3;
			}
			else
			{
				endFigure.expression = 2;
				LoadData::imageManager->DrawPngImage("텍스트박스", 284, 750, 1366, 300, 0.8f);
				PrintText(delta);

			}

		}
	}
}

void Decoudong::DrawDeco()
{
	if (deconum == 7)
	{
		LoadData::imageManager->DrawPngImage("가쓰오부시", this->posX, this->posY, 70, 55, 1.0f, true);
	}
	else if (deconum == 8)
	{
		LoadData::imageManager->DrawPngImage("반달어묵", this->posX, this->posY, 65, 46, 1.0f, true);
	}
	else if (deconum == 9)
	{


		LoadData::imageManager->DrawPngImage("튀김가루", this->posX, this->posY, 64, 42, 1.0f, true);
	}
	else if (deconum == 10)
	{
		LoadData::imageManager->DrawPngImage("대파", this->posX, this->posY, 70, 55, 1.0f, true);
	}
	else if (deconum == 11)
	{
		LoadData::imageManager->DrawPngImage("표고버섯", this->posX, this->posY, 55, 54, 1.0f, true);
	}
	else if (deconum == 12)
	{
		LoadData::imageManager->DrawPngImage("직화고기", this->posX, this->posY, 110, 60, 1.0f, true);
	}
	else if (deconum == 13)
	{
		LoadData::imageManager->DrawPngImage("썬유부", this->posX, this->posY, 60, 50, 1.0f, true);
	}
	else if (deconum == 14)
	{
		LoadData::imageManager->DrawPngImage("쑥갓", this->posX, this->posY, 60, 60, 1.0f, true);
	}
	else if (deconum == 15)
	{
		LoadData::imageManager->DrawPngImage("썬김(김채)", this->posX, this->posY, 50, 50, 1.0f, true);
	}
	else if (deconum == 16)
	{
		LoadData::imageManager->DrawPngImage("납작어묵", this->posX, this->posY, 60, 45, 1.0f, true);
	}
	else if (deconum == 17)
	{
		LoadData::imageManager->DrawPngImage("새우튀김", this->posX, this->posY, 80, 60, 1.0f, true);
	}
	else if (deconum == 18)
	{
		LoadData::imageManager->DrawPngImage("썬대파", this->posX, this->posY, 55, 45, 1.0f, true);
	}
	else if (deconum == 19)
	{
		LoadData::imageManager->DrawPngImage("썬청양고추", this->posX, this->posY, 60, 52, 1.0f, true);
	}
}

void Decoudong::SetDecoudong(float x, float y)
{
	this->posX = x;
	this->posY = y;
}

void Decoudong::SetDeco(int _num)
{
	this->deconum = _num;
}

void Decoudong::Setudong(float x, float y, int _num)
{
	this->posX = x;
	this->posY = y;
	this->udongnum = _num;
}

void Decoudong::Drawudong()
{
	if (udongnum == 1)
	{
		LoadData::imageManager->DrawPngImage("납작면우동", 740, 750, 300, 200, 1.0f, true);
	}
	else if(udongnum == 2)
	{
		LoadData::imageManager->DrawPngImage("중면우동", 740, 750, 300, 200, 1.0f, true);
	}
	else if(udongnum == 3)
	{
		LoadData::imageManager->DrawPngImage("소면우동", 740, 750, 300, 200, 1.0f, true);
	}
	else
	{
		LoadData::imageManager->DrawPngImage("소면우동", 740, 750, 300, 200, 1.0f, true);
	}
}
