#pragma once
#include "GlobalHeader.h"

namespace Screen
{
	enum ScreenName {
		ChooseFoodScreen,
		StockGameScreen,
		NoodleSliceScreen,
		PlaceFoodScreen,
		TitleScreen,
	};

	void SetScreen(ScreenName screen);
	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse);
	void InputKeyBoard();
	void ScreenRender();
}
