#include "MoveScreen.h"
#include "Animator.h"
#include "LoadData.h"
#include "Pause.h"

namespace MoveScreen
{

	bool check = false;

	void InitAni()
	{
	}
	void SetMoveAni()
	{
		LoadData::AniManager[0].SetAnimation();
	}


	void MoveToScreen()
	{
		LoadData::AniManager[0].DrawAnimation();
		LoadData::AniManager[1].DrawAnimation();
		if (check&& LoadData::AniManager[1].GetAnimationCheck() == false)
		{
			check = false;
		}
	}


	bool EndMoveScreen()
	{
		if (!LoadData::AniManager[0].GetAnimationCheck()) {
			check = true;
			LoadData::AniManager[1].SetAnimation();
			return false;
		}
		return true;
	}

};
