#include "NoodleSlice.h"
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
	// 치기 전
	for (int i = setCnt; i < setCnt + 1; i++)
	{
		for (int j = 0; j < stage; j++)
		{
			if (arrowArr[i][j].arrowType == UPARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawBackGround("resource/object/up.bmp",100,100, 50 + (j % stage) * 100, 100, false);
			}
			else if (arrowArr[i][j].arrowType == DOWNARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawBackGround("resource/object/down.bmp", 100, 100, 50 + (j % stage) * 100, 100, false);
			}
			else if (arrowArr[i][j].arrowType == RIGHTARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawBackGround("resource/object/right.bmp", 100, 100, 50 + (j % stage) * 100, 100, false);
			}
			else if (arrowArr[i][j].arrowType == LEFTARROW && arrowArr[i][j].isTrue == false)
			{
				render::DrawBackGround("resource/object/left.bmp", 100, 100, 50 + (j % stage) * 100, 100, false);
			}
		}
	}

	// 틀렸을 때 잠깐 색 바꾸기
	if (isReset == true)
	{
		for (int i = setCnt; i < noodle; i++)
		{
			for (int j = 0; j < stage; j++)
				render::DrawRect(50 + (j % stage) * 100, 100, 100, 100, RGB(0, 0, 0)); // 검
		}
	}

	std::string str = "맞춘 횟수 :" + std::to_string(cnt);
	str += "           세트 횟수 : " + std::to_string(setCnt);
	render::DrawTextF(10, 10, str.c_str(), RGB(0, 0, 0), 20);
}