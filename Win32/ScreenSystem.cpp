#include "ScreenSystem.h"
#include "ChooseFood.h"
#include "NoodleSlice.h"
#include "StockGame.h"
#include "PlaceFood.h"
#include "MoveScreen.h"
#include "Title.h"
#include "Story.h"
#include "Pause.h"
#include "TextList.h"
#include "PlayerData.h"
#include "Types.h"
#include "EndingCredit.h"
#include "FadeinFadeout.h"

namespace Screen
{
	int clickTime = 0;
	NoodleSlice noodleSlice;
	StockGame stock;
	TextList* textList = TextList::GetInstance();
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
		clickTime += TimeSystem::GetDeltaTime();

		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
			if (mouse.left && mouse.isDragging)
			{
				ChooseFood::CheckDragButton(mouse.x, mouse.y);
			}
			else if (mouse.left && clickTime > 100)
			{
				clickTime = 0;
				ChooseFood::CheckButton(mouse.x, mouse.y);
			}
			else if (mouse.right)
			{
				ChooseFood::CheckCancelButton(mouse.x, mouse.y);
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

			if (noodleSlice.isSuccess || noodleSlice.playTimer > 20000 || input::IsKeyDown(16) == true)
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
			ChangeStoryScript(TimeSystem::GetDeltaTime());
			break;
		case Screen::EndingScreen:
			ChangeEndingScript(TimeSystem::GetDeltaTime());
			break;
		case CreditScreen:
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
			PlaceFood::PrintScreen();
			break;
		case Screen::TitleScreen:
			Title::TitleRender();
			break;
		case Screen::StoryScreen:
			DrawStoryBack(PlayerData::player.GetStage());
			break;
		case Screen::EndingScreen:
			DrawEndingBack(PlayerData::player.GetStage());
			break;
		case Screen::CreditScreen:
			break;
		case Screen::MoveAniScreen:
			MoveScreen::MoveToScreen();
			if (!MoveScreen::EndMoveScreen()) {
				switch (preScreen)
				{
				case TitleScreen:
					textList->LoadtTextAll();
					SetStoryStage(PlayerData::player.GetStage());
					currentScreen = StoryScreen;
					break;
				case StoryScreen:
					ChooseFood::InitScreen();
					currentScreen = ChooseFoodScreen;
					break;
				case ChooseFoodScreen:
					noodleSlice.SetGame(PlayerData::player.GetStage(), noodleSlice.NOODLE2);
					currentScreen = NoodleSliceScreen;
					break;
				case StockGameScreen:
					SetEndingStage(PlayerData::player.GetStage(),PlayerData::player.IsGameClear());
					currentScreen = EndingScreen;
					break;
				case NoodleSliceScreen:
					stock.SetGame(PlayerData::player.GetStage());
					currentScreen = StockGameScreen;
					break;
				case PlaceFoodScreen:
					break;
				case EndingScreen:
					if(PlayerData::player.GetStage()==3)
					{
						PlayerData::player.ResetScore();
						currentScreen = TitleScreen;
					}
					else
					{
						PlayerData::player.ResetScore();
						SetStoryStage(PlayerData::player.GetStage());
						currentScreen = StoryScreen;
					}
					break;
				case CreditScreen:
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