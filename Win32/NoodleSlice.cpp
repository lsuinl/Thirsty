#include "NoodleSlice.h"


// 게임 세팅
void NoodleSlice::SetGame(StageNoodle _stage, NoodleType _noodle)
{
	srand(time(NULL));
	// 맞춘 횟수
	cnt = 0;
	setCnt = 0;
	playerScore = 0;

	isReset = false;

	stage = (int)_stage;
	noodle = (int)_noodle;

	arrSize = (int)stage * (int)noodle;

	CreatArrowArr();
}

float timer = 0;

// 게임루프
void NoodleSlice::UpdateGame()
{
	InputArrow();

	if (isReset)
	{
		timer += TimeSystem::GetDeltaTime();
		if (timer > 1000)
		{
			isReset = false;
		}
	}
}

// 배열 해제
void NoodleSlice::ReleaseGame()
{
	delete[] arrowArr;
}

// 방향키 배열 생성
void NoodleSlice::CreatArrowArr()
{
	// 배열 생성
	// (랜덤으로.. 38 = ↑, 37 = ←, 40 = ↓, 39 = →)
	arrowArr = new Arrow * [noodle * 2]; // 행 수만큼의 포인터를 가리키는 배열 생성

	for (int i = 0; i < noodle * 2; ++i) {
		arrowArr[i] = new Arrow[stage];
	}

	for (int i = 0; i < noodle * 2; i++)
	{
		for (int j = 0; j < stage; j++)
		{
			(arrowArr[i][j].arrowType = rand() % 4 + 37);
			(arrowArr[i][j].isTrue = false);
		}
	}
}

// 방향키 맞게 쳤는지 검사
void NoodleSlice::CompareArrow(ArrowType keyCode)
{
	// 맞았다면?
	if (arrowArr[setCnt][cnt % stage].arrowType == (int)keyCode)
	{
		arrowArr[setCnt][cnt % stage].isTrue = true;
		cnt++;
		playerScore++;
	}
	else // 못맞췄을 시 처음부터 다시
	{
		timer = 0;
		isReset = true;
		playerScore = 0;
		cnt = 0;

		for (int i = setCnt; i < noodle * 2; i++)
		{
			for (int j = 0; j < stage; j++)
			{
				arrowArr[i][j].isTrue = false;
			}
		}
	}

	if (cnt != 0)
	{
		if (cnt % stage == 0)
		{
			setCnt++;
		}
	}
}

// 방향키 입력받은 후 처리 시스템
void NoodleSlice::InputArrow()
{
	if (input::IsKeyDown(38)) // up
	{
		CompareArrow(UPARROW);
	}
	else if (input::IsKeyDown(37)) // left
	{
		CompareArrow(LEFTARROW);
	}
	else if (input::IsKeyDown(40)) // down
	{
		CompareArrow(DOWNARROW);
	}
	else if (input::IsKeyDown(39)) // right
	{
		CompareArrow(RIGHTARROW);
	}
}

// cnt 반환
int NoodleSlice::GetCnt()
{
	return cnt;
}

// setcnt 반환
int NoodleSlice::GetSetCnt()
{
	return setCnt;
}

// arrsize 반환
int NoodleSlice::GetArrSize()
{
	return arrSize;
}

// render
void NoodleSlice::NoodleSliceScreen()
{
	// 치기 전
	for (int i = setCnt; i < setCnt + 1; i++)
	{
		for (int j = 0; j < stage; j++)
		{
			if (arrowArr[i][j].arrowType == UPARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawRect(50 + (j % stage) * 100, 100, 100, 100, RGB(237, 28, 36)); // 빨
			}
			else if (arrowArr[i][j].arrowType == DOWNARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawRect(50 + (j % stage) * 100, 100, 100, 100, RGB(255, 203, 0)); // 노
			}
			else if (arrowArr[i][j].arrowType == RIGHTARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawRect(50 + (j % stage) * 100, 100, 100, 100, RGB(25, 255, 0)); // 초
			}
			else if (arrowArr[i][j].arrowType == LEFTARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawRect(50 + (j % stage) * 100, 100, 100, 100, RGB(0, 39, 255)); // 파
			}
		}
	}

	// 틀렸을 때 잠깐 색 바꾸기
	if (isReset == true)
	{
		for (int i = setCnt; i < noodle * 2; i++)
		{
			for (int j = 0; j < stage; j++)
				render::DrawRect(50 + (j % stage) * 100, 100, 100, 100, RGB(0, 0, 0)); // 검
		}
	}

	std::string str = "player score :" + std::to_string(playerScore);
	render::DrawTextF(10, 10, str.c_str(), RGB(0, 0, 0), 20);
}