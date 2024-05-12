#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"

//�� ����
enum Noodle 
{
	wow,
	suin,
	ee,
};

//���� ����
enum Soup 
{
	bi,
	in,
};

//��� ����
enum Decoration 
{
	wowff,
};

namespace ChooseFood
{
	Noodle noodle;
	Soup soup[];
	Decoration decortaion[];
	int screenIndex = 0, basketIndex = 0;
	button::Button buttonList[5] =
	{
		button::Button("����",80,500,100,100, "resource/background/back.bmp",LeftPage),
		button::Button("������",1280, 500, 100, 100, "resource/background/back.bmp",RightPage),
		button::Button("����",1600,100, 100, 100, "resource/background/back.bmp",UpBasket),
		button::Button("�Ʒ���",1600, 900, 100, 100, "resource/background/back.bmp",DownBasket),
		button::Button("�Ϸ�",1700, 950, 100, 100, "resource/background/back.bmp",Selected),
	};

	void ChooseScreen() 
	{
		//��� �̹��� �׸���
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
		if (screenIndex==0)
		{
			NoodleScreen();
		}
		else if (screenIndex == 1)
		{
			SoupScreen();
		}
		else
		{
			DecorationScreen();
		}

		//��ư �׸���
		for (int i = 0; i < sizeof(buttonList)/sizeof(button::Button); i++)
		{
			//���� ���¿� ���� �̵� ȭ��ǥ �����ֱ� ���� ����
			if ((screenIndex == 0 && i == 0) || (screenIndex == 2 && i == 1) || (basketIndex == 0 && i == 2) || (basketIndex == 10 && i == 3))
			{
				continue;
			}
			buttonList[i].DrawButton();
		}
	}

	void CheckButton(int dx,int dy)
	{
		for (int i = 0; i < sizeof(buttonList) / sizeof(button::Button); i++)
		{
			//���� ���¿� ���� �̵� ȭ��ǥ �۵� ���� ����
			if ((screenIndex == 0 && i == 0) || (screenIndex == 2 && i == 1) || (basketIndex == 0 && i == 2) || (basketIndex == 10 && i == 3))
			{
				continue;
			}
			buttonList[i].CheckClick(dx,dy);
		}
	}
	//��, ����, ��� ���� ȭ��
	void NoodleScreen() 
	{
		render::DrawTextF(130, 90, "�� ����", RGB(0, 0, 0), 60);
	}

	void SoupScreen() 
	{
		render::DrawTextF(130, 90, "���� ����", RGB(0, 0, 0), 60);
	}

	void DecorationScreen() 
	{
		render::DrawTextF(130, 90, "��� ����", RGB(0, 0, 0), 60);
	}

	//����â �ѱ��
	void LeftPage() 
	{
		//game::texts = "����";
		screenIndex--;
	}

	void RightPage() 
	{
		game::texts = "������";
		screenIndex++;
	}

	//�ٱ��� ���Ʒ��� �̵��ϱ�
	void UpBasket() 
	{
		game::texts = "����";
		basketIndex--;
	}

	void DownBasket()
	{
		game::texts = "�Ʒ���: ";
		basketIndex++;
	}

	//���ÿϷ��ư
	void Selected() 
	{
		game::texts = "�Ϸ�";
	}

}
