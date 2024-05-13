#include "WinApp.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "RenderSystem.h"
#include "GameManager.h"

#include "ChooseFood.h"
#include "StockGame.h"
#include <string>
#include "ScreenSystem.h"
namespace game
{
	const char* texts = "22";
	Stock::boxObject redBox = { global::GetWinApp().GetWidth() / 2, 500, 360, 90, 10, RGB(255, 0, 0) };
	Stock::boxObject yellowBox = { global::GetWinApp().GetWidth() / 2 ,500, 260, 70, 10, RGB(255, 255, 0) };
	Stock stocks;

		void UpdatePlayer()
		{
			if (input::IsKeyDown('A'))
			{
				yellowBox.Move(-yellowBox.speed, 0);
			}
			else if (input::IsKeyDown('D'))
			{
				yellowBox.Move(yellowBox.speed, 0);
			}
			if (input::IsKeyDown('W'))
			{
			}
			else if (input::IsKeyDown('S'))
			{
			}
		}
	GameManager* GameManager::instance = nullptr;
	GameManager::GameManager(){}
	GameManager::~GameManager(){}

	void GameManager::Initialize()
	{
		input::InitInput();
		time::InitTime();
		render::InitRender();
	}
	void GameManager::Update()
	{
		++m_UpdateCount;

		input::UpdateMouse();
		const input::MouseState& mouse = input::GetMouseState();
		const input::MouseState& prevmouse = input::GetPrevMouseState();
		Screen::InputMouse(mouse, prevmouse);
		input::ResetInput();

	}
	void GameManager::FixeUpdate()
	{
		static ULONGLONG elapsedTime;
		elapsedTime += time::GetDeltaTime();
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
		render::EndDraw();
	}
	void GameManager::Finalize()
	{
		render::ReleaseRender();
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
				time::UpdateTime();
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