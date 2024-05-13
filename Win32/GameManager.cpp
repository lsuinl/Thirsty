﻿#include "WinApp.h"
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

		void UpdatePlayer()
		{
			if (input::IsKeyDown('A'))
			{
			}
			else if (input::IsKeyDown('D'))
			{
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