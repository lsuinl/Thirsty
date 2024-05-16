#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "NoodleSlice.h"
#include "StockGame.h"
#include "MoveScreen.h"
#include "Title.h"
enum ScreenName {
	ChooseFoodScreen,
	StockGameScreen,
	NoodleSliceScreen,
	PlaceFoodScreen,
	MoveAniScreen,
	TitleScreen,
};
namespace Screen
{
	NoodleSlice noodleSlice;
	float _timer;
	ScreenName preScreen = TitleScreen;
	ScreenName currentScreen = ChooseFoodScreen;
	StockGame stock;
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
			if (mouse.left) 
			{
				ChooseFood::CheckButton(mouse.x, mouse.y);
			}
			if (mouse.isDragging) {
				ChooseFood::CheckDragButton(mouse.x, mouse.y);
			}
			else {
				ChooseFood::CheckDropButton(mouse.x, mouse.y);
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
		case Screen::ChooseFoodScreen:
			//MoveScreen::SetMoveAni();
			noodleSlice.SetGame(noodleSlice.STAGE3, noodleSlice.NOODLE2);
			//preScreen = currentScreen;
			currentScreen = NoodleSliceScreen;
			ChooseFood::ChooseScreen();
			break;
		case Screen::StockGameScreen:
			stock.RenderStockGame();
			break;
		case Screen::NoodleSliceScreen:
			noodleSlice.NoodleSliceScreen();
			break;
		case Screen::PlaceFoodScreen:
			break;
		case Screen::TitleScreen:
			Title::TitleRender();
			break;
		default:
			break;
		}
	}
}