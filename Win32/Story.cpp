#include "Story.h"
#include "ScreenSystem.h"
#include "LoadData.h"

int maxScript = 0;
int curScript = 0;
Figure figure;
void SetStoryStage(int _stagenum)
{
	LoadData::soundManager->PlayMusic(Music::eSoundList::inside, Music::eSoundChannel::Effect);
	maxScript = 0;
	curScript = 0;
	SetStoryScript(_stagenum);
	maxScript = GetMaxPage();
}
void ChangeStoryScript(float delta)
{
	curScript = GetCurPage();
	SkipText(delta);
	UpdateText();

	if (curScript == maxScript)
	{
		Screen::SetScreen();
	}
}
void DrawStoryBack(int _stagenum)
{
	
	if (_stagenum == 1)
	{
		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5 || curScript == 6 || curScript == 7 || curScript == 8)   //1�������� ȸ��1
		{
			figure.isDraw = false;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
			LoadData::imageManager->DrawBitMapImage("��������1_1", 0, 0);
		}
		else if (curScript == 9 || curScript == 10) //1�������� ȸ�� 2
		{
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
			LoadData::imageManager->DrawBitMapImage("��������1_2", 0, 0);
		}
		else  //1 �������� ȸ�� ��
		{
			figure.isDraw = true;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
	}
	else if (_stagenum == 2)
	{
		if (curScript == 0)
		{
			figure.isDraw = true;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
		else if (curScript == 1 || curScript == 2)
		{   //����� ǥ�������� �ϴܳ����� ǥ���ð������ϸ� ��ġ���
			figure.expression = 2;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
		else if (curScript == 3 || curScript == 4 || curScript == 5)
		{
			figure.isDraw = false;
			//ȸ���
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
			LoadData::imageManager->DrawBitMapImage("��������2_1", 0, 0);
		}
		else if (curScript == 6)
		{
			//�ι��� ȸ���
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
			LoadData::imageManager->DrawBitMapImage("��������2_2", 0, 0);
		}
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
	}
	else
	{

		if (curScript == 0 || curScript == 1 || curScript == 2)
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
		else if (curScript == 3)
		{
			//ĳ���� ������ǥ�� ������������
			figure.expression = 2;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
		else if (curScript == 4 || curScript == 5 || curScript == 6)
		{
			figure.isDraw = false;
			//ù��° ȸ���
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
			LoadData::imageManager->DrawBitMapImage("��������3_1", 0, 0);
		}
		else if (curScript == 7 || curScript == 8)
		{
			//�ι�° ȸ���
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
			LoadData::imageManager->DrawBitMapImage("��������3_2", 0, 0);
		}
		//���� �߰��ʿ�
		else
		{
			figure.expression = 0;
			figure.isDraw = true;
			LoadData::imageManager->DrawPngImage("���ȭ��", 0, 0, 1920, 1080, 1.0f, false);
		}
	}
	figure.DrawFigure(_stagenum);
	LoadData::imageManager->DrawPngImage("�ؽ�Ʈ�ڽ�", 284, 750, 1366, 300, 0.95f);
	PrintText();



}


