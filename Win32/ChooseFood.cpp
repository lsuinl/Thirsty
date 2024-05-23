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
    int screenIndex = 0;
    int basketIndex = 0;

    button::DragDrop* draggingButton = nullptr;

    int originXPos = 0;
    int originYPos = 0;
    int soupBNum = 0; // �����ٱ��� �ε���
    int decoBNum = 0; //���ٱ��� �ε���
    button::DragDrop noodleInBasket[1];
    button::DragDrop soupInBasket[4];
    button::DragDrop decorationInBasket[8];


    button::Button buttonList[5] =
    {
       button::Button("���ʹ�ư",80,500,100,100,LeftPage),
       button::Button("�����ʹ�ư",1280, 500, 100, 100, RightPage),
       button::Button("���ʹ�ư",1550,100, 100, 100, UpBasket),
       button::Button("�Ʒ��ʹ�ư",1550, 900, 100, 100,DownBasket),
       button::Button("�丮����", 1650, 950, 200, 70, Selected),
    };
    button::DragDrop noodleButtonList[3];
    button::DragDrop soupButtonList[4];
    button::DragDrop decorationButtonList[14];

	void InitScreen() {
        LoadData::soundManager->PlayMusic(Music::eSoundList::choose, Music::eSoundChannel::BGM);

		noodleButtonList[0] = button::DragDrop(Types::Noodle::FLAT, "���۸�", 300, 600, 200, 200, Test);
		noodleButtonList[1] = button::DragDrop(Types::Noodle::MIDDLE, "�⺻��", 650, 700, 200, 200, Test);
		noodleButtonList[2] = button::DragDrop(Types::Noodle::SMALL, "�Ҹ�", 1000, 600, 200, 200, Test);



		soupButtonList[0] = button::DragDrop(Types::Soup::MAULCHI, "��ġ", 250, 600, 200, 200, Test);
		soupButtonList[1] = button::DragDrop(Types::Soup::DASIMA, "�Ǵٽø�", 500, 600, 200, 200, Test);
		soupButtonList[2] = button::DragDrop(Types::Soup::TZUYU, "����", 750, 600, 200, 200, Test);
		soupButtonList[3] = button::DragDrop(Types::Soup::MU, "��", 1000, 600, 200, 200, Test);

		decorationButtonList[0] = button::DragDrop(Types::Decoration::DAEPA, "����", 250, 350, 200, 200, Test);
		decorationButtonList[1] = button::DragDrop(Types::Decoration::SICHIME, "����", 500, 350, 200, 200, Test);
		decorationButtonList[2] = button::DragDrop(Types::Decoration::BANDALAMUK,"�ݴ޾", 750, 350, 200, 200, Test);
		decorationButtonList[3] = button::DragDrop(Types::Decoration::PYOGO, "ǥ�����", 1000, 350, 200, 200, Test);
		decorationButtonList[4] = button::DragDrop(Types::Decoration::FIREMEET,"��ȭ���", 150, 550, 200, 200, Test);
		decorationButtonList[5] = button::DragDrop(Types::Decoration::GATHOBUSI, "�������ν�", 400, 550, 200, 200, Test);
		decorationButtonList[6] = button::DragDrop(Types::Decoration::YUBU, "������", 650, 550, 200, 200, Test);
		decorationButtonList[7] = button::DragDrop(Types::Decoration::SUKK, "����", 900, 550, 200, 200, Test);
		decorationButtonList[8] = button::DragDrop(Types::Decoration::CHOUNGYANGGOCHU, "��û�����", 1150, 550, 200, 200, Test);
		decorationButtonList[9] = button::DragDrop(Types::Decoration::SUNKIM, "���(��ä)", 150, 750, 200, 200, Test);
		decorationButtonList[10] = button::DragDrop(Types::Decoration::FLATAMUK, "���۾", 400, 750, 200, 200, Test);
		decorationButtonList[11] = button::DragDrop(Types::Decoration::SHRIMP, "����Ƣ��", 650, 750, 200, 200, Test);
		decorationButtonList[12] = button::DragDrop(Types::Decoration::FRYGARU,"Ƣ�谡��", 900, 750, 200, 200, Test);
		decorationButtonList[13] = button::DragDrop(Types::Decoration::SUNDAEPA,"�����", 1150, 750, 200, 200, Test);

		noodleInBasket[0] = button::DragDrop(Types::Basket::BASKET, "�ٱ���", 1555, 180, 120, 120, basketfunction);
		for (int i = 0; i < 4; i++)
			soupInBasket[i] = button::DragDrop(Types::Basket::BASKET, "�ٱ���", 1555, 180 + (i * 150), 120, 120, basketfunction);
		for (int i = 0; i < 8; i++)
			decorationInBasket[i] = button::DragDrop(Types::Basket::BASKET, "�ٱ���", 1555, 180 + (i * 150), 120, 120, basketfunction);
	}
	//��� �̹��� �׸���
	void ChooseScreen()
	{		
		LoadData::imageManager->DrawBitMapImage("�̴ϰ���", 0, 0);
        LoadData::imageManager->DrawPngImage("����¹ٱ���", 100, 100, 1300, 900, true);

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
            else if (screenIndex == 1) {
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
    {   ////�� ������ �ϳ��� �ǹǷ� ����� 1�̴�.
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
            {   //�ٱ��Ͽ� ���� �̹� ���� �̹����� �Ⱥ��̰� �� ��쿡�� �巡�װ� �����ʵ��� ���� �߰�
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
			for (int i = 0; i < 4; i++)
			{
				if (soupInBasket[i].nameTag != Types::Basket::BASKET && soupInBasket[i].CheckClick(dx, dy))
				{	////���� ��� 11��.
					for (int j = 0; j < 4; j++)
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
							while (temp <= 2)
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
				{	////��� ��� 14��.
					for (int j = 0; j < 14; j++)
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
        render::DrawObject(L"resource\\object\\basket.bmp", 330, 150, 1455, 170, true);
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
		for (int i = 0; i < 4; i++)
		{
            render::DrawObject(L"resource\\object\\basket.bmp", 330, 150, 1455, 170 + (i * 150), true);
		}
		////��ᰡ �������� �ٱ��� ���� ��Ḧ ����.
		for (int i = 0; i < 4; i++)
		{	////y��ǥ���� 100���� �۰ų� 900���� ũ�� �������� �ʵ��� ��.
			soupInBasket[i].setYPos(basketIndex);
			if ((soupInBasket[i].nameTag != Types::Basket::BASKET) && soupInBasket[i].getYPos() > 100 && soupInBasket[i].getYPos() < 900)
			{
				soupInBasket[i].DrawButton();
			}
		}
		////���� ��� ���- �ٱ��Ͽ� ���� �Ⱥ��̰� �Ȱ͵��� isShowing = FALSE�� �Ǿ�����.
		for (int i = 0; i < 4; i++)
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
            render::DrawObject(L"resource\\object\\basket.bmp", 330, 150, 1455, 170 + (i * 150), true);
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
		////��� ��� ���- �ٱ��Ͽ� ���� �Ⱥ��̰� �Ȱ͵��� isShowing = FALSE�� �Ǿ�����.
		for (int i = 0; i < 14; i++)
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

		for (int i = 0; i < 4; i++) {
			soup.push_back((Types::Soup)(soupInBasket[i].nameTag));
		}
		for (int i = 0; i < 8; i++) {
			decoration.push_back((Types::Decoration)(decorationInBasket[i].nameTag));
		}
		PlayerData::player.SetChooseFood(noodle, decoration, soup);

        screenIndex = 0;
        basketIndex = 0;
        soupBNum = 0; // �����ٱ��� �ε���
        decoBNum = 0; //���ٱ��� �ε���

		Screen::SetScreen();
	}
}
