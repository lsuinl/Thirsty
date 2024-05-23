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
#include "FadeinFadeout.h"

namespace Screen
{
	int clickTime = 2000;
	NoodleSlice noodleSlice;
	StockGame stock;
	float _timer;
	ScreenName preScreen = TitleScreen;
	ScreenName currentScreen = TitleScreen;
	bool re = false;

	void SetScreen()
	{
		MoveScreen::SetMoveAni();
		preScreen = currentScreen;
		currentScreen = MoveAniScreen;
	}

	void ReStartScreen()
	{
		re = true;
		MoveScreen::SetMoveAni();
		preScreen = currentScreen;
		currentScreen = MoveAniScreen;
	}

	void ReTitleScreen()
	{
		PlayerData::player.SetStage(Types::STAGE1);
		preScreen = TitleScreen;
		currentScreen = TitleScreen;
	}

	void InputMouse(const input::MouseState& mouse, const input::MouseState& premouse) {
		clickTime += TimeSystem::GetDeltaTime();
		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
			if (mouse.left && mouse.isDragging)
				ChooseFood::CheckDragButton(mouse.x, mouse.y);
			else if (mouse.left && clickTime > 200)
			{
				clickTime = 0;
				ChooseFood::CheckButton(mouse.x, mouse.y);
			}
			else if (mouse.right && clickTime > 200)
			{
				clickTime = 0;
				ChooseFood::CheckCancelButton(mouse.x, mouse.y);
			}
			else 
				ChooseFood::CheckDropButton(mouse.x, mouse.y);
			break;
		case Screen::PlaceFoodScreen:
			if (mouse.left && mouse.isDragging)
				PlaceFood::CheckDragButton(mouse.x, mouse.y);
			else if (mouse.left && clickTime > 100)
			{
				clickTime = 0;
				PlaceFood::CheckButton(mouse.x, mouse.y);
			}
			else
				PlaceFood::CheckDropButton(mouse.x, mouse.y);
			break;
		case Screen::TitleScreen:
			Title::TitleCheckHover(mouse.x, mouse.y);
			if (input::IsSame(mouse, premouse))
				return;
			if (mouse.left) 
				Title::TitleCheckClick(mouse.x, mouse.y);
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
				pause::IsButton(mouse.x, mouse.y);
			}
		}
		else
		{
			if (input::IsSame(mouse, premouse))
			{
				return;
			}
			if (mouse.left && (currentScreen != TitleScreen && currentScreen != EndingcreditScreen && currentScreen != StoryScreen && currentScreen != EndingScreen && currentScreen != TrueEndingScreen)) {
				pause::IsMenuButton(mouse.x, mouse.y);
			}
		}


	}

	void InputKeyBoard() {
		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
			pause::IsPause();
			if (!pause::GetIsPause())
				return;
			else
				pause::CaptureScreen();
			break;
		case Screen::StockGameScreen:
			pause::IsPause();
			if (!pause::GetIsPause())
			{
				stock.UpdateYellowBox(TimeSystem::GetDeltaTime());
				stock.UpdateGame(TimeSystem::GetDeltaTime());
			}
			else
				pause::CaptureScreen();
			break;
		case Screen::NoodleSliceScreen:
			pause::IsPause();
			if (!pause::GetIsPause())
				noodleSlice.UpdateGame();
			else
				pause::CaptureScreen();
			if (noodleSlice.isSuccess || noodleSlice.playTimer >= 22000 || input::IsKeyDown(13))
			{
				if (noodleSlice.playTimer >= 22000) 
				{
					noodleSlice.SetClearCheck(2);
					LoadData::soundManager->PlayMusic(Music::eSoundList::timemout, Music::eSoundChannel::Effect);
				}
				else 
				{
					noodleSlice.SetClearCheck(1);
				}
				PlayerData::player.MiniGameClear(noodleSlice.isSuccess);
				SetScreen();
			}
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
			break;
		default:
			break;
		}
	}

	//화면전환
	void aniRender() {
		//커튼닫기
		if (re) {
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
			default:
				break;
			}
		}
		else {
			//기본 화면전환
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
				DrawStoryBack(PlayerData::player.GetStage(), TimeSystem::GetDeltaTime());
				break;
			case Screen::EndingScreen:
				DrawEndingBack(PlayerData::player.GetStage(), TimeSystem::GetDeltaTime());
				break;
			case Screen::TrueEndingScreen:
				LoadData::imageManager->DrawPngImage("페이드", 0, 0, 1935, 1080, 1.0f, false);
				break;
			case Screen::EndingcreditScreen:
				LoadData::imageManager->DrawPngImage("페이드", 0, 0, 1935, 1080, 1.0f, false);
				break;
			default:
				break;
			}
		}
		//커튼 열기! 데이터 초기화완료
		if (!MoveScreen::EndMoveScreen()) {
			if (re) {
				switch (preScreen)
				{
				case Screen::ChooseFoodScreen:
					ChooseFood::InitScreen();
					currentScreen = ChooseFoodScreen;
					break;
				case Screen::StockGameScreen:
					stock.SetGame(PlayerData::player.GetStage());
					currentScreen = StockGameScreen;
					break;
				case Screen::NoodleSliceScreen:
					noodleSlice.SetGame(PlayerData::player.GetStage(), PlayerData::player.GetNoodle());
					currentScreen = NoodleSliceScreen;
					break;
				case Screen::PlaceFoodScreen:
					PlayerData::player.MiniGameClear(stock.IsStockClear());
					PlaceFood::InitScreen();
					currentScreen = PlaceFoodScreen;
					break;
				default:
					break;
				}
				re = false;
			}
			else {
				switch (preScreen)
				{
				case TitleScreen:
					LoadData::soundManager->PlayMusic(Music::eSoundList::title, Music::eSoundChannel::BGM);
					SetStoryStage(PlayerData::player.GetStage());
					currentScreen = StoryScreen;
					break;
				case StoryScreen:
					LoadData::soundManager->StopMusic(Music::eSoundChannel::Effect);
					ChooseFood::InitScreen();
					currentScreen = ChooseFoodScreen;
					break;
				case ChooseFoodScreen:
					noodleSlice.SetGame(PlayerData::player.GetStage(), PlayerData::player.GetNoodle());
					currentScreen = NoodleSliceScreen;
					break;
				case NoodleSliceScreen:
					stock.SetGame(PlayerData::player.GetStage());
					currentScreen = StockGameScreen;
					break;
				case StockGameScreen:
					LoadData::soundManager->StopMusic(Music::eSoundChannel::Effect);
					PlayerData::player.MiniGameClear(stock.IsStockClear());
					PlaceFood::InitScreen();
					currentScreen = PlaceFoodScreen;
					break;
				case PlaceFoodScreen:
					SetEndingStage(PlayerData::player.GetStage(), PlayerData::player.IsGameClear(PlayerData::player.GetStage()),PlaceFood::GetDeco());
					currentScreen = EndingScreen;
					break;
				case EndingScreen:
					PlayerData::player.ResetScore();
					if (PlayerData::player.GetStage() == Types::STAGE4)
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
	}


	void ScreenRender() {
		//화면 그리기
		switch (currentScreen)
		{
		case Screen::ChooseFoodScreen:
			ChooseFood::ChooseScreen();
			pause::DrawMenuButton();
			break;
		case Screen::StockGameScreen:
			stock.RenderStockGame(TimeSystem::GetDeltaTime());
			pause::DrawMenuButton();
			break;
		case Screen::NoodleSliceScreen:
			noodleSlice.NoodleSliceScreen();
			pause::DrawMenuButton();
			break;
		case Screen::PlaceFoodScreen:
			PlaceFood::PrintScreen();
			pause::DrawMenuButton();
			break;
		case Screen::TitleScreen:
			Title::TitleRender();
			break;
		case Screen::StoryScreen:
			DrawStoryBack(PlayerData::player.GetStage(), TimeSystem::GetDeltaTime());
			break;
		case Screen::EndingScreen:
			DrawEndingBack(PlayerData::player.GetStage(), TimeSystem::GetDeltaTime());
			break;
		case Screen::TrueEndingScreen:
			DrawTrueEndingBack(TimeSystem::GetDeltaTime());
			break;
		case Screen::EndingcreditScreen:
			EndingCre(TimeSystem::GetDeltaTime());
			break;
		case Screen::MoveAniScreen:
			aniRender();
		default:
			break;
		}
		if (pause::GetIsPause()) 
		{
			pause::RenderPause();
			pause::DrawReButton();
		}
		MoveScreen::MoveToScreen();
	}
}