#pragma once
#include <stdlib.h>
#include <time.h>

class MiniGame1
{
public:

	// 방향키 타입
	enum class ArrowType
	{
		UPARROW = 38,
		LEFTARROW = 37,
		DOWNARROW = 40,
		RIGHTARROW = 39
	};

	// 랜덤 방향키 생성 구조체
	struct Arrow
	{
		int arrowType;
		bool isTrue;
	};

	// 스테이지에 따른 면 개수
	enum class StageNoodle
	{
		STAGE1 = 4,
		STAGE2 = 6,
		STAGE3 = 8
	};

	// 면 타입
	enum class NoodleType
	{
		NOODLE1 = 1,
		NOODLE2 = 2,
		NOODLE3 = 4
	};

	// 게임 세팅
	int SetGame(StageNoodle _stage, NoodleType _noodle);

	// 게임루프
	int UpdateGame(ArrowType keyCode);

	// 배열 해제
	void ReleaseGame();

private:

	// Arrow 구조체 배열 선언
	Arrow* arrowArr;

	// 배열 사이즈
	int arrSize = 0;

	// 방향키 맞춘 횟수
	int Cnt = 0;

	// 면개수 변수
	StageNoodle stage;

	// 누들타입 변수
	NoodleType noodle;

	// 방향키 배열 생성
	void CreatArrowArr();

	// 방향키 맞게 쳤는지 검사
	void CompareArrow(ArrowType keyCode);

};
