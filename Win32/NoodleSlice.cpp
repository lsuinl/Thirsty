﻿#include "NoodleSlice.h"
#include <time.h>

// 게임 세팅
void NoodleSlice::SetGame(StageNoodle _stage, NoodleType _noodle)
{
	srand(time(NULL));

	// 플레이 시간
	playTimer = 0;
	
	// 성공 여부
	isSuccess = false;

	// 맞춘 횟수
	cnt = 0;

	// 세트 카운트
	setCnt = 0;

	// 스코어
	playerScore = 0;

	// 초기화 여부
	isReset = false;

	// 변수 대입
	stage = (int)_stage;
	noodle = (int)_noodle;

	// 최대 사이즈
	arrSize = stage * noodle;

	// 배열 생성
	CreatArrowArr();
}

// 게임루프
void NoodleSlice::UpdateGame()
{
	playTimer += TimeSystem::GetDeltaTime();

	if (playTimer <= 20000)
	{
		InputArrow();

		if (isReset)
		{
			resetTimer += TimeSystem::GetDeltaTime();
			if (resetTimer > 700)
			{
				isReset = false;
			}
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
	arrowArr = new Arrow * [noodle]; // 행 수만큼의 포인터를 가리키는 배열 생성

	for (int i = 0; i < noodle; ++i) {
		arrowArr[i] = new Arrow[stage];
	}

	for (int i = 0; i < noodle; i++)
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

		if (cnt < arrSize - 1)
		{
			cnt++;
		}
		else
		{
			isSuccess = true;
		}

		playerScore++;
		if (cnt != 0 && cnt < arrSize)
		{
			if (cnt % stage == 0)
			{
				setCnt++;
			}
		}
	}
	else // 못맞췄을 시 처음부터 다시
	{
		resetTimer = 0;
		isReset = true;
		playerScore = 0;
		cnt = setCnt * stage ;

		for (int i = setCnt; i < noodle; i++)
		{
			for (int j = 0; j < stage; j++)
			{
				arrowArr[i][j].isTrue = false;
			}
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
	render::DrawObject(L"resource\\background\\back.bmp", 1920, 1080, 0, 0, false);

	// 치기 전
	for (int i = setCnt; i < setCnt + 1; i++)
	{
		for (int j = 0; j < stage; j++)
		{
			if (arrowArr[i][j].arrowType == UPARROW)
			{
				if (arrowArr[i][j].isTrue == true)
				{
					render::DrawObject(L"resource\\object\\up.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else
				{
					render::DrawObject(L"resource\\object\\up2.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
			}
			else if (arrowArr[i][j].arrowType == DOWNARROW)
			{
				if (arrowArr[i][j].isTrue == true)
				{
					render::DrawObject(L"resource\\object\\down.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else
				{
					render::DrawObject(L"resource\\object\\down2.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
			}
			else if (arrowArr[i][j].arrowType == RIGHTARROW)
			{
				if (arrowArr[i][j].isTrue == true)
				{
					render::DrawObject(L"resource\\object\\right.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else
				{
					render::DrawObject(L"resource\\object\\right2.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
			}
			else if (arrowArr[i][j].arrowType == LEFTARROW)
			{
				if (arrowArr[i][j].isTrue == true)
				{
					render::DrawObject(L"resource\\object\\left.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else
				{
					render::DrawObject(L"resource\\object\\left2.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
			}
		}
	}

	// 틀렸을 때 잠깐 색 바꾸기
	if (isReset == true)
	{
		for (int i = setCnt; i < setCnt + 1; i++)
		{
			for (int j = 0; j < stage; j++)
			{
				if (arrowArr[i][j].arrowType == UPARROW)
				{
					render::DrawObject(L"resource\\object\\up1.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else if (arrowArr[i][j].arrowType == DOWNARROW)
				{
					render::DrawObject(L"resource\\object\\down1.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else if (arrowArr[i][j].arrowType == RIGHTARROW)
				{
					render::DrawObject(L"resource\\object\\right1.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
				else if (arrowArr[i][j].arrowType == LEFTARROW)
				{
					render::DrawObject(L"resource\\object\\left1.bmp", 100, 100, 500 + (j % stage) * 100, 150, true);
				}
			}
		}
	}

	render::DrawRect(1500, 200, 300, 300, RGB(255, 255, 255));
	render::DrawRect(1500, 600, 300, 300, RGB(255, 255, 255));

	std::string str1 = "완료 횟수";
	std::string str2 = "남은 세트";
	std::string clear_s = std::to_string(setCnt);
	std::string before_s = std::to_string(noodle - setCnt);

	render::DrawTextF(1560, 250, str1.c_str(), RGB(0, 0, 0), 50);
	render::DrawTextF(1560, 650, str2.c_str(), RGB(0, 0, 0), 50);
	render::DrawTextF(1620, 350, clear_s.c_str(), RGB(0, 0, 0), 100);
	render::DrawTextF(1620, 750, before_s.c_str(), RGB(0, 0, 0), 100);

	std::string time = "남은 시간  " + std::to_string((int)(20 - playTimer / 1000)) + " 초";
	render::DrawTextF(0, 0, time.c_str(), RGB(0, 0, 0), 50);

}