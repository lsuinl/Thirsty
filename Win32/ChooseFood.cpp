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
enum Ingredients
{
	FLAT, //납작면 0
	MIDDLE, //중면 1 
	SMALL,//소면 2


	MAULCHI,//멸치 3 
	SALT,//소금 4
	TZUYU,//쯔유 5
	GUKSAUCE,//국간장 6
	DASIMA,//다시마 7
	MU,//무
	DRYDIPORI,//말린디포리
	DRYMUSHROOMS,//말린버섯
	GATHOBUSI,//가쓰오부시
	SUGAR,//설탕
	HUCHU,//후추


	DAEPA,//대파 
	SICHIME,//시치미
	CHUPA,//쪽파
	PYOGO,//표고
	PANGE,//팽이
	FIREMEET,//직화고기
	YANGPA,//양파
	DOOBU,//두부
	HOBAK,//호박
	YUBU,//유부
	GOCHIAMUK,//꼬치어묵
	SUKK,//쑥갓
	GOCHUGARU,//고추가루
	CHOUNGYANGGOCHU,//청양고추
	SUNKIM,//썬김
	FLATAMUK,//납작어묵
	SHRIMP,//새우튀김

	BASKET,//바구니
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
	int soupBNum = 0; // 육수바구니 인덱스
	int decoBNum = 0; //고명바구니 인덱스
	button::DragDrop noodleInBasket[1];
	button::DragDrop soupInBasket[6];
	button::DragDrop decorationInBasket[8];

	button::Button buttonList[5] =
	{
		button::Button("왼쪽버튼",80,500,100,100,LeftPage),
		button::Button("오른쪽버튼",1280, 500, 100, 100, RightPage),
		button::Button("위쪽버튼",1500,100, 100, 100, UpBasket),
		button::Button("아래쪽버튼",1500, 900, 100, 100,DownBasket),
		button::Button("완료버튼",1650, 50, 200, 100, Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop(FLAT,"납작면",300,400, 200, 200,Test),
		button::DragDrop(MIDDLE,"기본면",650, 600, 200, 200, Test),
		button::DragDrop(SMALL,"소면", 1000, 400, 200, 200, Test),
	};
	button::DragDrop soupButtonList[11] =
	{
		button::DragDrop(MAULCHI,"멸치",300,400, 200, 200,Test),
		button::DragDrop(DASIMA,"멸치",380, 600, 200, 200, Test),
		button::DragDrop(TZUYU,"멸치",460, 400, 200, 200,Test),
		button::DragDrop(SALT,"멸치",540, 600, 200, 200, Test),
		button::DragDrop(MU,"멸치",620, 400, 200, 200,Test),
		button::DragDrop(GUKSAUCE,"멸치",700, 600, 200, 200, Test),
		button::DragDrop(DRYDIPORI,"멸치",780, 400, 200, 200, Test),
		button::DragDrop(DRYMUSHROOMS,"멸치",860, 600, 200, 200,Test),
		button::DragDrop(GATHOBUSI,"멸치",940, 400, 200, 200, Test),
		button::DragDrop(SUGAR,"멸치",1000, 600, 200, 200, Test),
		button::DragDrop(HUCHU,"멸치",1080, 400, 200, 200, Test),
	};

	button::DragDrop decorationButtonList[17] =
	{
		button::DragDrop(DAEPA,"쪽파",300,400, 200, 200, Test),
		button::DragDrop(SICHIME,"쪽파",380, 600, 200, 200,Test),
		button::DragDrop(CHUPA,"쪽파",460, 400, 200, 200,Test),
		button::DragDrop(PYOGO,"쪽파",540, 600, 200, 200,Test),
		button::DragDrop(PANGE,"쪽파",620, 400, 200, 200,Test),
		button::DragDrop(FIREMEET,"쪽파",700, 600, 200, 200, Test),
		button::DragDrop(YANGPA,"쪽파",780, 400, 200, 200,Test),
		button::DragDrop(DOOBU,"쪽파",860, 600, 200, 200,Test),
		button::DragDrop(HOBAK,"쪽파",940, 400, 200, 200,Test),
		button::DragDrop(YUBU,"쪽파",1000, 600, 200, 200,Test),
		button::DragDrop(GOCHIAMUK,"쪽파",380, 200, 200, 200, Test),
		button::DragDrop(SUKK,"쪽파",540, 200, 200, 200,Test),
		button::DragDrop(GOCHUGARU,"쪽파",700, 200, 200, 200,Test),
		button::DragDrop(CHOUNGYANGGOCHU,"쪽파",860, 200, 200, 200,Test),
		button::DragDrop(SUNKIM,"쪽파",1000, 200, 200, 200, Test),
		button::DragDrop(FLATAMUK,"쪽파",540, 800, 200, 200, Test),
		button::DragDrop(SHRIMP,"쪽파",700, 800, 200, 200, Test),
	};

	void InitScreen() {
		noodleInBasket[0] = button::DragDrop(BASKET, "바구니", 1485, 200, 100, 100, Selected);
		for (int i = 0; i < 6; i++)
			soupInBasket[i] = button::DragDrop(BASKET, "바구니", 1485, 200 + (150 * i), 100, 100, Selected);
		for (int i = 0; i < 8; i++)
			decorationInBasket[i] = button::DragDrop(BASKET, "바구니", 1485, 200 + (150 * i), 100, 100, Selected);
	}

	void ChooseScreen() 
	{
		//배경 이미지 그리기
		LoadData::imageManager->DrawBitMapImage("미니게임", 0,0);
		LoadData::imageManager->DrawBitMapImage("도마", 100,100);

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

		//버튼 그리기
		for (int i = 0; i < sizeof(buttonList)/sizeof(button::Button); i++)
		{
			//현재 상태에 따라 이동 화살표 보여주기 여부 설정
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
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::Button); i++)
			{
				if ((screenIndex == 0) && noodleButtonList[i].CheckDrag(dx, dy))
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
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::Button); i++)
			{
				if ((screenIndex == 1) && (soupButtonList[i].CheckDrag(dx, dy)))
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
			for (int i = 0; i < sizeof(decorationButtonList) / sizeof(button::DragDrop); i++)
			{
				if ((screenIndex == 2) && (decorationButtonList[i].CheckDrag(dx, dy)))
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
		else {
			draggingButton->PlayFunction();
		}
	}
	void CheckDropButton(int dx, int dy)
	{	////면 선택은 하나만 되므로 사이즈가 1이다.
		if (draggingButton != nullptr && screenIndex == 0)
		{
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++)
			{
				if (draggingButton->isDragging)
				{
					//현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();
					//범위 안에 들어오면 바구니버튼에 값이 저장되고 
					if ((currentX > noodleInBasket[0].getXPos() - 130 && currentY > noodleInBasket[0].getYPos() - 120) && (currentX < noodleInBasket[0].getXPos() + 130 && currentY < noodleInBasket[0].getYPos() + 120) && noodleInBasket[0].nameTag == BASKET)
					{

						int ingredient = draggingButton->nameTag;
						noodleInBasket[0].nameTag = ingredient;
						noodleInBasket[0].name = draggingButton->name;
						////바구니버튼에 이미지값을 전달하고 나서 재료는 안보이도록 설정.
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->isShowing = false;
					}
					//바구니 안이 아닌경우 원래자리로 돌아가기.
					else
					{
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->width = 200;
						draggingButton->height = 200;
					}
					//noodleButtonList[i]getdragg6ing ==false로변경
					draggingButton->isDragging = false;
					//draggingButton에 있는 값 없애기
					draggingButton = nullptr;
					break;
				}
			}
		}
		////육수재료 선택부터는 여러개가 가능하므로 바구니 인덱스를 증가시켜야한다.
		if (draggingButton != nullptr && screenIndex == 1)
		{
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
			{
				if ((draggingButton->isDragging))// && (draggingButton->isShowing))
				{
					//현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();
					//범위 안에 들어오면 위에서부터 순서대로 바구니버튼에 값이 저장되고 6개까지만 가능하다
					if ((currentX > soupInBasket[0].getXPos() - 130 && currentY > soupInBasket[0].getYPos() - 120) && soupBNum != 6)
					{
						int ingredient = draggingButton->nameTag;
						soupInBasket[soupBNum].nameTag = ingredient;
						soupInBasket[soupBNum].name = draggingButton->name;
						////바구니 인덱스 증가시키기.
						soupBNum++;
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->isShowing = false;
					}
					//바구니 안이 아닌경우 원래자리로 돌아가기.
					else
					{
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->width = 200;
						draggingButton->height = 200;
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
			{	//바구니에 값이 이미 들어가서 이미지가 안보이게 된 경우에는 드래그가 되지않도록 조건 추가
				if ((draggingButton->isDragging))// && (draggingButton->isShowing))
				{
					//현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();
					//범위 안에 들어오면 위에서부터 순서대로 바구니버튼에 값이 저장되고 it's able until 8
					if ((currentX > decorationInBasket[0].getXPos() - 130 && currentY > decorationInBasket[0].getYPos() - 120) && decoBNum != 8)
					{	//같은 값이 들어오지 않도록 하는 검사.

						int ingredient = draggingButton->nameTag;
						decorationInBasket[decoBNum].nameTag = ingredient;
						decorationInBasket[decoBNum].name = draggingButton->name;
						////바구니 인덱스 증가시키기.
						decoBNum++;

						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->isShowing = false;
					}
					//바구니 안이 아닌경우 원래자리로 돌아가기.
					else
					{
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->width = 200;
						draggingButton->height = 200;
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
			if (noodleInBasket[0].CheckClick(dx, dy))
			{
				for (int i = 0; i < 3; i++)
				{
					if (noodleButtonList[i].nameTag == noodleInBasket[0].nameTag)
					{
						noodleButtonList[i].isShowing = true;
						noodleButtonList[i].setSize(200, 200);
						noodleInBasket[0].nameTag = BASKET;
						noodleInBasket[0].name = "바구니";
					}
				}
			}
		}
		//육수 바구니
		if (screenIndex == 1)
		{	////육수 바구니 6개.
			for (int i = 0; i < 6; i++)
			{
				if (soupInBasket[i].CheckClick(dx, dy))
				{	////육수 재료 11개.
					for (int j = 0; j < 11; j++)
					{
						if (soupButtonList[j].nameTag == soupInBasket[i].nameTag)
						{
							soupButtonList[j].isShowing = true;
							soupButtonList[j].setSize(200, 200);
							soupInBasket[i].nameTag = BASKET;
							soupInBasket[i].name = "바구니";
						}
					}
					soupBNum--; //바스켓의 인덱스값 줄이기
					while (i <= 5)
					{
						soupInBasket[i].nameTag = soupInBasket[i + 1].nameTag; // 한칸씩 값 땡기기.
						soupInBasket[i].name = soupInBasket[i + 1].name;
						soupInBasket[i + 1].nameTag = BASKET;
						i++;
					}
				}
			}

		}
		//고명 바구니
		if (screenIndex == 2)
		{	////고명 바구니 8 개.
			for (int i = 0; i < 8; i++)
			{
				if (decorationInBasket[i].CheckClick(dx, dy))
				{	////고명 재료 17개.
					for (int j = 0; j < 17; j++)
					{
						if (decorationButtonList[j].nameTag == decorationInBasket[i].nameTag)
						{
							decorationButtonList[j].isShowing = true;
							decorationButtonList[j].setSize(200, 200);
							decorationInBasket[i].nameTag = BASKET;
							decorationInBasket[i].name = "바구니";
						}
					}
					decoBNum--;
					while (i <= 7)
					{
						decorationInBasket[i].nameTag = decorationInBasket[i + 1].nameTag; // 한칸씩 값 땡기기.
						decorationInBasket[i].name = decorationInBasket[i + 1].name;
						decorationInBasket[i + 1].nameTag = BASKET;
						i++;
					}
				}
			}

		}

	}

	void NoodleScreen()
	{
		////바구니 그려져있기.
		render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true);
		////재료가 들어가있으면 바구니 위에 재료를 띄우기.
		if (noodleInBasket[0].nameTag != BASKET)
		{
			noodleInBasket[0].DrawButton();
		}
		////면 재료 출력- 바구니에 들어가서 안보이게 된것들은 IsShowing = FALSE
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
		////바구니 그려져있기.
		for (int i = 0; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200+(i*150), true);
		}
		////재료가 들어가있으면 바구니 위에 재료를 띄우기.
		for (int i = 0; i < 6; i++)
		{	////y좌표값이 100보다 작거나 900보다 크면 랜더되지 않도록 함.
			soupInBasket[i].setYPos(basketIndex);
			if ((soupInBasket[i].nameTag != BASKET) && soupInBasket[i].getYPos() > 100 && soupInBasket[i].getYPos() < 900)
			{
				soupInBasket[i].DrawButton();
			}
		}
		////육수 재료 출력- 바구니에 들어가서 안보이게 된것들은 isShowing = FALSE로 되어있음.
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
		////바구니 그려져있기.
		for (int i = 0; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200+(i*150), true);
		}
		//고명 재료 출력
		for (int i = 0; i < 8; i++)
		{	////y좌표값이 100보다 작거나 900보다 크면 랜더되지 않도록 함.
			decorationInBasket[i].setYPos(basketIndex);
			if ((decorationInBasket[i].nameTag != BASKET) && decorationInBasket[i].getYPos() > 100 && decorationInBasket[i].getYPos() < 900)
			{
				decorationInBasket[i].DrawButton();
			}
		}
		////육수 재료 출력- 바구니에 들어가서 안보이게 된것들은 isShowing = FALSE로 되어있음.
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
			int xPos = mouse.x - 120;
			int yPos = mouse.y - 120;
			if (input::GetMouseState().isDragging)
			{
				draggingButton->setSize(300, 300);
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

	//선택완료버튼
	void Selected() 
	{
		game::texts = "완료";
		Screen::SetScreen();
	}
}
