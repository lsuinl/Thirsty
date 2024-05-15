#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "NoodleSlice.h"
#include "StockGame.h"
#include "Animations.h"
#include "Title.h"

namespace Screen
{
	NoodleSlice noodleSlice;
	StockGame stock;

	ScreenName currentScreen = TitleScreen;

	void SetScreen(ScreenName screen)
	{
		currentScreen = screen;
	}

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
		case TitleScreen:
			if (input::IsSame(mouse, premouse))
			{
				return;
			}
			if (mouse.left) {
				Title::TitleCheckClick(mouse.x, mouse.y);
			}
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
			// 성공했거나 시간 지났을 때
			if (noodleSlice.isSuccess || noodleSlice.playTimer > 20000)
			{
				currentScreen = StockGameScreen;
			}
			break;
		case PlaceFoodScreen:
			break;
		case TitleScreen:
			Title::isEsc();
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
			//noodleSlice.SetGame(noodleSlice.STAGE3,noodleSlice.NOODLE2);
			//currentScreen = NoodleSliceScreen;
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
			Title::TitleRender();
			break;
		default:
			break;
		}
		//Animations::RenderAnimation();
	}
}