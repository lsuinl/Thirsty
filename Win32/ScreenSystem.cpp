#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "NoodleSlice.h"
#include "StockGame.h"
#include "Animations.h"
#include "Title.h"

namespace Screen
{
	NoodleSlice noodleSlice;
	ScreenName priviewScreen = ChooseFoodScreen;
	ScreenName currentScreen = TitleScreen;
	StockGame stock;
	Title title;

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

	void InputKeyBoard() {
		switch (currentScreen)
		{
		case ChooseFoodScreen:
			break;
		case StockGameScreen:
			stock.UpdateYellowBox(TimeSystem::GetDeltaTime());
			stock.UpdateGame(TimeSystem::GetDeltaTime());
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
			noodleSlice.SetGame(noodleSlice.STAGE3,noodleSlice.NOODLE2);
			currentScreen = NoodleSliceScreen;
			ChooseFood::ChooseScreen();
			break;
		case StockGameScreen:
			stock.RenderStockGame();
			break;
		case NoodleSliceScreen:
			noodleSlice.NoodleSliceScreen();
			break;
		case PlaceFoodScreen:
			break;
		case TitleScreen:
			title.TitleRender();
			break;
		default:
			break;
		}
		//Animations::RenderAnimation();
	}
}