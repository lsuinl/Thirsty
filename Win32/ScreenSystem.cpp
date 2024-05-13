#include "InputSystem.h"
#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "MiniGame1.h"
#include "StockGame.h"
#include "TimeSystem.h"
enum ScreenName {
	ChooseFoodScreen,
	StockGameScreen,
	NoodleSliceScreen,
	PlaceFoodScreen,
};
namespace Screen
{
	ScreenName currentScreen = StockGameScreen;
	StockGame stock;

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
			stock.UpdateYellowBox(time::GetDeltaTime());
			stock.UpdateGame(time::GetDeltaTime());
			break;
		case NoodleSliceScreen:
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
			ChooseFood::ChooseScreen();
			break;
		case StockGameScreen:
			stock.RenderStockGame();
			break;
		case NoodleSliceScreen:
			break;
		case PlaceFoodScreen:
			break;
		default:
			break;
		}
	}
}