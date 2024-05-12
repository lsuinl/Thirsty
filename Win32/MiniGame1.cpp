#include "MiniGame1.h"

// 게임 세팅
int MiniGame1::SetGame(StageNoodle _stage, NoodleType _noodle)
{
	// 맞춘 횟수
	Cnt = 0;
	stage = _stage;
	noodle = _noodle;

	arrSize = (int)stage * (int)noodle;

	CreatArrowArr();
	return 1;
}


// 게임루프
int MiniGame1::UpdateGame(ArrowType keyCode)
{
	CompareArrow(keyCode);
	return 1;
}

// 배열 해제
void MiniGame1::ReleaseGame()
{
	delete[] arrowArr;
}

// 방향키 배열 생성
void MiniGame1::CreatArrowArr()
{
	// 배열 생성
	// (랜덤으로.. 38 = ↑, 37 = ←, 40 = ↓, 39 = →)
	arrowArr = new Arrow[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		(arrowArr + i)->arrowType = rand() % 4 + 37;
		(arrowArr + i)->isTrue = false;
	}
}

// 방향키 맞게 쳤는지 검사
void MiniGame1::CompareArrow(ArrowType keyCode)
{
	if (arrowArr[Cnt].arrowType == (int)keyCode)
	{
		Cnt++;
	}
	else
	{
		Cnt = 0;
	}
}

