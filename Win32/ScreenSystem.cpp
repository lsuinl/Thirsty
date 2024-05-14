#include "InputSystem.h"
#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "MiniGame1.h"
#include "StockGame.h"
enum ScreenName {
	ChooseFoodScreen,
	StockGameScreen,
	NoodleSliceScreen,
	PlaceFoodScreen,
};
namespace Screen
{
	ScreenName currentScreen = ChooseFoodScreen;

	//���콺 �Է� �ý���
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

	//Ű���� �Է� �ý���
	void InputKeyBoard() {
		switch (currentScreen)
		{
		case ChooseFoodScreen:
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

	//�׸���
	void ScreenRender() {
		switch (currentScreen)
		{
		case ChooseFoodScreen:
			ChooseFood::ChooseScreen();
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
}