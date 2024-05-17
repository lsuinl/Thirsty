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
	DRYMUSHROOMS,//��������
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
	int soupBNum = 0; // �����ٱ��� �ε���
	int decoBNum = 0; //���ٱ��� �ε���

	button::DragDrop noodleInBasket[1] ={
		button::DragDrop(BASKET,1485,200,100,100, L"resource\\object\\basket.bmp",Selected),
	};
	button::DragDrop soupInBasket[6] =
	{
		button::DragDrop(BASKET,1485,200,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,350,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,500,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,650,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,800,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,950,100,100, L"resource\\object\\basket.bmp",Selected),


	};
	button::DragDrop decorationInBasket[8] =
	{
		button::DragDrop(BASKET,1485,200,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,350,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,500,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,650,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,800,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,950,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,1100,100,100, L"resource\\object\\basket.bmp",Selected),
		button::DragDrop(BASKET,1485,1250,100,100, L"resource\\object\\basket.bmp",Selected),

	};
	button::Button buttonList[5] =
	{
		button::Button("����",80,500,100,100, L"resource\\object\\left.png",LeftPage),
		button::Button("������",1280, 500, 100, 100, L"resource\\object\\right.png",RightPage),
		button::Button("����",1500,100, 100, 100, L"resource\\object\\up.png",UpBasket),
		button::Button("�Ʒ���",1500, 900, 100, 100, L"resource\\object\\down.png",DownBasket),
		button::Button("�Ϸ�",1650, 50, 200, 100, L"resource\\background\\back.png",Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop(FLAT,300,400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(MIDDLE,650, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp", Test),
		button::DragDrop(SMALL, 1000, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp", Test),
	};
	button::DragDrop soupButtonList[11] =
	{
		button::DragDrop(MAULCHI,300,400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DASIMA,380, 600, 200, 200, L"resource\\object\\right.png",Test),
		button::DragDrop(TZUYU,460, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SALT,540, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(MU,620, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(GUKSAUCE,700, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DRYDIPORI,780, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(DRYMUSHROOMS,860, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(GATHOBUSI,940, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(SUGAR,1000, 600, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
		button::DragDrop(HUCHU,1080, 400, 200, 200, L"resource\\object\\Prriceshrimp.bmp",Test),
	};

	button::DragDrop decorationButtonList[17] =
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
			if (buttonList[i].CheckClick(dx, dy)&& draggingButton == nullptr)
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
			for (int i = 0; i < sizeof(decorationButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 2)
				{
					if (decorationButtonList[i].CheckDrag(dx, dy))
					{
						//draggingButton�� ����.
						draggingButton = &decorationButtonList[i];
						//isDragging=true�� ����
						draggingButton->isDragging = true;
						//�̵�..�Լ�..
						decorationButtonList[i].PlayFunction();
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
	{	////�� ������ �ϳ��� �ǹǷ� ����� 1�̴�.
		if (draggingButton != nullptr&&screenIndex == 0)
		{
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++) 
			{
				if (draggingButton->isDragging)
				{
					//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();
					//���� �ȿ� ������ �ٱ��Ϲ�ư�� ���� ����ǰ� 
					if ((currentX > noodleInBasket[0].getXPos() - 130 && currentY > noodleInBasket[0].getYPos() - 120) && (currentX < noodleInBasket[0].getXPos() + 130 && currentY < noodleInBasket[0].getYPos() + 120) && noodleInBasket[0].nameTag == BASKET)
					{
						int ingredient = draggingButton->name;
						noodleInBasket[0].nameTag = ingredient;
						noodleInBasket[0].image = draggingButton->image;
						////�ٱ��Ϲ�ư�� �̹������� �����ϰ� ���� ���� �Ⱥ��̵��� ����.
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->isShowing = false;
					}
					//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
					else
					{
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->width = 200;
						draggingButton->height = 200;
					}
					//noodleButtonList[i]getdragg6ing ==false�κ���
					draggingButton->isDragging = false;
					//draggingButton�� �ִ� �� ���ֱ�
					draggingButton = nullptr;
					break;
				}
			}
		}
		////������� ���ú��ʹ� �������� �����ϹǷ� �ٱ��� �ε����� �������Ѿ��Ѵ�.
		if (draggingButton != nullptr && screenIndex == 1)
		{
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
			{
				if (draggingButton->isDragging)
				{
					//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();
					//���� �ȿ� ������ ���������� ������� �ٱ��Ϲ�ư�� ���� ����ǰ�
					if ((currentX > soupInBasket[0].getXPos() - 130 && currentY > soupInBasket[0].getYPos() - 120) && soupBNum != 7)
					{
						int ingredient = draggingButton->name;
						soupInBasket[soupBNum].nameTag = ingredient;
						soupInBasket[soupBNum].image = draggingButton->image;
						////�ٱ��� �ε��� ������Ű��.
						soupBNum++;

						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->isShowing = false;
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
		if (draggingButton != nullptr && screenIndex == 2)
		{
			for (int i = 0; i < sizeof(decorationButtonList) / sizeof(button::DragDrop); i++)
			{
				if (draggingButton->isDragging)
				{
					//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();
					//���� �ȿ� ������ ���������� ������� �ٱ��Ϲ�ư�� ���� ����ǰ�
					if ((currentX > decorationInBasket[0].getXPos() - 130 && currentY > decorationInBasket[0].getYPos() - 120) && decoBNum != 9)
					{
						int ingredient = draggingButton->name;
						decorationInBasket[soupBNum].nameTag = ingredient;
						decorationInBasket[soupBNum].image = draggingButton->image;
						////�ٱ��� �ε��� ������Ű��.
						decoBNum++;

						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->isShowing = false;
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

	//��Ŭ���� �ٱ��� ���� �ִ� �׸��� �������, �� �׸��� �ε����� ���� ��ᰡ ����ġ���� ���̰� �ȴ�.
	void CheckCancelButton(int dx, int dy) 
	{
		//����ٱ��� �Ѱ�.
		if (screenIndex == 0) 
		{
			if (noodleInBasket[0].CheckClick(dx, dy))
			{
				for (int i = 0; i < 3; i++)
				{
					if (noodleButtonList[i].name == noodleInBasket[0].nameTag)
					{
						noodleButtonList[i].isShowing = true;
						noodleButtonList[i].setSize(200, 200);
						noodleInBasket[0].nameTag = BASKET;
					}
				}
			}
		}
		//���� �ٱ���
		if (screenIndex == 1)
		{	////���� �ٱ��� 6��.
			for (int i = 0; i < 6; i++)
			{
				if (soupInBasket[i].CheckClick(dx,dy))
				{	////���� ��� 11��.
					for (int j = 0; j < 11; j++)
					{
						if (soupButtonList[j].name == soupInBasket[i].nameTag)
						{
							soupButtonList[j].isShowing = true;
							soupButtonList[j].setSize(200, 200);
							soupInBasket[i].nameTag = BASKET;
						}
					}
					soupBNum--; //�ٽ����� �ε����� ���̱�
					while (i <= 5)
					{
						soupInBasket[i].nameTag = soupInBasket[i + 1].nameTag; // ��ĭ�� �� �����.
						soupInBasket[i].image = soupInBasket[i + 1].image;
						soupInBasket[i + 1].nameTag = BASKET;
						i++;
					}
				}
			}
			
		}		
		//��� �ٱ���
		if (screenIndex == 2)
		{	////��� �ٱ��� 8 ��.
			for (int i = 0; i < 8; i++)
			{
				if (decorationInBasket[i].CheckClick(dx, dy))
				{	////��� ��� 17��.
					for (int j = 0; j < 17; j++)
					{
						if (decorationButtonList[j].name == decorationInBasket[i].nameTag)
						{
							decorationButtonList[j].isShowing = true;
							decorationButtonList[j].setSize(200, 200);
							decorationInBasket[i].nameTag = BASKET;
						}
					}
					decoBNum--;
					while (i <= 7)
					{
						decorationInBasket[i].nameTag = decorationInBasket[i + 1].nameTag; // ��ĭ�� �� �����.
						decorationInBasket[i].image = decorationInBasket[i + 1].image;
						decorationInBasket[i + 1].nameTag = BASKET;
						i++;
					}
				}
			}

		}

	}
	
	//��, ����, ��� ���� ȭ�� ���
	void NoodleScreen()
	{
		////�ٱ��� �׷����ֱ�.
		render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true); 
		////��ᰡ �������� �ٱ��� ���� ��Ḧ ����.
		if (noodleInBasket[0].nameTag != BASKET)
		{
			noodleInBasket[0].DrawButton();
		}
		////�� ��� ���- �ٱ��Ͽ� ���� �Ⱥ��̰� �Ȱ͵��� IsShowing = FALSE
		for (int i = 0; i < 3; i++)
		{
			if (noodleButtonList[i].isShowing == true)
			{
				noodleButtonList[i].DrawButton();
			}	
		}		
	}

	void SoupScreen()
	{				
		////�ٱ��� �׷����ֱ�.
		for (int i = basketIndex; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 350, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 500, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 650, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 800, true);
		}
		////��ᰡ �������� �ٱ��� ���� ��Ḧ ����.
		for (int i =0; i < 6; i++)
		{	////y��ǥ���� 100���� �۰ų� 900���� ũ�� �������� �ʵ��� ��.
			if ((soupInBasket[i].nameTag != BASKET) && soupInBasket[i].getYPos() > 100 && soupInBasket[i].getYPos() < 900)
			{
				soupInBasket[i].setYPos(basketIndex);
				soupInBasket[i].DrawButton();
			}
		}		
		////���� ��� ���- �ٱ��Ͽ� ���� �Ⱥ��̰� �Ȱ͵��� isShowing = FALSE�� �Ǿ�����.
		for (int i = 0; i < 11; i++)
		{ 
			if (soupButtonList[i].isShowing == true)
			{
				soupButtonList[i].DrawButton();
			}
		}
	}

	void DecorationScreen()
	{
		////�ٱ��� �׷����ֱ�.
		for (int i = 0; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 350, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 500, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 650, true);
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 800, true);
		}
		//��� ��� ���
		for (int i = 0; i < 8; i++)
		{	////y��ǥ���� 100���� �۰ų� 900���� ũ�� �������� �ʵ��� ��.
			if ((decorationInBasket[i].nameTag != BASKET) && decorationInBasket[i].getYPos() > 100 && decorationInBasket[i].getYPos() < 900)
			{
				decorationInBasket[i].setYPos(basketIndex);
				decorationInBasket[i].DrawButton();
			}
		}
		////���� ��� ���- �ٱ��Ͽ� ���� �Ⱥ��̰� �Ȱ͵��� isShowing = FALSE�� �Ǿ�����.
		for (int i = 0; i < 17; i++)
		{
			if (decorationButtonList[i].isShowing == true)
			{
				decorationButtonList[i].DrawButton();
			}
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
				draggingButton->setSize(300, 300);
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
