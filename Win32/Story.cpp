#include "Story.h"
#include "ScreenSystem.h"

int maxScript= 0; //�ִ� ��� ��ȣ
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
	if(input::IsKeyUp(16))               //��ũ��Ʈ ��������ȯ �̶�  �����ó����� ��ȯ ��ư�и�
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
	if(_stagenum == 1)//�ϋ� ��������1�� ������������
	{
		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5 || curScript == 6 || curScript == 7 || curScript == 8)   //1�������� ȸ��1
		{
			figure.isDraw = false;
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 9 || curScript == 10 ) //1�������� ȸ�� 2
		{
			render::DrawBackGround("resource/object/best.bmp", 1920, 1080, 0, 0, false);
		}
		else  //1 �������� ȸ�� ��
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
		{   //����� ǥ�������� �ϴܳ����� ǥ���ð������ϸ� ��ġ���
			figure.expression = 2;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5)
		{
			figure.isDraw = false;
			//ȸ���
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 6)
		{ 
			//�ι��� ȸ���
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
			//ĳ���� ������ǥ�� ������������
			figure.expression = 2;
			render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		}
		else if (curScript == 4 || curScript == 5 || curScript ==  6)
		{
			figure.isDraw = false;
			//ù��° ȸ���
			render::DrawBackGround("resource/object/Prriceshrimp.bmp", 1920, 1080, 0, 0, false);
		}
		else if(curScript == 7 || curScript == 8)
		{
			//�ι�° ȸ���
			render::DrawBackGround("resource/object/basket.bmp", 1920, 1080, 0, 0, false);
		}
		//���� �߰��ʿ�
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


