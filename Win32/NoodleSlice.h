#pragma once
#include "GlobalHeader.h"
class NoodleSlice
{
public:

	// 방향키 타입
	enum ArrowType
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

	// Arrow 구조체 배열 선언
	Arrow** arrowArr;

	// 면 타입
	enum NoodleType
	{
		NOODLE1 = 4,
		NOODLE2 = 6,
		NOODLE3 = 8
	};

	// 방향키 올킬 여부
	bool isSuccess;

	// timer
	float resetTimer;
	float playTimer;

	// 게임 세팅
	void SetGame(int _stage, NoodleType _noodle);

	// 게임루프
	void UpdateGame();

	// 배열 해제
	void ReleaseGame();

	// 방향키 입력
	void InputArrow();

	// cnt 반환
	int GetCnt();

	// setcnt 반환
	int GetSetCnt();

	// arrsize 반환
	int GetArrSize();

	// render
	void NoodleSliceScreen();

	// success
	bool NoodleSuccess();

	// 애니메이션
	void SliceAni();

private:

	// 배열 사이즈
	int arrSize;

	// 방향키 맞춘 횟수
	int cnt;

	// 세트 횟수
	int setCnt;

	// 플레이어 점수
	int playerScore;

	// 초기화 판단
	bool isReset;

	// 면개수 변수
	int stage;

	// 누들타입 변수
	int noodle;

	// 방향키 배열 생성
	void CreatArrowArr();

	// 방향키 맞게 쳤는지 검사
	void CompareArrow(ArrowType keyCode);
};
