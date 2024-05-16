#include "InputSystem.h"
#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "MiniGame1.h"
#include "StockGame.h"
#include "Animations.h"
#include "Scenario.h"
#include "Story.h"

enum ScreenName {
	StoryScreen,
	ChooseFoodScreen,
	StockGameScreen,
	NoodleSliceScreen,
	PlaceFoodScreen,
};
namespace Screen
{
	ScreenName currentScreen = StoryScreen;
	StockGame stock;

	//마우스 입력 시스템
	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse) {
		switch (currentScreen)
		{
		case StoryScreen:
			break;
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

	void InputKeyBoard() {
		switch (currentScreen)
		{
		case StoryScreen:
			if (ChangeBack(TimeSystem::GetDeltaTime()) == true)
			{
				currentScreen = ChooseFoodScreen;
			}
			break;
		case ChooseFoodScreen:
			break;
		case StockGameScreen:
			stock.UpdateYellowBox(TimeSystem::GetDeltaTime());
			stock.UpdateGame(TimeSystem::GetDeltaTime());
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
		case StoryScreen:
			DrawBack();
			break;
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
		//Animations::RenderAnimation();
	}
}