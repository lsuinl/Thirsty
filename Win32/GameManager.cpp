#include "WinApp.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "RenderSystem.h"
#include "GameManager.h"
#include <string>
#include "ScreenSystem.h"
#include "Story.h"
#include "TextList.h"
#include "LoadData.h"
#include "MoveScreen.h"
namespace game
{
	const char* texts = "22";
	GameManager* GameManager::instance = nullptr;
	GameManager::GameManager() {}
	GameManager::~GameManager() {}
	void GameManager::Initialize()
	{
		input::InitInput();
		TimeSystem::InitTime();
		render::InitRender();
		MoveScreen::InitAni();
	    LoadData::LoadMusic();
		LoadData::LoadImages();
		LoadData::LoadAnimation();
		LoadData::soundManager->PlayMusic(Music::eSoundList::title, Music::eSoundChannel::BGM);
	}
	void GameManager::Update()
	{
		++m_UpdateCount;
		Screen::InputKeyBoard();
		input::UpdateMouse();
		const input::MouseState& mouse = input::GetMouseState();
		const input::MouseState& prevmouse = input::GetPrevMouseState();
		Screen::InputMouse(mouse, prevmouse);
		input::ResetInput();

	}
	void GameManager::FixeUpdate()
	{
		static ULONGLONG elapsedTime;
		elapsedTime += TimeSystem::GetDeltaTime();
		while (elapsedTime >= 20) //0.02seconds
		{
			++m_FixedUpdateCount;
			elapsedTime -= 20;
		}
	}
	void GameManager::Render()
	{
		render::BeginDraw();
		Screen::ScreenRender();
		static int fps;
		static float time;
		time += TimeSystem::GetDeltaTime();
		while (time > 1000) {
			fps = m_UpdateCount;
			m_UpdateCount = 0;
			time -= 1000;
		}
		render::DrawTextF(0, 100, std::to_wstring(fps).c_str(), RGB(100, 100, 100), 50);
		render::EndDraw();
	}
	void GameManager::Finalize()
	{
		render::ReleaseRender();
		LoadData::imageManager->DestroyInstance();
		LoadData::imageManager = nullptr;
		LoadData::soundManager->DestroyInstance();
		LoadData::soundManager = nullptr;
	}
	void GameManager::Run()
	{
		MSG msg;
		while (true)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) break;
				if (msg.message == WM_KEYDOWN)
				{
					input::KeyDown(msg.wParam);
				}
				else if (msg.message == WM_KEYUP)
				{
					input::KeyUp(msg.wParam);
				}
				else
				{
					DispatchMessage(&msg);
				}
			}
			else
			{
				TimeSystem::UpdateTime();
				FixeUpdate();
				Update();
				Render();
			}
		}
	}

	GameManager* GameManager::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}
	void GameManager::DestroyInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
}