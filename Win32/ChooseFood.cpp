#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include <string>
#include "InputSystem.h"
#include "ScreenSystem.h"
#include "Types.h"
#include "LoadData.h"
namespace ChooseFood
{
	Types::Noodle noodle;
	Types::Soup soup[];
	Types::Decoration decortaion[];
	int screenIndex = 0, basketIndex = 0;
	int index;
	button::DragDrop* draggingButton;

	int originXPos = 0;
	int originYPos = 0;
	int bNum = 0;
	button::DragDrop* basket[15];

	button::Button buttonList[5] =
	{
		button::Button("���ʹ�ư",80,500,100,100, LeftPage),
		button::Button("�����ʹ�ư",1280, 500, 100, 100, RightPage),
		button::Button("���ʹ�ư",1500,100, 100, 100, UpBasket),
		button::Button("�Ʒ��ʹ�ư",1500, 900, 100, 100,DownBasket),
		button::Button("�Ϸ��ư",1650, 50, 200, 100, Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop("���۸�",300,400, 300, 300, Test),
		button::DragDrop("�⺻��",650, 600, 300, 300,  Test),
		button::DragDrop("�Ҹ�",1000, 400, 300, 300, Test),
	};

	button::DragDrop soupButtonList[5] =
	{
		button::DragDrop("��ġ",300,400, 200, 200,UpBasket),
		button::DragDrop("�Ǵٽø�",380, 600, 200, 200, DownBasket),
		button::DragDrop("����",460, 400, 200, 200,Selected),
		button::DragDrop("��",620, 400, 200, 200,Selected),
		button::DragDrop("�������ν�",940, 400, 200, 200,Selected),
	};

	button::DragDrop decortaionButtonList[10] =
	{
		button::DragDrop("����",300,400, 200, 200,UpBasket),
		button::DragDrop("��ġ��",380, 600, 200, 200,DownBasket),
		button::DragDrop("����",460, 400, 200, 200,Selected),
		button::DragDrop("ǥ�����",540, 600, 200, 200,Selected),
		button::DragDrop("��ȭ���",700, 600, 200, 200,Selected),
		button::DragDrop("������",1000, 600, 200, 200,Selected),
		button::DragDrop("����",540, 200, 200, 200, Selected),
		button::DragDrop("���(��ä)",1000, 200, 200, 200,Selected),
		button::DragDrop("���۾",540, 800, 200, 200,Selected),
		button::DragDrop("����Ƣ��",700, 800, 200, 200,Selected),
	};

	void ChooseScreen() 
	{
		//��� �̹��� �׸���
		LoadData::imageManager->DrawBitMapImage("�̴ϰ���", 0,0);
		render::DrawBackGround("resource/object/doma.bmp", 1000, 700, 100, 100, false);
		//�ٱ��� �׸���
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
			LoadData::imageManager->DrawPngImage("�ٱ���",150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
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
		Screen::SetScreen();
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
