#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"
#include "Types.h"
#include "Animations.h"
#include <string>
namespace ChooseFood
{
	Types::Noodle noodle;
	Types::Soup soup[];
	Types::Decoration decortaion[];
	int screenIndex = 0, basketIndex = 0;

	const char* basket[15];
	button::Button buttonList[5] =
	{
		button::Button("왼쪽",80,500,100,100, "resource/object/left.bmp",LeftPage),
		button::Button("오른쪽",1280, 500, 100, 100, "resource/object/right.bmp",RightPage),
		button::Button("위쪽",1500,100, 100, 100, "resource/object/up.bmp",UpBasket),
		button::Button("아래쪽",1500, 900, 100, 100, "resource/object/down.bmp",DownBasket),
		button::Button("완료",1650, 50, 200, 100, "resource/background/back.bmp",Selected),
	};

	button::Button noodleButtonList[3] =
	{
		button::Button("납작면",300,400, 300, 300, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::Button("기본면",650, 600, 300, 300, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::Button("소면",1000, 400, 300, 300, "resource/object/Prriceshrimp.bmp",Selected),
	};

	button::Button soupButtonList[11] =
	{
		button::Button("멸치",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::Button("건다시마",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::Button("쯔유",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("소금",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("무",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("국간장",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("마른 디포리",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("건표고버섯",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("가쓰오부시",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("설탕",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("진간장",1080, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	button::Button decortaionButtonList[17] =
	{
		button::Button("대파",300,400, 200, 200, "resource/object/Prriceshrimp.bmp",UpBasket),
		button::Button("시치미",380, 600, 200, 200, "resource/object/Prriceshrimp.bmp",DownBasket),
		button::Button("쪽파",460, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("표고버섯",540, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("팽이버섯",620, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("직화고기",700, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("양파",780, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("두부",860, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("호박",940, 400, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("썬유부",1000, 600, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("꼬치어묵",380, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("쑥갓",540, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("고춧가루",700, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("청양고추",860, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("썬김(김채)",1000, 200, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("납작어묵",540, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
		button::Button("새우튀김",700, 800, 200, 200, "resource/object/Prriceshrimp.bmp",Selected),
	};

	void ChooseScreen() 
	{
		//배경 이미지 그리기
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
		if (screenIndex==0)
		{
			NoodleScreen();
		}
		else if (screenIndex == 1)
		{
			SoupScreen();
		}
		else
		{
			DecorationScreen();
		}



		//바구니 그리기
		for (int i = basketIndex; i < basketIndex + 5; i++) 
		{
			render::DrawBackGround("resource/object/basket.bmp", 150, 100, 1485, 200-((basketIndex-i)*150), true);
			//바구니에 재료가 들어가 있는 경우 재료도 함께 출력(임시로 인덱스 출력하였음)
			if (basket[i] == NULL) 
			{
				//render::DrawTextF(1535, 200 - ((basketIndex - i) * 150), std::to_string(i).c_str(), RGB(0, 0, 0), 60);
			}
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
			buttonList[i].CheckClick(dx,dy);
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

}
