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
		moveAni = Animator("테스트", 300, 600, 400, 400, 2000, imageList, false , false);
		moveAni.SetAnimation();
	}
	void MoveToScreen() 
	{
		render::DrawBackGround("resource/background/loading.bmp", 1920, 1080, 0, 0, false);
		render::DrawTextF(130, 90, L"화면 체인지", RGB(0, 0, 0), 60);

		moveAni.DrawAnimation();
	}

	bool EndMoveScreen()
	{
		return moveAni.GetAnimationCheck(); 
	}
};
