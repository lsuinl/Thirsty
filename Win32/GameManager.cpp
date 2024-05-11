#include "WinApp.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "RenderSystem.h"
#include "GameManager.h"
#include <string>

namespace game
{
	

	GameManager::Object redBox = { global::GetWinApp().GetWidth() / 2, 500, 360, 90, 10, RGB(255, 0, 0) };
	GameManager::Object yellowBox = { global::GetWinApp().GetWidth() / 2 ,500, 260, 70, 10, RGB(255, 255, 0) };
	
	


	void UpdatePlayer()
	{
		// 게임 로직은 여기에 추가
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
		++m_UpdateCount;

		input::UpdateMouse();

		UpdatePlayer();
		

		input::ResetInput();

	}

	void GameManager::FixeUpdate()
	{
		static ULONGLONG elapsedTime;

		elapsedTime += time::GetDeltaTime();

		while (elapsedTime >= 50) //0.02초
		{
			
			Overlab(redBox, yellowBox);

			elapsedTime -= 20;
		}
	}

	void GameManager::Render()
	{
		render::BeginDraw();

		DrawFPS();
		DrawSomething();
		DrawPlayer();

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
			//GetMessage 는 큐에 메시지가 있을 때까지 대기, 블러킹
			//PeekMessage 는 메시지가 있으면 처리하고 아니면 넌블러킹
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

		std::string str = "FPS: " + std::to_string(time::GetFrameRate());
		str += "           Update " + std::to_string(UpdateCount);
		str += "           FixedUpdate " + std::to_string(FixedUpdateCount);
		str += "           salinity " + std::to_string(salinity);
		render::DrawText(10, 10, str.c_str(), RGB(255, 0, 0));

	}

	void GameManager::DrawPlayer()
	{
		
	}

	void GameManager::DrawSomething()
	{

		
		//render::DrawRect(player.x - 25, player.y - 25, 50, 50, RGB(255, 0, 255));
		render::DrawRect(redBox.x - redBox.width / 2, redBox.y - redBox.height / 2 , redBox.width , redBox.height ,redBox.color);
		render::DrawRect(yellowBox.x - yellowBox.width / 2, yellowBox.y - yellowBox.height / 2, yellowBox.width, yellowBox.height, yellowBox.color);

	}
	//두 오브젝트 충돌검사
	bool GameManager::isCollide(Object obj1, Object obj2)
	{
		if (obj1.x < obj2.x + obj2.width &&
			obj1.x + obj1.width > obj2.x &&
			obj1.y < obj2.y + obj2.height &&
			obj1.y + obj1.height > obj2.y)
		{
			return true;
		}
		return false;
	}

	//노란상자가 70퍼센트이상 속했는지 확인
	void GameManager::Overlab(Object obj1, Object obj2)
	{
		float totalSize = 0.0f;
		Object bigObj;
		Object smallObj;
		if (obj1.width > obj2.width)
		{
			bigObj = obj1;
			smallObj = obj2;
		}
		else
		{
			bigObj = obj2;
			smallObj = obj1;
		}
		if (isCollide(bigObj, smallObj) == true)
		{
			if (bigObj.x >= smallObj.x)
			{
				totalSize = (bigObj.x + bigObj.width / 2) - (smallObj.x - smallObj.width / 2);
			}
			else
			{
				totalSize = (smallObj.x + smallObj.width / 2) - (bigObj.x - bigObj.width / 2);
			}
		}
		
		if (isCollide(bigObj, smallObj) && totalSize <= bigObj.width + smallObj.width * 0.3)
		{
			salinity++;
		}
		else
		{
			salinity--;
		}
	}
}
