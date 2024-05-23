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
#include "LoadData.h"

namespace Screen
{
	int clickTime = 2000;
	NoodleSlice noodleSlice;
	StockGame stock;
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
			else if (mouse.right && clickTime > 100)
			{
				clickTime = 0;
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
			if (mouse.left && mouse.isDragging)
			{
				PlaceFood::CheckDragButton(mouse.x, mouse.y);
			}
			else if (mouse.left && clickTime > 100)
			{
				clickTime = 0;
				PlaceFood::CheckButton(mouse.x, mouse.y);
			}
			else {
				PlaceFood::CheckDropButton(mouse.x, mouse.y);
			}
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
			if (noodleSlice.isSuccess || noodleSlice.playTimer >= 200000 || input::IsKeyDown(13))
			{
				if (noodleSlice.playTimer >= 200000)
				{
					LoadData::soundManager->PlayMusic(Music::eSoundList::timemout, Music::eSoundChannel::Effect);
				}

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
		case Screen::TrueEndingScreen:
			ChangeTrueEndingScript(TimeSystem::GetDeltaTime());
			break;
		case Screen::EndingcreditScreen:
			GoTitle();
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
			stock.RenderStockGame(TimeSystem::GetDeltaTime());
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
		case Screen::TrueEndingScreen:
			DrawTrueEndingBack(TimeSystem::GetDeltaTime());
			break;
		default:
			break;
		}
		if (currentScreen == Screen::MoveAniScreen) {
			switch (preScreen)
			{
			case Screen::ChooseFoodScreen:
				ChooseFood::ChooseScreen();
				break;
			case Screen::StockGameScreen:
				stock.RenderStockGame(TimeSystem::GetDeltaTime());
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
			case Screen::TrueEndingScreen:
				DrawTrueEndingBack(TimeSystem::GetDeltaTime());
				break;
			default:
				break;
			}
			if (!MoveScreen::EndMoveScreen()) {
				switch (preScreen)
				{
				case TitleScreen:
					LoadData::soundManager->PlayMusic(Music::eSoundList::title, Music::eSoundChannel::BGM);
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
				case NoodleSliceScreen:
					stock.SetGame(PlayerData::player.GetStage());
					currentScreen = StockGameScreen;
					break;
				case StockGameScreen:
					PlaceFood::InitScreen();
					currentScreen = PlaceFoodScreen;
					PlayerData::player.IsGameClear(PlayerData::player.GetStage());
					break;
				case PlaceFoodScreen:
					SetEndingStage(PlayerData::player.GetStage(),PlayerData::player.IsGameClear(PlayerData::player.GetStage()), PlaceFood::GetDeco());
					currentScreen = EndingScreen;
					break;
				case EndingScreen:
					PlayerData::player.ResetScore();
					if (PlayerData::player.GetStage() == 4)
					{
						SetTrueEndingStage(PlayerData::player.IsTrueEnding());
						currentScreen = TrueEndingScreen;
					}
					else
					{
						SetStoryStage(PlayerData::player.GetStage());
						currentScreen = StoryScreen;
					}
					break;
				case TrueEndingScreen:
					currentScreen = EndingcreditScreen;
					SetCre();
					break;
				case EndingcreditScreen:
					PlayerData::player.ResetScore();
					currentScreen = TitleScreen;
					break;
				default:


					break;
				}
			}
		}
		if (pause::GetIsPause()) {
			pause::RenderPause();
			pause::DrawReButton();
			pause::DrawReButton();
		}
		MoveScreen::MoveToScreen();
	}
}