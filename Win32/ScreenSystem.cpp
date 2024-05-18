#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "NoodleSlice.h"
#include "StockGame.h"
#include "MoveScreen.h"
#include "Title.h"
#include "Story.h"
#include "Pause.h"
#include "TextList.h"
#include "PlayerData.h"
#include "Types.h"

namespace Screen
{
	NoodleSlice noodleSlice;
	StockGame stock;
	TextList* textList = TextList::GetInstance();
	float _timer;
	ScreenName preScreen = TitleScreen;
	ScreenName currentScreen = TitleScreen;

	void SetScreen()
	{
		MoveScreen::SetMoveAni();
		preScreen = currentScreen;
		currentScreen = MoveAniScreen;
	}
	
	void ReStartScreen()
	{
		MoveScreen::SetMoveAni();
		currentScreen = preScreen;
		currentScreen = MoveAniScreen;
	}

	void ReTitleScreen()
	{
		preScreen = TitleScreen;
		currentScreen = TitleScreen;
	}

	
	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse) {
		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
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
		case Screen::StockGameScreen:
			break;
		case Screen::NoodleSliceScreen:
			break;
		case Screen::PlaceFoodScreen:
			break;
		case Screen::MoveAniScreen:
			break;
		case Screen::TitleScreen:
			if (input::IsSame(mouse, premouse))
			{
				return;
			}
			if (mouse.left) {
				Title::TitleCheckClick(mouse.x, mouse.y);
			}
			break;
		case Screen::StoryScreen:
			break;
		default:
			break;
		}

		if (pause::GetIsPause())
		{
			if (input::IsSame(mouse, premouse))
			{
				return;
			}
			if (mouse.left) {
				pause::IsCheckReButton(mouse.x, mouse.y);
			}
		}
	}

	void InputKeyBoard() {
		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
			pause::IsPause();
			if (!pause::GetIsPause())
			{
				return;
			}
			else
			{
				pause::CaptureScreen();
			}
			break;
		case Screen::StockGameScreen:
			pause::IsPause();
			if (!pause::GetIsPause())
			{
				stock.UpdateYellowBox(TimeSystem::GetDeltaTime());
				stock.UpdateGame(TimeSystem::GetDeltaTime());
			}
			else
			{
				pause::CaptureScreen();
			}
			break;
		case Screen::NoodleSliceScreen:
			pause::IsPause();
			if (!pause::GetIsPause())
			{
				noodleSlice.UpdateGame();
			}
			else
			{
				pause::CaptureScreen();
			}

			if (noodleSlice.isSuccess || noodleSlice.playTimer > 20000)
			{
				SetScreen();
			}
			break;
		case Screen::PlaceFoodScreen:
			break;
		case Screen::MoveAniScreen:
			break;
		case Screen::TitleScreen:
			Title::isEsc();
			break;
		case Screen::StoryScreen:
			ChangeScript(TimeSystem::GetDeltaTime());
			break;
		case Screen::EndingScreen:
			ChangeEndingBack(TimeSystem::GetDeltaTime());
			break;
		default:
			break;
		}
	}




	void ScreenRender() {
		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
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
		case Screen::StoryScreen:
			DrawBack(PlayerData::player.GetStage());
			break;
		case Screen::EndingScreen:
			DrawEndingBack(PlayerData::player.GetStage());
			break;
		case Screen::MoveAniScreen:
			MoveScreen::MoveToScreen();
			if (!MoveScreen::EndMoveScreen()) {
				switch (preScreen)
				{
				case TitleScreen:
					textList->LoadtTextAll();
					SetStoryScript(PlayerData::player.GetStage());

					currentScreen = StoryScreen;
					break;
				case StoryScreen:
					currentScreen = ChooseFoodScreen;
					break;
				case ChooseFoodScreen:
					noodleSlice.SetGame(PlayerData::player.GetStage(), noodleSlice.NOODLE3);
					currentScreen = NoodleSliceScreen;
					break;
				case StockGameScreen:
					SetEndingScript(1,false);
					currentScreen = EndingScreen;
					break;
				case NoodleSliceScreen:
					currentScreen = StockGameScreen;
					break;
				case PlaceFoodScreen:
					break;
				case EndingScreen:
					PlayerData::player.ResetScore();
					SetStoryStage(PlayerData::player.GetStage());
					currentScreen = StoryScreen;
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}

		if (pause::GetIsPause()) {
			pause::RenderPause();
			pause::DrawReButton();
			pause::DrawReButton();
		}	
	}
}