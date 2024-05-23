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
    int soupBNum = 0; // 육수바구니 인덱스
    int decoBNum = 0; //고명바구니 인덱스
    button::DragDrop noodleInBasket[1];
    button::DragDrop soupInBasket[4];
    button::DragDrop decorationInBasket[8];


    button::Button buttonList[5] =
    {
       button::Button("왼쪽버튼",80,500,100,100,LeftPage),
       button::Button("오른쪽버튼",1800, 500, 100, 100, RightPage),
       button::Button("위쪽버튼",1550,100, 100, 100, UpBasket),
       button::Button("아래쪽버튼",1550, 900, 100, 100,DownBasket),
       button::Button("요리시작", 1650, 950, 200, 70, Selected),
    };
    button::DragDrop noodleButtonList[3];
    button::DragDrop soupButtonList[4];
    button::DragDrop decorationButtonList[13];

	void InitScreen() {

        LoadData::soundManager->PlayMusic(Music::eSoundList::choose, Music::eSoundChannel::BGM);
		noodleButtonList[0] = button::DragDrop(Types::Noodle::FLAT, "납작면", 300, 600, 2.5, 1.5, Test);
		noodleButtonList[1] = button::DragDrop(Types::Noodle::MIDDLE, "기본면", 650, 700, 2.5, 1.5, Test);
		noodleButtonList[2] = button::DragDrop(Types::Noodle::SMALL, "소면", 1000, 600, 2.5, 1.5, Test);


		soupButtonList[0] = button::DragDrop(Types::Soup::MAULCHI, "멸치", 250, 600, 2, 2, Test);
		soupButtonList[1] = button::DragDrop(Types::Soup::DASIMA, "건다시마", 500, 600, 2, 2, Test);
		soupButtonList[2] = button::DragDrop(Types::Soup::TZUYU, "쯔유", 750, 600, 1.5, 3, Test);
		soupButtonList[3] = button::DragDrop(Types::Soup::MU, "무", 1000, 600, 2.5, 1.5, Test);

		decorationButtonList[0] = button::DragDrop(Types::Decoration::SUNDAEPA, "썬대파", 250, 350, 2, 1, Test);
		decorationButtonList[1] = button::DragDrop(Types::Decoration::SICHIME, "시치미", 500, 350, 1, 2, Test);
		decorationButtonList[2] = button::DragDrop(Types::Decoration::BANDALAMUK,"반달어묵", 750, 350, 2, 1.5, Test);
		decorationButtonList[3] = button::DragDrop(Types::Decoration::PYOGO, "표고버섯", 1000, 350, 2, 2, Test);
		decorationButtonList[4] = button::DragDrop(Types::Decoration::FIREMEET,"직화고기", 150, 550, 2.5, 1.5, Test);
		decorationButtonList[5] = button::DragDrop(Types::Decoration::GATHOBUSI, "가쓰오부시", 400, 550, 2, 2, Test);
		decorationButtonList[6] = button::DragDrop(Types::Decoration::YUBU, "썬유부", 650, 550, 2, 2, Test);
		decorationButtonList[7] = button::DragDrop(Types::Decoration::SUKK, "쑥갓", 900, 550, 2, 2, Test);
		decorationButtonList[8] = button::DragDrop(Types::Decoration::CHOUNGYANGGOCHU, "썬청양고추", 1150, 550, 1.2, 1.2, Test);
		decorationButtonList[9] = button::DragDrop(Types::Decoration::SUNKIM, "썬김(김채)", 150, 750, 2, 1.5, Test);
		decorationButtonList[10] = button::DragDrop(Types::Decoration::FLATAMUK, "납작어묵", 400, 750, 2.5, 1.2, Test);
		decorationButtonList[11] = button::DragDrop(Types::Decoration::SHRIMP, "새우튀김", 650, 750, 3, 2, Test);
		decorationButtonList[12] = button::DragDrop(Types::Decoration::FRYGARU,"튀김가루", 900, 750, 2, 1.5, Test);

		noodleInBasket[0] = button::DragDrop(Types::Basket::BASKET, "바구니", 1555, 210, 2, 2, basketfunction);
		for (int i = 0; i < 4; i++)
			soupInBasket[i] = button::DragDrop(Types::Basket::BASKET, "바구니", 1565, 210 + (i * 150), 2, 2, basketfunction);
		for (int i = 0; i < 8; i++)
			decorationInBasket[i] = button::DragDrop(Types::Basket::BASKET, "바구니", 1560, 200 + (i * 150), 2, 2, basketfunction);
	}
	//배경 이미지 그리기
	void ChooseScreen()
	{		
		LoadData::imageManager->DrawBitMapImage("미니게임", 0, 0);
        LoadData::imageManager->DrawPngImage("재료담는바구니", 100, 100, 1300, 900, true);


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

        //버튼 그리기
        for (int i = 0; i < sizeof(buttonList) / sizeof(button::Button); i++)
        {
            //현재 상태에 따라 이동 화살표 보여주기 여부 설정
            if ((screenIndex == 0 && i == 0) || (screenIndex == 2 && i == 1) || (basketIndex == 0 && i == 2) || (basketIndex == 10 && i == 3) || (screenIndex == 0 && i == 3) || (screenIndex == 1 && i == 3))
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
            //현재 상태에 따라 이동 화살표 작동 여부 설정
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
        if (draggingButton == nullptr) { //드래그중인 버튼이 없는 경우에만 검사
            if (screenIndex == 0) {
                for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++)
                {
                    if (noodleButtonList[i].isShowing && noodleButtonList[i].CheckDrag(dx, dy))
                    {
                        //draggingButton에 저장. 
                        draggingButton = &noodleButtonList[i];
                        //isDragging=true로 변경
                        draggingButton->isDragging = true;
                        //이동..함수..
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
                        //draggingButton에 저장.
                        draggingButton = &soupButtonList[i];
                        //isDragging=true로 변경
                        draggingButton->isDragging = true;
                        //이동..함수..
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
                        //draggingButton에 저장.
                        draggingButton = &decorationButtonList[i];

                        //isDragging=true로 변경
                        draggingButton->isDragging = true;
                        //이동..함수..
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
    {   ////면 선택은 하나만 되므로 사이즈가 1이다.
        if (draggingButton != nullptr && screenIndex == 0)
        {
            if (draggingButton->isDragging)
            {
                //현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
                int currentX = draggingButton->getXPos();
                int currentY = draggingButton->getYPos();
                //범위 안에 들어오면 바구니버튼에 값이 저장되고 
                if ((currentX > noodleInBasket[0].getXPos() - 130 && currentY > noodleInBasket[0].getYPos() - 120) && (currentX < noodleInBasket[0].getXPos() + 130 && currentY < noodleInBasket[0].getYPos() + 120) && noodleInBasket[0].nameTag == Types::Basket::BASKET)
                {
                    noodleInBasket[0].nameTag = draggingButton->nameTag;
                    noodleInBasket[0].name = draggingButton->name;
                    noodleInBasket[0].setSize(draggingButton->getOriginWidth(), draggingButton->getOriginHeight());
                    noodleInBasket[0].SetImage(50, 50);
                    ////바구니버튼에 이미지값을 전달하고 나서 재료는 안보이도록 설정.
                    draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
                    draggingButton->isShowing = false;
                    draggingButton->canClick = false;
                }
                //바구니 안이 아닌경우 원래자리로 돌아가기.
                else
                {
                    draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
                    draggingButton->SetImage(100, 100);
                }
                //noodleButtonList[i]getdragg6ing ==false로변경
                draggingButton->isDragging = false;
                //draggingButton에 있는 값 없애기
                draggingButton = nullptr;
                //break;
            }
        }
        ////육수재료 선택부터는 여러개가 가능하므로 바구니 인덱스를 증가시켜야한다.
        if (draggingButton != nullptr && screenIndex == 1)
        {
            for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
            {
                if ((draggingButton->isDragging))// && (draggingButton->canClick))// && (draggingButton->isShowing))
                {
                    //현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
                    int currentX = draggingButton->getXPos();
                    int currentY = draggingButton->getYPos();
                    //범위 안에 들어오면 위에서부터 순서대로 바구니버튼에 값이 저장되고 6개까지만 가능하다
                    if ((currentX > soupInBasket[0].getXPos() - 130 && currentY > soupInBasket[0].getYPos() - 120) && soupBNum != 6)
                    {
                        soupInBasket[soupBNum].nameTag = draggingButton->nameTag;
                        soupInBasket[soupBNum].name = draggingButton->name;
                        soupInBasket[soupBNum].setSize(draggingButton->getOriginWidth(), draggingButton->getOriginHeight());
                        soupInBasket[soupBNum].SetImage(70, 70);
                        ////바구니 인덱스 증가시키기.
                        soupBNum++;
                        draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
                        draggingButton->isShowing = false;
                        draggingButton->canClick = false;
                    }
                    //바구니 안이 아닌경우 원래자리로 돌아가기.
                    else
                    {
                        draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
                        draggingButton->SetImage(100, 100);
                    }
                    //noodleButtonList[i]getdragging ==false로변경
                    draggingButton->isDragging = false;
                    //draggingButton에 있는 값 없애기
                    draggingButton = nullptr;
                    break;
                }
            }
        }
        if (draggingButton != nullptr && screenIndex == 2)
        {
            for (int i = 0; i < sizeof(decorationButtonList) / sizeof(button::DragDrop); i++)
            {   //바구니에 값이 이미 들어가서 이미지가 안보이게 된 경우에는 드래그가 되지않도록 조건 추가
                if ((draggingButton->isDragging))//&& (draggingButton->canClick))// && (draggingButton->isShowing))
                {
                    //현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
                    int currentX = draggingButton->getXPos();
                    int currentY = draggingButton->getYPos();
                    //범위 안에 들어오면 위에서부터 순서대로 바구니버튼에 값이 저장되고 it's able until 8
                    if ((currentX > decorationInBasket[0].getXPos() - 130 && currentY > decorationInBasket[0].getYPos() - 120) && decoBNum != 8)
                    {
                        decorationInBasket[decoBNum].nameTag = draggingButton->nameTag;
                        decorationInBasket[decoBNum].name = draggingButton->name;
                        decorationInBasket[decoBNum].setSize(draggingButton->getOriginWidth(), draggingButton->getOriginHeight());
                        decorationInBasket[decoBNum].SetImage(50, 50);
                        ////바구니 인덱스 증가시키기.
                        decoBNum++;

                        draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
                        draggingButton->isShowing = false;
                        draggingButton->canClick = false;
                    }
                    //바구니 안이 아닌경우 원래자리로 돌아가기.
                    else
                    {
                        draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
                        draggingButton->SetImage(100, 100);
                    }
                    //noodleButtonList[i]getdragging ==false로변경
                    draggingButton->isDragging = false;
                    //draggingButton에 있는 값 없애기
                    draggingButton = nullptr;
                    break;
                }
            }
        }
    }

	//우클릭시 바구니 위에 있던 그림이 사라지고, 그 그림의 인덱스와 같은 재료가 원위치에서 보이게 된다.
	void CheckCancelButton(int dx, int dy)
	{
		//누들바구니 한개.
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
						noodleButtonList[i].SetImage(100, 100);
						noodleInBasket[0].nameTag = Types::Basket::BASKET;
						noodleInBasket[0].name = "바구니";
					}
				}
			}
		}
		//육수 바구니
		else if (screenIndex == 1)
		{
			int temp = 0;
            ////육수 바구니 6개.
			for (int i = 0; i < 4; i++)
			{
				if (soupInBasket[i].nameTag != Types::Basket::BASKET && soupInBasket[i].CheckClick(dx, dy))
				{	////육수 재료 11개.
					for (int j = 0; j < 4; j++)
					{
						if (soupButtonList[j].nameTag == soupInBasket[i].nameTag)
						{
							soupButtonList[j].isShowing = true;
							soupButtonList[j].canClick = true;
							soupButtonList[j].SetImage(100, 100);
							soupInBasket[i].nameTag = Types::Basket::BASKET;
							soupInBasket[i].name = "바구니";
							soupBNum--;//바스켓의 인덱스값 줄이기
							temp = i;
							while (temp <= 2)
							{
								soupInBasket[temp].nameTag = soupInBasket[temp + 1].nameTag; // 한칸씩 값 땡기기.
								soupInBasket[temp].name = soupInBasket[temp + 1].name;
                                soupInBasket[temp].setSize(soupInBasket[temp + 1].getOriginWidth(), soupInBasket[temp + 1].getOriginHeight());
								soupInBasket[temp + 1].nameTag = Types::Basket::BASKET;
								temp++;
							}
							break;
						}
					}
				}
			}
		}
		//고명 바구니
		else
		{	
			int temp = 0;
			////고명 바구니 8 개.
			for (int i = 0; i < 8; i++)
			{
				if (decorationInBasket[i].nameTag != Types::Basket::BASKET && decorationInBasket[i].CheckClick(dx, dy) )
				{	////고명 재료 14개.
					for (int j = 0; j < 13; j++)
					{
						if (decorationButtonList[j].nameTag == decorationInBasket[i].nameTag)
						{
							decorationButtonList[j].isShowing = true;
							decorationButtonList[j].canClick = true;
							decorationButtonList[j].SetImage(100, 100);
							decorationInBasket[i].nameTag = Types::Basket::BASKET;
							decorationInBasket[i].name = "바구니";
							decoBNum--;//바스켓의 인덱스값 줄이기
							temp = i;
							while (temp <= 6)
							{
								decorationInBasket[temp].nameTag = decorationInBasket[temp + 1].nameTag; // 한칸씩 값 땡기기.
								decorationInBasket[temp].name = decorationInBasket[temp + 1].name;
                                decorationInBasket[temp].setSize(decorationInBasket[temp + 1].getOriginWidth(), decorationInBasket[temp + 1].getOriginHeight());
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
        ////바구니 그려져있기.
        LoadData::imageManager->DrawPngImage("바구니", 1455, 170 , 330, 150, 1.0f, true);
        ////재료가 들어가있으면 바구니 위에 재료를 띄우기.
        if (noodleInBasket[0].nameTag != Types::Basket::BASKET)
        {
            noodleInBasket[0].SetImage(50, 50);
            noodleInBasket[0].DrawButton();
        }
        ////면 재료 출력- 바구니에 들어가서 안보이게 된것들은 IsShowing = FALSE
        for (int i = 0; i < 3; i++)
        {
            if (noodleButtonList[i].isShowing == true)
            {
                noodleButtonList[i].SetImage(100, 100);
                noodleButtonList[i].DrawButton();
            }
        }
    }

	void SoupScreen()
	{
		////바구니 그려져있기.
		for (int i = 0; i < 4; i++)
		{
            LoadData::imageManager->DrawPngImage("바구니", 1455, 170 + (i * 150), 330, 150, 1.0f, true);
		}
		////재료가 들어가있으면 바구니 위에 재료를 띄우기.
		for (int i = 0; i < 4; i++)
		{	////y좌표값이 100보다 작거나 900보다 크면 랜더되지 않도록 함.
            soupInBasket[i].SetImage(50, 50);
			soupInBasket[i].setYPos(basketIndex);
			if ((soupInBasket[i].nameTag != Types::Basket::BASKET) && soupInBasket[i].getYPos() > 100 && soupInBasket[i].getYPos() < 900)
			{
				soupInBasket[i].DrawButton();
			}
		}
		////육수 재료 출력- 바구니에 들어가서 안보이게 된것들은 isShowing = FALSE로 되어있음.
		for (int i = 0; i < 4; i++)
		{
			if (soupButtonList[i].isShowing == true)
			{
                soupButtonList[i].SetImage(100, 100);
				soupButtonList[i].DrawButton();
			}
		}
	}

	void DecorationScreen()
	{
		////바구니 그려져있기.
		for (int i = 0; i < 5; i++)
		{
            LoadData::imageManager->DrawPngImage("바구니", 1455, 170 + (i * 150), 330, 150, 1.0f, true);
		}
		//고명 재료 출력
		for (int i = 0; i < 8; i++)
		{	////y좌표값이 100보다 작거나 900보다 크면 랜더되지 않도록 함.
            decorationButtonList[i].SetImage(50, 50);
			decorationInBasket[i].setYPos(basketIndex);
			if ((decorationInBasket[i].nameTag != Types::Basket::BASKET) && decorationInBasket[i].getYPos() > 100 && decorationInBasket[i].getYPos() < 900)
			{
				decorationInBasket[i].DrawButton();
			}
		}
		////고명 재료 출력- 바구니에 들어가서 안보이게 된것들은 isShowing = FALSE로 되어있음.
		for (int i = 0; i < 13; i++)
		{
			if (decorationButtonList[i].isShowing == true)
			{
                decorationButtonList[i].SetImage(100, 100);
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
                draggingButton->SetImage(120,120);
                draggingButton->setPos(xPos, yPos);
            }
        }
    }

    //선택창 넘기기
    void LeftPage()
    {
        game::texts = "왼쪽";
        screenIndex--;
    }

    void RightPage()
    {
        game::texts = "오른쪽";
        screenIndex++;
    }

    //바구니 위아래로 이동하기
    void UpBasket()
    {
        game::texts = "위쪽";
        basketIndex--;
    }

    void DownBasket()
    {
        game::texts = "아래쪽: ";
        basketIndex++;
    }

    void basketfunction() {}
    //선택완료버튼
    void Selected()
    {
        game::texts = "완료";
        //담은 재료 종류
        Types::Noodle noodle; //면
        std::vector <Types::Decoration> decoration; //고명(여러개)
        std::vector <Types::Soup> soup; //육수(여러개)
        noodle = (Types::Noodle)(noodleInBasket[0].nameTag);

		for (int i = 0; i < 4; i++) {
			soup.push_back((Types::Soup)(soupInBasket[i].nameTag));
		}
		for (int i = 0; i < 8; i++) {
            if (decorationInBasket[i].nameTag != 31) {
                decoration.push_back((Types::Decoration)(decorationInBasket[i].nameTag));
            }
		}
		PlayerData::player.SetChooseFood(noodle, decoration, soup);

        screenIndex = 0;
        basketIndex = 0;
        soupBNum = 0; // 육수바구니 인덱스
        decoBNum = 0; //고명바구니 인덱스

		Screen::SetScreen();
	}
}
