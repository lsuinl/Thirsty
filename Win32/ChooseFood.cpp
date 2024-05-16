#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include "Types.h"
#include "Animations.h"
#include <string>
namespace ChooseFood
{
	Types::Noodle noodle;
	Types::Soup soup[];
	Types::Decoration decortaion[];
	int screenIndex = 0, basketIndex = 0;

	const char* basket[15];
	button::Button buttonList[5] =
	{
		button::Button("����",80,500,100,100, "resource/object/left.bmp",LeftPage),
		button::Button("������",1280, 500, 100, 100, "resource/object/right.bmp",RightPage),
		button::Button("����",1500,100, 100, 100, "resource/object/up.bmp",UpBasket),
		button::Button("�Ʒ���",1500, 900, 100, 100, "resource/object/down.bmp",DownBasket),
		button::Button("�Ϸ�",1650, 50, 200, 100, "resource/background/back.bmp",Selected),
	};

	button::Button noodleButtonList[3] =
	{
		button::Button("���۸�",300,400, 300, 300, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::Button("�⺻��",650, 600, 300, 300, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::Button("�Ҹ�",1000, 400, 300, 300, "resource/object/Prriceshrimp.bmp",Selected),
	};

	button::Button soupButtonList[11] =
	{
		button::Button("��ġ",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::Button("�Ǵٽø�",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::Button("����",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("�ұ�",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("��",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("������",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("���� ������",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("��ǥ�����",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("�������ν�",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("����",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("������",1080, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	button::Button decortaionButtonList[17] =
	{
		button::Button("����",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::Button("��ġ��",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::Button("����",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("ǥ�����",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("���̹���",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("��ȭ���",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("����",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("�κ�",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("ȣ��",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("������",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("��ġ�",380, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("����",540, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("���尡��",700, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("û�����",860, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("���(��ä)",1000, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("���۾",540, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("����Ƣ��",700, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
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



		//�ٱ��� �׸���
		for (int i = basketIndex; i < basketIndex + 5; i++) 
		{
			render::DrawBackGround("resource/object/basket.bmp", 150, 100, 1485, 200-((basketIndex-i)*150), true);
			//�ٱ��Ͽ� ��ᰡ �� �ִ� ��� ��ᵵ �Բ� ���(�ӽ÷� �ε��� ����Ͽ���)
			if (basket[i] == NULL) 
			{
				//render::DrawTextF(1535, 200 - ((basketIndex - i) * 150), std::to_string(i).c_str(), RGB(0, 0, 0), 60);
			}
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
		render::DrawTextF(130, 90, L"�� ����", RGB(0, 0, 0), 60);
		//�� ��� ���
		for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::Button); i++)
		{
			noodleButtonList[i].DrawButton();
		}
	}

	void SoupScreen() 
	{
		render::DrawTextF(130, 90, L"���� ����", RGB(0, 0, 0), 60);
		//���� ��� ���
		for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::Button); i++)
		{
			soupButtonList[i].DrawButton();
		}
	}

	void DecorationScreen() 
	{
		render::DrawTextF(130, 90, L"��� ����", RGB(0, 0, 0), 60);
		//��� ��� ���
		for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::Button); i++)
		{
			decortaionButtonList[i].DrawButton();
		}
	}

	//����â �ѱ��
	void LeftPage() 
	{
		game::texts = "����";
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
