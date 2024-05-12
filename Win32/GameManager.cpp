﻿#include "WinApp.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "RenderSystem.h"
#include "GameManager.h"

#include "ChooseFood.h"
#include "StockGame.h"
#include <string>

namespace game
{
	const char* texts = "22";
	Stock::boxObject redBox = { global::GetWinApp().GetWidth() / 2, 500, 360, 90, 10, RGB(255, 0, 0) };
	Stock::boxObject yellowBox = { global::GetWinApp().GetWidth() / 2 ,500, 260, 70, 10, RGB(255, 255, 0) };
	Stock stocks;

		// 방향키 입력 시스템인데 어케해야하지?
	void InputArrow()
	{
		if (input::IsKeyDown(38)) // up
		{

		}
		else if (input::IsKeyDown(37)) // left
		{

		}
		else if (input::IsKeyDown(40)) // down
		{

		}
		else if (input::IsKeyDown(39)) // right
		{

		}
	}
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
	void UpdateBlueCircle()
	{
		const input::MouseState& mouse = input::GetMouseState();
		const input::MouseState& prevmouse = input::GetPrevMouseState();

		if (input::IsSame(mouse, prevmouse))
		{
			return;
		}
		if (mouse.left) {
			ChooseFood::CheckButton(mouse.x, mouse.y);
		}
	}

	GameManager* GameManager::instance = nullptr;
	GameManager::GameManager()
	{
	}
	GameManager::~GameManager()
	{
	}
	void GameManager::Initialize()
	{
		input::InitInput();
		time::InitTime();
		render::InitRender();
	}
	void GameManager::Update()
	{
		UpdatePlayer();
		++m_UpdateCount;

		input::UpdateMouse();
		UpdateBlueCircle();
		input::ResetInput();

	}
	void GameManager::FixeUpdate()
	{
		static ULONGLONG elapsedTime;

		elapsedTime += time::GetDeltaTime();

		while (elapsedTime >= 20) //0.02��
		{
			++m_FixedUpdateCount;

			elapsedTime -= 20;
		}
	}
	void GameManager::Render()
	{
//
//		DrawFPS();
//		DrawSomething();
		//DrawPlayer();
		render::BeginDraw();

		ChooseFood::ChooseScreen();

		render::DrawTextF(0, 0, texts, RGB(255, 255, 255), 50);
		DrawFPS();
		DrawSomething();
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
	void GameManager::DrawFPS()
	{
		static ULONGLONG elapsedTime;
		static int UpdateCount;
		static int FixedUpdateCount;

		elapsedTime += time::GetDeltaTime();

		if (elapsedTime >= 1000)
		{
			elapsedTime = 0;
			;
			UpdateCount = m_UpdateCount;
			FixedUpdateCount = m_FixedUpdateCount;

			m_UpdateCount = 0;
			m_FixedUpdateCount = 0;
		}
		int salin = stocks.GetSalinity();
		std::string str = "FPS: " + std::to_string(time::GetFrameRate());
		str += "           Update " + std::to_string(UpdateCount);
		str += "           FixedUpdate " + std::to_string(FixedUpdateCount);
		str += "           salinity " + std::to_string(salin);

		render::DrawTextF(10, 10, str.c_str(), RGB(255, 0, 0), 40);

	}
	void GameManager::DrawSomething()
	{
		//render::DrawRect(player.x - 25, player.y - 25, 50, 50, RGB(255, 0, 255));
		render::DrawRect(redBox.x - redBox.width / 2, redBox.y - redBox.height / 2, redBox.width, redBox.height, redBox.color);
		render::DrawRect(yellowBox.x - yellowBox.width / 2, yellowBox.y - yellowBox.height / 2, yellowBox.width, yellowBox.height, yellowBox.color);

	}

}