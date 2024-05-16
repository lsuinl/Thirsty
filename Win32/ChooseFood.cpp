#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include <string>
#include "InputSystem.h"

enum Ingredients
{
	FLAT, //���۸� 0
	MIDDLE, //�߸� 1 
	SMALL,//�Ҹ� 2


	MAULCHI,//��ġ 3 
	SALT,//�ұ� 4
	TZUYU,//���� 5
	GUKSAUCE,//������ 6
	DASIMA,//�ٽø� 7
	MU,//��
	DRYDIPORI,//����������
	DRYPYOGO,//��������
	GATHOBUSI,//�������ν�
	SUGAR,//����
	HUCHU,//����


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

	BASKET,//�ٱ���
};

namespace ChooseFood
{
	int num = 0;
	
	int screenIndex = 0;
	int basketIndex = 0;
	int index;
	button::DragDrop* draggingButton;

	int originXPos = 0;
	int originYPos = 0;
	int bNum = 0;

	button::DragDrop noddleInBasket[1] =
	{
		button::DragDrop(BASKET,1485,200,100,100, L"resource\\object\\basket.bmp",Selected),
	};
	button::DragDrop soupInBasket[5] =
	{
		button::DragDrop(BASKET,1485,200,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,350,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,500,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,650,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,800,100,100, L"resource\\object\\basket.bmp",Selected),

	};
	button::DragDrop decortaionInBasket[5] =
	{
		button::DragDrop(BASKET,1485,200,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,350,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,500,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,650,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,800,100,100, L"resource\\object\\basket.bmp",Selected),
	};
	button::Button buttonList[5] =
	{
		button::Button("����",80,500,100,100, L"resource\\object\\left.bmp",LeftPage),
		button::Button("������",1280, 500, 100, 100, L"resource\\object\\right.bmp",RightPage),
		button::Button("����",1500,100, 100, 100, L"resource\\object\\up.bmp",UpBasket),
		button::Button("�Ʒ���",1500, 900, 100, 100, L"resource\\object\\down.bmp",DownBasket),
		button::Button("�Ϸ�",1650, 50, 200, 100, L"resource\\background\\back.bmp",Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop(FLAT,300,400, 300, 300, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(MIDDLE,650, 600, 300, 300, L"resource\\object\\Prriceshrimp.bmp", Test),
		button::DragDrop(SMALL, 1000, 400, 300, 300, L"resource\\object\\Prriceshrimp.bmp", Test),
	};
	button::DragDrop soupButtonList[11] =
	{
		button::DragDrop(MAULCHI,300,400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DASIMA,380, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(TZUYU,460, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SALT,540, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(MU,620, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(GUKSAUCE,700, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DRYDIPORI,780, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DRYPYOGO,860, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(GATHOBUSI,940, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SUGAR,1000, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(HUCHU,1080, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
	};

	button::DragDrop decortaionButtonList[17] =
	{
		button::DragDrop(DAEPA,300,400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SICHIME,380, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(CHUPA,460, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(PYOGO,540, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(PANGE,620, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(FIREMEET,700, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(YANGPA,780, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DOOBU,860, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(HOBAK,940, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(YUBU,1000, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(GOCHIAMUK,380, 200, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SUKK,540, 200, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(GOCHUGARU,700, 200, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(CHOUNGYANGGOCHU,860, 200, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SUNKIM,1000, 200, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(FLATAMUK,540, 800, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SHRIMP,700, 800, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
	};

	void ChooseScreen()
	{
		//��� �̹��� �׸���
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
		//�ٱ��� �׸���


		if (screenIndex == 0)
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
		for (int i = 0; i < sizeof(buttonList) / sizeof(button::Button); i++)
		{
			//���� ���¿� ���� �̵� ȭ��ǥ �����ֱ� ���� ����
			if ((screenIndex == 0 && i == 0) || (screenIndex == 2 && i == 1) || (basketIndex == 0 && i == 2) || (basketIndex == 10 && i == 3))
			{
				continue;
			}
			buttonList[i].DrawButton();
		}
	}

	void CheckButton(int dx, int dy)
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
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++)
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
						noodleButtonList[i].PlayFunction();
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 1)
				{
					if (soupButtonList[i].CheckDrag(dx, dy))
					{
						//draggingButton�� ����.
						draggingButton = &soupButtonList[i];
						//isDragging=true�� ����
						draggingButton->isDragging = true;
						//�̵�..�Լ�..
						soupButtonList[i].PlayFunction();
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 2)
				{
					if (decortaionButtonList[i].CheckDrag(dx, dy))
					{
						//draggingButton�� ����.
						draggingButton = &decortaionButtonList[i];
						//isDragging=true�� ����
						draggingButton->isDragging = true;
						//�̵�..�Լ�..
						decortaionButtonList[i].PlayFunction();
						break;
					}
				}
			}
		}
		else
		{
			draggingButton->PlayFunction();
		}
	}
	void CheckDropButton(int dx, int dy)
	{
		if (draggingButton != nullptr)
		{
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 0)
				{
					if (draggingButton->isDragging)
					{
						//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						//���� �߸ŷ� �Ǿ��ֿ� ��ȣ
						if (currentX > noddleInBasket[0].getXPos()-130 && currentY > noddleInBasket[0].getYPos()-120)
						{
							int ingredient = draggingButton->name;
							noddleInBasket[0].num1= ingredient;
							noddleInBasket[0].image = draggingButton->image;

							draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
							draggingButton->IsShowing = false;
							/*noodleButtonList[0].num1 = 0;
							noodleButtonList[1].num1 = 1;
							noodleButtonList[2].num1 = 2;*/
							
							/*draggingButton->setPos(noddleInBasket[bNum].getXPos(), noddleInBasket[bNum].getYPos());
							draggingButton->width = 100;  
							draggingButton->height = 100;
							noddleInBasket[bNum] = *draggingButton;
							bNum++;*/
							
						}
						//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
						else
						{
							draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
							draggingButton->width = 300;
							draggingButton->height = 300;
						}
						//noodleButtonList[i]getdragg6ing ==false�κ���
						draggingButton->isDragging = false;
						//draggingButton�� �ִ� �� ���ֱ�
						draggingButton = nullptr;
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 1)
				{
					if (draggingButton->isDragging)
					{
						//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						//���� �߸ŷ� �Ǿ��ֿ� ��ȣ
						if (currentX > 1485 - 130 && currentY > 200 - 120)
						{
							draggingButton->setPos(soupInBasket[bNum].getXPos(), soupInBasket[bNum].getYPos());
							draggingButton->width = 100;
							draggingButton->height = 100;
							soupInBasket[bNum] = *draggingButton;
							bNum++;
						}
						//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
						else
						{
							draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
							draggingButton->width = 200;
							draggingButton->height = 200;
						}
						//noodleButtonList[i]getdragging ==false�κ���
						draggingButton->isDragging = false;
						//draggingButton�� �ִ� �� ���ֱ�
						draggingButton = nullptr;
						break;
					}
				}
			}
			for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 2)
				{
					if (draggingButton->isDragging)
					{
						//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						//���� �߸ŷ� �Ǿ��ֿ� ��ȣ
						if (currentX > 1485 - 130 && currentY > 200 - 120)
						{
							draggingButton->setPos(decortaionInBasket[bNum].getXPos(), decortaionInBasket[bNum].getYPos());
							draggingButton->width = 100;
							draggingButton->height = 100;
							decortaionInBasket[bNum] = *draggingButton;
							bNum++;
						}
						//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
						else
						{
							draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
							draggingButton->width = 200;
							draggingButton->height = 200;
						}
						//noodleButtonList[i]getdragging ==false�κ���
						draggingButton->isDragging = false;
						//draggingButton�� �ִ� �� ���ֱ�
						draggingButton = nullptr;
						break;
					}
				}
			}
		}
	}

	//��Ŭ���� �ٱ��� ���� �ִ� �׸��� �������, �� �׸��� �ε����� ���� ��ᰡ ����ġ���� ���̰� �ȴ�.
	void CheckCancelButton(int dx, int dy) 
	{
		//����ٱ��� �Ѱ�.


		//���� �ٱ���

		//��� �ٱ���

	}
	
	//��, ����, ��� ���� ȭ�� ���
	void NoodleScreen()
	{
		
		render::DrawTextF(130, 90, "�� ����", RGB(0, 0, 0), 60);
		//�ٱ��Ͽ� ��ᰡ �� �ִ� ��� ��ᵵ �Բ� ���(�ӽ÷� �ε��� ����Ͽ���)
		//if (noddleInBasket[0].num1 == 0)
		//{
		//	noddleInBasket[0].image = L"resource\\object\\right.bmp";
		//}
		//else if (noddleInBasket[0].num1 == 1)
		//{
		//	noddleInBasket[0].image = L"resource\\object\\left.bmp";
		//}
		//else if (noddleInBasket[0].num1 == 2)
		//{
		//	noddleInBasket[0].image = L"resource\\object\\up.bmp";
		//}
		render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true); //�ٱ��� �׷����ֱ�.
		if (noddleInBasket[0].num1 != 0)
		{
			noddleInBasket[0].DrawButton();
		}

		for (int i = 0; i < 3; i++)
		{
			if (noodleButtonList[i].IsShowing == true)
			{
				noodleButtonList[i].DrawButton();
			}
	
		}		
		//�� ��� ���

	}

	void SoupScreen()
	{
		
		render::DrawTextF(130, 90, "���� ����", RGB(0, 0, 0), 60);
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
			//�ٱ��Ͽ� ��ᰡ �� �ִ� ��� ��ᵵ �Բ� ���(�ӽ÷� �ε��� ����Ͽ���)
		}
		//���� ��� ���

	}

	void DecorationScreen()
	{
		
		render::DrawTextF(130, 90, "��� ����", RGB(0, 0, 0), 60);
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
	
				render::DrawTextF(1535, 200 - ((basketIndex - i) * 150), std::to_string(i).c_str(), RGB(0, 0, 0), 60);
				render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
		//�ٱ��Ͽ� ��ᰡ �� �ִ� ��� ��ᵵ �Բ� ���(�ӽ÷� �ε��� ����Ͽ���)

		}
		//��� ��� ���
		for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::DragDrop); i++)
		{
			decortaionButtonList[i].DrawButton();
		}
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
		noddleInBasket[bNum].setPos(1500, 200 + 150 * (bNum + basketIndex));
	}

	void DownBasket()
	{
		game::texts = "�Ʒ���: ";
		basketIndex++;
		noddleInBasket[bNum].setPos(1500, 200 + 150 * (bNum - basketIndex));
	}

	//���ÿϷ��ư
	void Selected()
	{
		game::texts = "�Ϸ�";
	}
}
