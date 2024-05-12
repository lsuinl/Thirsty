#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "GameManager.h"

//면 종류
enum Noodle 
{
	wow,
	suin,
	ee,
};

//육수 종류
enum Soup 
{
	bi,
	in,
};

//고명 종류
enum Decoration 
{
	wowff,
};

namespace ChooseFood
{
	Noodle noodle;
	Soup soup[];
	Decoration decortaion[];
	int screenIndex = 0, basketIndex = 0;
	button::Button buttonList[5] =
	{
		button::Button("왼쪽",80,500,100,100, "resource/background/back.bmp",LeftPage),
		button::Button("오른쪽",1280, 500, 100, 100, "resource/background/back.bmp",RightPage),
		button::Button("위쪽",1600,100, 100, 100, "resource/background/back.bmp",UpBasket),
		button::Button("아래쪽",1600, 900, 100, 100, "resource/background/back.bmp",DownBasket),
		button::Button("완료",1700, 950, 100, 100, "resource/background/back.bmp",Selected),
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
		render::DrawTextF(130, 90, "면 선택", RGB(0, 0, 0), 60);
	}

	void SoupScreen() 
	{
		render::DrawTextF(130, 90, "육수 선택", RGB(0, 0, 0), 60);
	}

	void DecorationScreen() 
	{
		render::DrawTextF(130, 90, "고명 선택", RGB(0, 0, 0), 60);
	}

	//선택창 넘기기
	void LeftPage() 
	{
		//game::texts = "왼쪽";
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
