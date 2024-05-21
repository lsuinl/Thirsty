#include "EndingCredit.h"

namespace end
{
	std::wstring* imageList = new std::wstring[5];
	Animator moveCredit;

	void SetMoveCredit()
	{
		for (int i = 1; i <= 5; i++)
		{
			imageList[i - 1] = L"resource\\animation\\credit\\" + std::to_wstring(i) + L".bmp";
		}
		moveCredit = Animator("����ũ����", 0, 0, 1920, 1080, 30000, imageList, false, false);
		moveCredit.SetAnimation();
	}
	void MoveToCredit()
	{
		LoadData::imageManager->DrawBitMapImage("����ũ����", 0, 0);
		moveCredit.DrawAnimation();
	}

	bool EndMoveCredit()
	{
		return moveCredit.GetAnimationCheck();
	}

	void ReleasCredit()
	{
		delete[] imageList;
	}
}