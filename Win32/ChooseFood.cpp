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
	int num = 0;

	int screenIndex = 0;
	int basketIndex = 0;
	int index;
	button::DragDrop* draggingButton = nullptr;

	int originXPos = 0;
	int originYPos = 0;
	int soupBNum = 0; // �����ٱ��� �ε���
	int decoBNum = 0; //���ٱ��� �ε���
	button::DragDrop noodleInBasket[1];
	button::DragDrop soupInBasket[6];
	button::DragDrop decorationInBasket[8];

	button::Button buttonList[5] =
	{
		button::Button("���ʹ�ư",80,500,100,100,LeftPage),
		button::Button("�����ʹ�ư",1280, 500, 100, 100, RightPage),
		button::Button("���ʹ�ư",1500,100, 100, 100, UpBasket),
		button::Button("�Ʒ��ʹ�ư",1500, 900, 100, 100,DownBasket),
		button::Button("�Ϸ��ư",1650, 50, 200, 100, Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop(Types::Noodle::FLAT,"���۸�",300,400, 200, 200,Test),
		button::DragDrop(Types::Noodle::MIDDLE,"�⺻��",650, 600, 200, 200, Test),
		button::DragDrop(Types::Noodle::SMALL,"�Ҹ�", 1000, 400, 200, 200, Test),
	};
	button::DragDrop soupButtonList[11] =
	{
		button::DragDrop(Types::Soup::MAULCHI,"��ġ",300,400, 200, 200,Test),
		button::DragDrop(Types::Soup::DASIMA,"��ġ",380, 600, 200, 200, Test),
		button::DragDrop(Types::Soup::TZUYU,"��ġ",460, 400, 200, 200,Test),
		button::DragDrop(Types::Soup::SALT,"��ġ",540, 600, 200, 200, Test),
		button::DragDrop(Types::Soup::MU,"��ġ",620, 400, 200, 200,Test),
		button::DragDrop(Types::Soup::GUKSAUCE,"��ġ",700, 600, 200, 200, Test),
		button::DragDrop(Types::Soup::DRYDIPORI,"��ġ",780, 400, 200, 200, Test),
		button::DragDrop(Types::Soup::DRYMUSHROOMS,"��ġ",860, 600, 200, 200,Test),
		button::DragDrop(Types::Soup::GATHOBUSI,"��ġ",940, 400, 200, 200, Test),
		button::DragDrop(Types::Soup::SUGAR,"��ġ",1000, 600, 200, 200, Test),
		button::DragDrop(Types::Soup::HUCHU,"��ġ",1080, 400, 200, 200, Test),
	};

	button::DragDrop decorationButtonList[17] =
	{
		button::DragDrop(Types::Decoration::DAEPA,"����",300,400, 200, 200, Test),
		button::DragDrop(Types::Decoration::SICHIME,"����",380, 600, 200, 200,Test),
		button::DragDrop(Types::Decoration::CHUPA,"����",460, 400, 200, 200,Test),
		button::DragDrop(Types::Decoration::PYOGO,"����",540, 600, 200, 200,Test),
		button::DragDrop(Types::Decoration::PANGE,"����",620, 400, 200, 200,Test),
		button::DragDrop(Types::Decoration::FIREMEET,"����",700, 600, 200, 200, Test),
		button::DragDrop(Types::Decoration::YANGPA,"����",780, 400, 200, 200,Test),
		button::DragDrop(Types::Decoration::DOOBU,"����",860, 600, 200, 200,Test),
		button::DragDrop(Types::Decoration::HOBAK,"����",940, 400, 200, 200,Test),
		button::DragDrop(Types::Decoration::YUBU,"����",1000, 600, 200, 200,Test),
		button::DragDrop(Types::Decoration::GOCHIAMUK,"����",380, 200, 200, 200, Test),
		button::DragDrop(Types::Decoration::SUKK,"����",540, 200, 200, 200,Test),
		button::DragDrop(Types::Decoration::GOCHUGARU,"����",700, 200, 200, 200,Test),
		button::DragDrop(Types::Decoration::CHOUNGYANGGOCHU,"����",860, 200, 200, 200,Test),
		button::DragDrop(Types::Decoration::SUNKIM,"����",1000, 200, 200, 200, Test),
		button::DragDrop(Types::Decoration::FLATAMUK,"����",540, 800, 200, 200, Test),
		button::DragDrop(Types::Decoration::SHRIMP,"����",700, 800, 200, 200, Test),
	};

	void InitScreen() {
		noodleInBasket[0] = button::DragDrop(Types::Basket::BASKET, "�ٱ���", 1485, 200, 100, 100, basketfunction);
		for (int i = 0; i < 6; i++)
			soupInBasket[i] = button::DragDrop(Types::Basket::BASKET, "�ٱ���", 1485, 200 + (150 * i), 100, 100, basketfunction);
		for (int i = 0; i < 8; i++)
			decorationInBasket[i] = button::DragDrop(Types::Basket::BASKET, "�ٱ���", 1485, 200 + (150 * i), 100, 100, basketfunction);
	}
	//��� �̹��� �׸���
	void ChooseScreen()
	{		
		LoadData::imageManager->DrawBitMapImage("�̴ϰ���", 0, 0);
		LoadData::imageManager->DrawBitMapImage("����", 100, 100);

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
			if (buttonList[i].CheckClick(dx, dy) && draggingButton == nullptr)
			{
				buttonList[i].PlayFunction();
			}
		}

	}
	//-------------
	void CheckDragButton(int dx, int dy) {
		if (draggingButton == nullptr) { //�巡������ ��ư�� ���� ��쿡�� �˻�
			if (screenIndex == 0) {
				for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++)
				{
					if (noodleButtonList[i].isShowing && noodleButtonList[i].CheckDrag(dx, dy))
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
			else if(screenIndex == 1) {
				for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
				{
					if (soupButtonList[i].isShowing && (soupButtonList[i].CheckDrag(dx, dy)))
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
			else {
				for (int i = 0; i < sizeof(decorationButtonList) / sizeof(button::DragDrop); i++)
				{
					if (decorationButtonList[i].isShowing && (decorationButtonList[i].CheckDrag(dx, dy)))
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
		else {
			draggingButton->PlayFunction();
		}
	}
	void CheckDropButton(int dx, int dy)
	{	////�� ������ �ϳ��� �ǹǷ� ����� 1�̴�.
		if (draggingButton != nullptr && screenIndex == 0)
		{
			if (draggingButton->isDragging)
			{
				//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
				int currentX = draggingButton->getXPos();
				int currentY = draggingButton->getYPos();
				//���� �ȿ� ������ �ٱ��Ϲ�ư�� ���� ����ǰ� 
				if ((currentX > noodleInBasket[0].getXPos() - 130 && currentY > noodleInBasket[0].getYPos() - 120) && (currentX < noodleInBasket[0].getXPos() + 130 && currentY < noodleInBasket[0].getYPos() + 120) && noodleInBasket[0].nameTag == Types::Basket::BASKET)
				{
					int ingredient = draggingButton->nameTag;
					noodleInBasket[0].nameTag = ingredient;
					noodleInBasket[0].name = draggingButton->name;
					////�ٱ��Ϲ�ư�� �̹������� �����ϰ� ���� ���� �Ⱥ��̵��� ����.
					draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
					draggingButton->isShowing = false;
					draggingButton->canClick = false;
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
				//break;
			}
		}
		////������� ���ú��ʹ� �������� �����ϹǷ� �ٱ��� �ε����� �������Ѿ��Ѵ�.
		if (draggingButton != nullptr && screenIndex == 1)
		{
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
			{
			if ((draggingButton->isDragging))// && (draggingButton->canClick))// && (draggingButton->isShowing))
			{
				//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
				int currentX = draggingButton->getXPos();
				int currentY = draggingButton->getYPos();
				//���� �ȿ� ������ ���������� ������� �ٱ��Ϲ�ư�� ���� ����ǰ� 6�������� �����ϴ�
				if ((currentX > soupInBasket[0].getXPos() - 130 && currentY > soupInBasket[0].getYPos() - 120) && soupBNum != 6)
				{
					soupInBasket[soupBNum].nameTag = draggingButton->nameTag;
					soupInBasket[soupBNum].name = draggingButton->name;
					////�ٱ��� �ε��� ������Ű��.
					soupBNum++;
					draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
					draggingButton->isShowing = false;
					draggingButton->canClick = false;
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
			{	//�ٱ��Ͽ� ���� �̹� ���� �̹����� �Ⱥ��̰� �� ��쿡�� �巡�װ� �����ʵ��� ���� �߰�
			if ((draggingButton->isDragging))//&& (draggingButton->canClick))// && (draggingButton->isShowing))
			{
				//������ġ �˻��Ͽ�, �ٱ��� ���� ��� �ٱ��Ͽ� �� �ѱ��.
				int currentX = draggingButton->getXPos();
				int currentY = draggingButton->getYPos();
				//���� �ȿ� ������ ���������� ������� �ٱ��Ϲ�ư�� ���� ����ǰ� it's able until 8
				if ((currentX > decorationInBasket[0].getXPos() - 130 && currentY > decorationInBasket[0].getYPos() - 120) && decoBNum != 8)
				{
					decorationInBasket[decoBNum].nameTag = draggingButton->nameTag;
					decorationInBasket[decoBNum].name = draggingButton->name;
					////�ٱ��� �ε��� ������Ű��.
					decoBNum++;

					draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
					draggingButton->isShowing = false;
					draggingButton->canClick = false;
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
			if (noodleInBasket[0].nameTag != Types::Basket::BASKET&&noodleInBasket[0].CheckClick(dx, dy))
			{
				for (int i = 0; i < 3; i++)
				{
					if (noodleButtonList[i].nameTag == noodleInBasket[0].nameTag)
					{
						noodleButtonList[i].isShowing = true;
						noodleButtonList[i].canClick = true;
						noodleButtonList[i].setSize(200, 200);
						noodleInBasket[0].nameTag = Types::Basket::BASKET;
						noodleInBasket[0].name = "�ٱ���";
					}
				}
			}
		}
		//���� �ٱ���
		else if (screenIndex == 1)
		{
			int temp = 0;
			////���� �ٱ��� 6��.
			for (int i = 0; i < 6; i++)
			{
				if (soupInBasket[i].nameTag != Types::Basket::BASKET && soupInBasket[i].CheckClick(dx, dy))
				{	////���� ��� 11��.
					for (int j = 0; j < 11; j++)
					{
						if (soupButtonList[j].nameTag == soupInBasket[i].nameTag)
						{
							soupButtonList[j].isShowing = true;
							soupButtonList[j].canClick = true;
							soupButtonList[j].setSize(200, 200);
							soupInBasket[i].nameTag = Types::Basket::BASKET;
							soupInBasket[i].name = "�ٱ���";
							soupBNum--;//�ٽ����� �ε����� ���̱�
							temp = i;
							while (temp <= 4)
							{
								soupInBasket[temp].nameTag = soupInBasket[temp + 1].nameTag; // ��ĭ�� �� �����.
								soupInBasket[temp].name = soupInBasket[temp + 1].name;
								soupInBasket[temp + 1].nameTag = Types::Basket::BASKET;
								temp++;
							}
							break;
						}
					}
				}
			}
		}
		//��� �ٱ���
		else
		{	
			int temp = 0;
			////��� �ٱ��� 8 ��.
			for (int i = 0; i < 8; i++)
			{
				if (decorationInBasket[i].nameTag != Types::Basket::BASKET && decorationInBasket[i].CheckClick(dx, dy) )
				{	////��� ��� 17��.
					for (int j = 0; j < 17; j++)
					{
						if (decorationButtonList[j].nameTag == decorationInBasket[i].nameTag)
						{
							decorationButtonList[j].isShowing = true;
							decorationButtonList[j].canClick = true;
							decorationButtonList[j].setSize(200, 200);
							decorationInBasket[i].nameTag = Types::Basket::BASKET;
							decorationInBasket[i].name = "�ٱ���";
							decoBNum--;//�ٽ����� �ε����� ���̱�
							temp = i;
							while (temp <= 6)
							{
								decorationInBasket[temp].nameTag = decorationInBasket[temp + 1].nameTag; // ��ĭ�� �� �����.
								decorationInBasket[temp].name = decorationInBasket[temp + 1].name;
								decorationInBasket[temp + 1].nameTag = Types::Basket::BASKET;
								temp++;
							}
							break;
						}

					}

				}
			}
			
		}

	}
	void NoodleScreen()
	{
		////�ٱ��� �׷����ֱ�.
		render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true);
		////��ᰡ �������� �ٱ��� ���� ��Ḧ ����.
		if (noodleInBasket[0].nameTag != Types::Basket::BASKET)
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
		for (int i = 0; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 + (i * 150), true);
		}
		////��ᰡ �������� �ٱ��� ���� ��Ḧ ����.
		for (int i = 0; i < 6; i++)
		{	////y��ǥ���� 100���� �۰ų� 900���� ũ�� �������� �ʵ��� ��.
			soupInBasket[i].setYPos(basketIndex);
			if ((soupInBasket[i].nameTag != Types::Basket::BASKET) && soupInBasket[i].getYPos() > 100 && soupInBasket[i].getYPos() < 900)
			{
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
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 + (i * 150), true);
		}
		//��� ��� ���
		for (int i = 0; i < 8; i++)
		{	////y��ǥ���� 100���� �۰ų� 900���� ũ�� �������� �ʵ��� ��.
			decorationInBasket[i].setYPos(basketIndex);
			if ((decorationInBasket[i].nameTag != Types::Basket::BASKET) && decorationInBasket[i].getYPos() > 100 && decorationInBasket[i].getYPos() < 900)
			{
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

	void basketfunction() {}
	//���ÿϷ��ư
	void Selected()
	{
		game::texts = "�Ϸ�";
		//���� ��� ����
		Types::Noodle noodle; //��
		std::vector <Types::Decoration> decoration; //���(������)
		std::vector <Types::Soup> soup; //����(������)
		noodle = (Types::Noodle)(noodleInBasket[0].nameTag);

		for (int i = 0; i < 6; i++) {
			soup.push_back((Types::Soup)(soupInBasket[i].nameTag));
		}
		for (int i = 0; i < 8; i++) {
			decoration.push_back((Types::Decoration)(decorationInBasket[i].nameTag));
		}
		PlayerData::player.SetChooseFood(noodle, decoration, soup);
		Screen::SetScreen();
	}
}
