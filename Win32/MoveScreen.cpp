#include "MoveScreen.h"
#include "Animator.h"
#include "LoadData.h"
#include "Pause.h"
namespace MoveScreen
{
	Animator openAni;
	Animator closeAni;

	void SetMoveAni()
	{
		std::wstring* imageOpenList = new std::wstring[43];
		std::wstring* imageClosseList = new std::wstring[43];
		for (int i = 1; i <=43; i++)
		{
			imageOpenList[i - 1] = L"resource\\animation\\curten\\" + std::to_wstring(i) + L".png";
		}
		openAni = Animator("커튼열어", 0, 0, 1920, 1080, 1000, imageOpenList, false , true, 43);

		for (int i = 1; i <= 43; i++)
		{
			imageClosseList[i - 1] = L"resource\\animation\\curten\\" + std::to_wstring(44- i) + L".png";
		}
		closeAni = Animator("커튼닫어", 0, 0, 1920, 1080, 2000, imageClosseList, false, true, 43);

		closeAni.SetAnimation();
	}

	void MoveToScreen() 
	{
		closeAni.DrawAnimation();
	}
	
	void FirstAniScreen() 
	{
		openAni.DrawAnimation();
	}
	
	bool EndMoveScreen()
	{
		if (!closeAni.GetAnimationCheck()) {
			openAni.SetAnimation();
			return false;
		}
		return true;
	}

};
