#pragma once

namespace game
{
	class GameManager
	{
	public:
		GameManager();

		~GameManager();

		void Initialize();

		void Update();

		void FixeUpdate();

		void Render();

		void Finalize();

		void Run();

		struct Object
		{
			float x;
			float y;
			float size;
			float speed;

			COLORREF color;

			void SetPos(float x, float y)
			{
				this->x = x;
				this->y = y;
			}

			void Move(float x, float y)
			{
				this->x += x;
				this->y += y;
			}
		};

		static GameManager* GetInstance();

		

		static void DestroyInstance();

	private:

		void DrawFPS();
		void DrawPlayer();
		void DrawSomething();

		static GameManager* instance;

		int m_UpdateCount = { 0 };
		int m_FixedUpdateCount = { 0 };

	};

	
}

