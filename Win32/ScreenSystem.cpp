#include "ScreenSystem.h"

enum ScreenName {
	ChooseFoodScreen,
	StockGameScreen,
	NoodleSliceScreen,
	PlaceFoodScreen,
};
namespace Screen
{
	NoodleSlice noodleSlice;
	ScreenName currentScreen = ChooseFoodScreen;
	float _timer;

	//마우스 입력 시스템
	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse) {
		switch (currentScreen)
		{
		case ChooseFoodScreen:
			if (input::IsSame(mouse, premouse))
			{
				return;
			}
			if (mouse.left) {
				ChooseFood::CheckButton(mouse.x, mouse.y);
			}
			break;
		case StockGameScreen:
			break;
		case NoodleSliceScreen:
			break;
		case PlaceFoodScreen:
			break;
		default:
			break;
		}
	}

	//키보드 입력 시스템
	void InputKeyBoard() {
		switch (currentScreen)
		{
		case ChooseFoodScreen:
			break;
		case StockGameScreen:
			break;
		case NoodleSliceScreen:
			noodleSlice.UpdateGame();
			if (noodleSlice.isSuccess || noodleSlice.playTimer > 20000)
			{
				currentScreen = StockGameScreen;
			}
			break;
		case PlaceFoodScreen:
			break;
		default:
			break;
		}
	}

	//그리기
	void ScreenRender() {
		switch (currentScreen)
		{
		case ChooseFoodScreen:
			noodleSlice.SetGame(noodleSlice.STAGE2,noodleSlice.NOODLE2);
			currentScreen = NoodleSliceScreen;
			ChooseFood::ChooseScreen();
			break;
		case StockGameScreen:
			break;
		case NoodleSliceScreen:
			noodleSlice.NoodleSliceScreen();
			break;
		case PlaceFoodScreen:
			break;
		default:
			break;
		}
	}
}