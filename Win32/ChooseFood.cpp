#include "WinApp.h"
#include "ChooseFood.h"
#include "RenderSystem.h"
#include "Button.h"

//�� ����
enum Noodle 
{
	wow,
	suin,
	ee,
};

//���� ����
enum Soup 
{
	bi,
	in,
};

//��� ����
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
		button::Button("����",0,0,100,100, "resource/background/back.bmp"), 
		button::Button("������",0, 100, 100, 100, "resource/background/back.bmp"),
		button::Button("����",0,200, 100, 100, "resource/background/back.bmp"),
		button::Button("�Ʒ���",0, 300, 100, 100, "resource/background/back.bmp"),
	};
	void CheckButton(int dx,int dy) {
		for (int i = 0; i < 4; i++) 
		{
			buttonList[i].CheckClick(dx,dy);
		}
	}
	//��, ����, ��� ���� ȭ��
	void NoodleScreen() 
	{
		render::DrawBackGround("resource/background/back.bmp",1920,1080,0,0,false);
		render::DrawBackGround("resource/background/back.bmp",1300,900,100,100,false);
		render::DrawTextF(130, 90, "�� ����", RGB(0, 0, 0), 60);
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

	//����â �ѱ��
	void LeftPage() 
	{

	}

	void RightPage() 
	{

	}

	//�ٱ��� ���Ʒ��� �̵��ϱ�
	void UpBasket() 
	{

	}

	void DownBasket()
	{

	}

	//���ÿϷ��ư
	void Selected() 
	{

	}

}
