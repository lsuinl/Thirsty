#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"

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
	button::Button buttonList[4] = {
		button::Button("왼쪽",0,0,100,100, "resource/background/back.bmp"), 
		button::Button("오른쪽",0, 100, 100, 100, "resource/background/back.bmp"),
		button::Button("위쪽",0,200, 100, 100, "resource/background/back.bmp"),
		button::Button("아래쪽",0, 300, 100, 100, "resource/background/back.bmp"),
	};
	void CheckButton(int dx,int dy) {
		for (int i = 0; i < 4; i++) 
		{
			buttonList[i].CheckClick(dx,dy);
		}
	}
	//면, 육수, 고명 선택 화면
	void NoodleScreen() 
	{
		render::DrawBackGround("resource/background/back.bmp",1920,1080,0,0,false);
		render::DrawBackGround("resource/background/back.bmp",1300,900,100,100,false);
		render::DrawTextF(130, 90, "면 선택", RGB(0, 0, 0), 60);
		for (int i = 0; i < 4; i++)
		{
			buttonList[i].DrawButton();
		}
	}

	void SoupScreen() 
	{
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
	}

	void DecorationScreen() 
	{
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawBackGround("resource/background/back.bmp", 1300, 900, 100, 100, false);
	}

	//선택창 넘기기
	void LeftPage() 
	{

	}

	void RightPage() 
	{

	}

	//바구니 위아래로 이동하기
	void UpBasket() 
	{

	}

	void DownBasket()
	{

	}

	//선택완료버튼
	void Selected() 
	{

	}

}
