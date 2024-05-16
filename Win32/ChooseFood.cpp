#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include <string>
#include "InputSystem.h"
//면 종류
enum Noodle 
{
	FLAT, //납작면 0
	MIDDLE, //중면 1 
	SMALL,//소면 2
};

//육수 종류
enum Soup 
{
	MAULCHI,//멸치 3
	SALT,//소금 4
	TZUYU,//쯔유
	GUKSAUCE,//국간장
	DASIMA,//다시마
	MU,//무
	DRYDIPORI,//말린디포리
	DRYMUSHROOMS,//말린버섯
	GATHOBUSI,//가쓰오부시
	SUGAR,//설탕
	HUCHU,//후추
};

//고명 종류
enum Decoration 
{
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
		button::Button("왼쪽",80,500,100,100, "resource/object/left.bmp",LeftPage),
		button::Button("오른쪽",1280, 500, 100, 100, "resource/object/right.bmp",RightPage),
		button::Button("위쪽",1500,100, 100, 100, "resource/object/up.bmp",UpBasket),
		button::Button("아래쪽",1500, 900, 100, 100, "resource/object/down.bmp",DownBasket),
		button::Button("완료",1650, 50, 200, 100, "resource/background/back.bmp",Selected),
	};

	button::DragDrop noodleButtonList[3] =
	{
		button::DragDrop("납작면",300,400, 300, 300, "resource/object/Prriceshrimp.bmp",Test),
		button::DragDrop("기본면",650, 600, 300, 300, "resource/object/Prriceshrimp.bmp", Test),
		button::DragDrop("소면",1000, 400, 300, 300, "resource/object/Prriceshrimp.bmp", Test),
	};

	button::DragDrop soupButtonList[11] =
	{
		button::DragDrop("멸치",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::DragDrop("건다시마",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::DragDrop("쯔유",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("소금",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("무",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("국간장",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("마른 디포리",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("건표고버섯",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("가쓰오부시",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("설탕",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("진간장",1080, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	button::DragDrop decortaionButtonList[17] =
	{
		button::DragDrop("대파",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::DragDrop("시치미",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::DragDrop("쪽파",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("표고버섯",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("팽이버섯",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("직화고기",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("양파",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("두부",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("호박",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("썬유부",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("꼬치어묵",380, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("쑥갓",540, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("고춧가루",700, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("청양고추",860, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("썬김(김채)",1000, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("납작어묵",540, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::DragDrop("새우튀김",700, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	void ChooseScreen() 
	{
		//배경 이미지 그리기
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
		//바구니 그리기
		for (int i = basketIndex; i < basketIndex + 5; i++)
		{
			render::DrawBackGround("resource/object/basket.bmp", 150, 100, 1485, 200 - ((basketIndex - i) * 150), true);
			//바구니에 재료가 들어가 있는 경우 재료도 함께 출력(임시로 인덱스 출력하였음)
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
			if (buttonList[i].CheckClick(dx, dy))
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
				if (screenIndex == 0)
				{
					if (noodleButtonList[i].CheckDrag(dx, dy))
					{
						//draggingButton에 저장.
						draggingButton = &noodleButtonList[i];
						//isDragging=true로 변경
						draggingButton->isDragging = true;
						//이동..함수..
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
						//현재위치 검사하여, 바구니 안인 경우 뭐였지.
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
						//바구니 안이 아닌경우 원래자리로 돌아가기.

						//noodleButtonList[i]getdragging ==false로변경
						draggingButton->isDragging = false;
						//draggingButton에 있는 값 없애기
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
						//현재위치 검사하여, 바구니 안인 경우 뭐였지.
						//바구니 안이 아닌경우 원래자리로 돌아가기.
						//noodleButtonList[i]getdragging ==false로변경
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
						//현재위치 검사하여, 바구니 안인 경우 뭐였지.
						//바구니 안이 아닌경우 원래자리로 돌아가기.
						//noodleButtonList[i]getdragging ==false로변경
						//draggingButton에 있는 값 없애기
						draggingButton = nullptr;
						break;
					}
				}
			}
		}
	}

	//면, 육수, 고명 선택 화면
	void NoodleScreen() 
	{
		render::DrawTextF(130, 90, L"면 선택", RGB(0, 0, 0), 60);
		//면 재료 출력
		for (int i = 0; i < sizeof(noodleButtonList) / sizeof(button::Button); i++)
		{
			noodleButtonList[i].DrawButton();
		}
	}

	void SoupScreen() 
	{
		render::DrawTextF(130, 90, L"육수 선택", RGB(0, 0, 0), 60);
		//육수 재료 출력
		for (int i = 0; i < sizeof(soupButtonList) / sizeof(button::Button); i++)
		{
			soupButtonList[i].DrawButton();
		}
	}

	void DecorationScreen() 
	{
		render::DrawTextF(130, 90, L"고명 선택", RGB(0, 0, 0), 60);
		//고명 재료 출력
		for (int i = 0; i < sizeof(decortaionButtonList) / sizeof(button::Button); i++)
		{
			decortaionButtonList[i].DrawButton();
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
