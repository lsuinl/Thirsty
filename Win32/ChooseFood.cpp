#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include <string>
#include "InputSystem.h"
//�� ����
enum Noodle 
{
	FLAT, //���۸� 0
	MIDDLE, //�߸� 1 
	SMALL,//�Ҹ� 2
};

//���� ����
enum Soup 
{
	MAULCHI,//��ġ 3
	SALT,//�ұ� 4
	TZUYU,//����
	GUKSAUCE,//������
	DASIMA,//�ٽø�
	MU,//��
	DRYDIPORI,//����������
	DRYMUSHROOMS,//��������
	GATHOBUSI,//�������ν�
	SUGAR,//����
	HUCHU,//����
};

//��� ����
enum Decoration 
{
	DAEPA,//���� 
	SICHIME,//��ġ��
	CHUPA,//����
	PYOGO,//ǥ��
	PANGE,//����
	FIREMEET,//��ȭ���
	YANGPA,//����
	DOOBU,//�κ�
	HOBAK,//ȣ��
	YUBU,//����
	GOCHIAMUK,//��ġ�
	SUKK,//����
	GOCHUGARU,//���߰���
	CHOUNGYANGGOCHU,//û�����
	SUNKIM,//���
	FLATAMUK,//���۾
	SHRIMP,//����Ƣ��
};

namespace ChooseFood
{
	Noodle noodle;
	Soup soup[];
	Decoration decortaion[];
	int screenIndex = 0, basketIndex = 0;
	int index;
	button::DragDrop* draggingButton;

	int originXPos = 0;
	int originYPos = 0;
	int bNum = 0;
	button::DragDrop* basket[15];

	button::Button buttonList[5] =
	{
		button::Button("����",80,500,100,100, "resource/object/left.bmp",LeftPage),
		button::Button("������",1280, 500, 100, 100, "resource/object/right.bmp",RightPage),
		button::Button("����",1500,100, 100, 100, "resource/object/up.bmp",UpBasket),
		button::Button("�Ʒ���",1500, 900, 100, 100, "resource/object/down.bmp",DownBasket),
		button::Button("�Ϸ�",1650, 50, 200, 100, "resource/background/back.bmp",Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop("���۸�",300,400, 300, 300, "resource/object/Prriceshrimp.bmp",Test),
		button::DragDrop("�⺻��",650, 600, 300, 300, "resource/object/Prriceshrimp.bmp", Test),
		button::DragDrop("�Ҹ�",1000, 400, 300, 300, "resource/object/Prriceshrimp.bmp", Test),
	};

	button::DragDrop soupButtonList[11] =
	{
		button::DragDrop("��ġ",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::DragDrop("�Ǵٽø�",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::DragDrop("����",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("�ұ�",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("��",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("������",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("���� ������",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("��ǥ�����",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("�������ν�",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("����",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("������",1080, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	button::DragDrop decortaionButtonList[17] =
	{
		button::DragDrop("����",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::DragDrop("��ġ��",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::DragDrop("����",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("ǥ�����",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("���̹���",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("��ȭ���",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("����",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("�κ�",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("ȣ��",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("������",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("��ġ�",380, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("����",540, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("���尡��",700, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("û�����",860, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("���(��ä)",1000, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("���۾",540, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("����Ƣ��",700, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	void ChooseScreen() 
	{
		//��� �̹��� �׸���
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
		//�ٱ��� �׸���
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
			render::DrawBackGround("resource/object/basket.bmp", 150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
			//�ٱ��Ͽ� ��ᰡ �� �ִ� ��� ��ᵵ �Բ� ���(�ӽ÷� �ε��� ����Ͽ���)
			if (basket[i] == nullptr)
			{
				render::DrawTextF(1535, 200 - ((basketIndex - i) * 150), std::to_wstring(i).c_str(), RGB(0, 0, 0), 60);
			}

		}

		if (screenIndex==0)
		{
			NoodleScreen();
		}
		else if (screenIndex == 1)
		{
			SoupScreen();
		}
		else if (screenIndex == 2)
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
			if (buttonList[i].CheckClick(dx, dy))
			{
				buttonList[i].PlayFunction();
			}
		}
			
	}
	//-------------
	void CheckDragButton(int dx, int dy) {
		if (draggingButton == nullptr) { //�巡������ ��ư�� ���� ��쿡�� �˻�
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::Button); i++)
			{
				if (screenIndex == 0)
				{
					if (noodleButtonList[i].CheckDrag(dx, dy))
					{
						//draggingButton�� ����.
						draggingButton = &noodleButtonList[i];
						//isDragging=true�� ����
						draggingButton->isDragging = true;
						//�̵�..�Լ�..
						input::UpdateMouse();
						const input::MouseState& mouse = input::GetMouseState();
						int xPos = mouse.x - 130;
						int yPos = mouse.y - 120;
						noodleButtonList[i].PlayFunction();
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::Button); i++)
			{
				if (screenIndex == 1)
				{
					if (soupButtonList[i].CheckDrag(dx, dy))
					{
						soupButtonList[i].PlayFunction();
					}
				}
			}
			for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::Button); i++)
			{
				if (screenIndex == 2)
				{
					if (decortaionButtonList[i].CheckDrag(dx, dy))
					{
						decortaionButtonList[i].PlayFunction();
					}
				}
			}
		}
		else {
			draggingButton->PlayFunction();
		}
	}
	void CheckDropButton(int dx, int dy) 
	{
		if (draggingButton != nullptr) 
		{
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::Button); i++)
			{
				if (screenIndex == 0)
				{
					if (draggingButton->isDragging)
					{
						//������ġ �˻��Ͽ�, �ٱ��� ���� ��� ������.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						if (currentX > 1485-130 && currentY > 200-120)
						{
							draggingButton->setPos(1500, 200);
							draggingButton->width = 100;
							draggingButton->height = 100;
							basket[bNum] = draggingButton;
							bNum++;
						}
						//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.

						//noodleButtonList[i]getdragging ==false�κ���
						draggingButton->isDragging = false;
						//draggingButton�� �ִ� �� ���ֱ�
						draggingButton = nullptr;
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::Button); i++)
			{
				if (screenIndex == 1)
				{
					if (soupButtonList[i].isDragging)
					{
						//������ġ �˻��Ͽ�, �ٱ��� ���� ��� ������.
						//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
						//noodleButtonList[i]getdragging ==false�κ���
						draggingButton = nullptr;
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::Button); i++)
			{
				if (screenIndex == 2)
				{
					if (decortaionButtonList[i].isDragging)
					{
						//������ġ �˻��Ͽ�, �ٱ��� ���� ��� ������.
						//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
						//noodleButtonList[i]getdragging ==false�κ���
						//draggingButton�� �ִ� �� ���ֱ�
						draggingButton = nullptr;
						break;
					}
				}
			}
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

	void Test()
	{
		if (draggingButton->isDragging) {
			input::UpdateMouse();
			const input::MouseState& mouse = input::GetMouseState();

			int xPos = mouse.x - 130;
			int yPos = mouse.y - 120;
			if (input::GetMouseState().isDragging)
			{

				draggingButton->setPos(xPos, yPos);
			}
		}
	}
}
