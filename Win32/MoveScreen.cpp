#include "MoveScreen.h"
#include "Animator.h"
#include "LoadData.h"
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
		LoadData::imageManager->DrawBitMapImage("로딩화면",0,0);
		render::DrawTextF(130, 90, L"화면 체인지", RGB(0, 0, 0), 60);
		moveAni.DrawAnimation();
	}

	bool EndMoveScreen()
	{
		return moveAni.GetAnimationCheck(); 
	}
};
