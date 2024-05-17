#pragma once
#include "GlobalHeader.h"

namespace Screen
{
	enum ScreenName {
		ChooseFoodScreen,
		StockGameScreen,
		NoodleSliceScreen,
		PlaceFoodScreen,
		MoveAniScreen,
		TitleScreen,
		StoryScreen,
	};
	void SetScreen();
	void ReStartScreen();
	void ReTitleScreen();
	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse);
	void InputKeyBoard();
	void ScreenRender();
}
