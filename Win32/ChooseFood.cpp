#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include <string>
#include "InputSystem.h"

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
	DRYPYOGO,//말린버섯
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
		button::Button("왼쪽",80,500,100,100, L"resource\\object\\left.bmp",LeftPage),
		button::Button("오른쪽",1280, 500, 100, 100, L"resource\\object\\right.bmp",RightPage),
		button::Button("위쪽",1500,100, 100, 100, L"resource\\object\\up.bmp",UpBasket),
		button::Button("아래쪽",1500, 900, 100, 100, L"resource\\object\\down.bmp",DownBasket),
		button::Button("완료",1650, 50, 200, 100, L"resource\\background\\back.bmp",Selected),
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
		//배경 이미지 그리기
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
		//바구니 그리기


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
			//현재 상태에 따라 이동 화살표 작동 여부 설정
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
		if (draggingButton == nullptr) { //드래그중인 버튼이 없는 경우에만 검사
			for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 0)
				{
					if (noodleButtonList[i].CheckDrag(dx, dy))
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
			for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 1)
				{
					if (soupButtonList[i].CheckDrag(dx, dy))
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
			for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 2)
				{
					if (decortaionButtonList[i].CheckDrag(dx, dy))
					{
						//draggingButton에 저장.
						draggingButton = &decortaionButtonList[i];
						//isDragging=true로 변경
						draggingButton->isDragging = true;
						//이동..함수..
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
						//현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						//현재 야매로 되어있움 야호
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
						//바구니 안이 아닌경우 원래자리로 돌아가기.
						else
						{
							draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
							draggingButton->width = 300;
							draggingButton->height = 300;
						}
						//noodleButtonList[i]getdragg6ing ==false로변경
						draggingButton->isDragging = false;
						//draggingButton에 있는 값 없애기
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
						//현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						//현재 야매로 되어있움 야호
						if (currentX > 1485 - 130 && currentY > 200 - 120)
						{
							draggingButton->setPos(soupInBasket[bNum].getXPos(), soupInBasket[bNum].getYPos());
							draggingButton->width = 100;
							draggingButton->height = 100;
							soupInBasket[bNum] = *draggingButton;
							bNum++;
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
			for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::DragDrop); i++)
			{
				if (screenIndex == 2)
				{
					if (draggingButton->isDragging)
					{
						//현재위치 검사하여, 바구니 안인 경우 바구니에 값 넘기기.
						int currentX = draggingButton->getXPos();
						int currentY = draggingButton->getYPos();
						//현재 야매로 되어있움 야호
						if (currentX > 1485 - 130 && currentY > 200 - 120)
						{
							draggingButton->setPos(decortaionInBasket[bNum].getXPos(), decortaionInBasket[bNum].getYPos());
							draggingButton->width = 100;
							draggingButton->height = 100;
							decortaionInBasket[bNum] = *draggingButton;
							bNum++;
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
	}

	//우클릭시 바구니 위에 있던 그림이 사라지고, 그 그림의 인덱스와 같은 재료가 원위치에서 보이게 된다.
	void CheckCancelButton(int dx, int dy) 
	{
		//누들바구니 한개.


		//육수 바구니

		//고명 바구니

	}
	
	//면, 육수, 고명 선택 화면 출력
	void NoodleScreen()
	{
		
		render::DrawTextF(130, 90, "면 선택", RGB(0, 0, 0), 60);
		//바구니에 재료가 들어가 있는 경우 재료도 함께 출력(임시로 인덱스 출력하였음)
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
		render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200, true); //바구니 그려져있기.
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
		//면 재료 출력

	}

	void SoupScreen()
	{
		
		render::DrawTextF(130, 90, "육수 선택", RGB(0, 0, 0), 60);
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
			//바구니에 재료가 들어가 있는 경우 재료도 함께 출력(임시로 인덱스 출력하였음)
		}
		//육수 재료 출력

	}

	void DecorationScreen()
	{
		
		render::DrawTextF(130, 90, "고명 선택", RGB(0, 0, 0), 60);
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
	
				render::DrawTextF(1535, 200 - ((basketIndex - i) * 150), std::to_string(i).c_str(), RGB(0, 0, 0), 60);
				render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
		//바구니에 재료가 들어가 있는 경우 재료도 함께 출력(임시로 인덱스 출력하였음)

		}
		//고명 재료 출력
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
		noddleInBasket[bNum].setPos(1500, 200 + 150 * (bNum + basketIndex));
	}

	void DownBasket()
	{
		game::texts = "아래쪽: ";
		basketIndex++;
		noddleInBasket[bNum].setPos(1500, 200 + 150 * (bNum - basketIndex));
	}

	//선택완료버튼
	void Selected()
	{
		game::texts = "완료";
	}
}
