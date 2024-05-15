#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "NoodleSlice.h"
#include "StockGame.h"
#include "MoveScreen.h"
enum ScreenName {
	ChooseFoodScreen,
	StockGameScreen,
	NoodleSliceScreen,
	PlaceFoodScreen,
	MoveAniScreen
};
namespace Screen
{
	NoodleSlice noodleSlice;
	float _timer;
	ScreenName preScreen = ChooseFoodScreen;
	ScreenName currentScreen = ChooseFoodScreen;
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
			MoveScreen::SetMoveAni();
			noodleSlice.SetGame(noodleSlice.STAGE3,noodleSlice.NOODLE2);
			preScreen = currentScreen;
			currentScreen = MoveAniScreen;
			ChooseFood::ChooseScreen();
			break;
		case StockGameScreen:
			stock.RenderStockGame();
			break;
		case NoodleSliceScreen:
			noodleSlice.NoodleSliceScreen();
			break;
		case MoveAniScreen:
			MoveScreen::MoveToScreen();
			//현재 애니메이션이 종료되면 false가 반환됨
			if (!MoveScreen::EndMoveScreen()) {
				switch (preScreen)
				{
				case ChooseFoodScreen:
					currentScreen = NoodleSliceScreen;
					break;
				case StockGameScreen:
					currentScreen = PlaceFoodScreen;
					break;
				case NoodleSliceScreen:
					currentScreen = StockGameScreen;
					break;
				case PlaceFoodScreen:
					currentScreen = NoodleSliceScreen;
					break;
				default:
					break;
				}
			}
			break;
		case PlaceFoodScreen:
			break;
		default:
			break;
		}
	}
}