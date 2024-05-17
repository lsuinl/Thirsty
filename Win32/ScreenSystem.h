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
		EndingScreen,
	};
	void SetScreen();
	void ReScreen();
	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse);
	void InputKeyBoard();
	void ScreenRender();
}
