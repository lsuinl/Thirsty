#include "MoveScreen.h"
#include "Animator.h"
namespace MoveScreen
{
	std::wstring* imageList = new std::wstring[10];
	Animator moveAni;
	void SetMoveAni()
	{
		for (int i = 1; i <= 10; i++)
		{
			imageList[i - 1] = L"resource\\animation\\test\\" + std::to_wstring(i) + L".bmp";
		}
		moveAni = Animator("테스트", 300, 100, 400, 400, 800, imageList, false , false);
		moveAni.SetAnimation();
	}
	void MoveToScreen() 
	{
		render::DrawBackGround("resource/background/back.bmp", 1920, 1080, 0, 0, false);
		render::DrawTextF(130, 90, "육수 선택", RGB(0, 0, 0), 60);

		moveAni.DrawAnimation();
	}

	bool EndMoveScreen()
	{
		return moveAni.GetAnimationCheck(); 
	}
};
