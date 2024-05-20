#include "Story.h"
#include "ScreenSystem.h"
#include "LoadData.h"

int maxScript= 0;
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
	if(_stagenum == 1)
	{
		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5 || curScript == 6 || curScript == 7 || curScript == 8)   //1�������� ȸ��1
		{
			figure.isDraw = false;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else if (curScript == 9 || curScript == 10 ) //1�������� ȸ�� 2
		{
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else  //1 �������� ȸ�� ��
		{
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
	}
	else if(_stagenum == 2)
	{
		if (curScript == 0)
		{
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else if (curScript == 1 || curScript == 2)
		{   //����� ǥ�������� �ϴܳ����� ǥ���ð������ϸ� ��ġ���
			figure.expression = 2;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5)
		{
			figure.isDraw = false;
			//ȸ���
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��2", 0, 0);
		}
		else if (curScript == 6)
		{ 
			//�ι��� ȸ���
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��3", 0, 0);
		}
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
	}
	else
	{


		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else if (curScript == 3)
		{
			//ĳ���� ������ǥ�� ������������
			figure.expression = 2;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
		else if (curScript == 4 || curScript == 5 || curScript ==  6)
		{
			figure.isDraw = false;
			//ù��° ȸ���
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��2", 0, 0);
		}
		else if(curScript == 7 || curScript == 8)
		{
			//�ι�° ȸ���
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��3", 0, 0);
		}
		//���� �߰��ʿ�
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawBitMapImage("���丮ȭ��1", 0, 0);
		}
	}
	figure.DrawFigure(_stagenum);
	LoadData::imageManager->DrawPngImage("�ؽ�Ʈ�ڽ�", 200, 500, 1600, 600, 0.8f);
	PrintText();
	


}


