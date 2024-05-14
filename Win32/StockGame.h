#pragma once
#include <windows.h>
#include "RenderSystem.h"
#include "InputSystem.h"
struct boxObject
{
	float x;
	float y;
	float width;
	float height;
	float speed;

	COLORREF color;


	void MoveStop()
	{
		this->x = this->x;
	}
	void MoveRight(float speed, float delta)
	{
		if (this->x + this->width / 2 <= 1800)
		{
			this->x += speed * delta;
		}
	}

	void MoveLeft(float speed, float delta)
	{
		if (this->x - this->width / 2 >= 200)
		{
			this->x += speed * -1 * delta;
		}
	}

	void SetBox(float x, float y, float width, float height, float speed, COLORREF color)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->speed = speed;
		this->color = color;
	}
};
class StockGame
{
private:
	int score = 0;
	int salinity = 0;
	int targetSalinity;
	float timeLimit = 1000000;  //게임 시간제한
	bool isTimeOver = false;


	//float printTime;
	//const wchar_t* str1[5] = { L"흔히 이승에서  aadwad사는 유령은 1234567890 ㅂㅈㄷㄱ ㅁㄴㅇㄹ ㅋㅌㅊㅍ", 
	//	L"흔히 저승에서  어쩌구 저쩌구  안녕하세요 유령입니다ㅈㅁㅇfadwadwad",L"adwadwadd",L"dwadwadwa",L"dwad끝끝끝끝끝"};  //시나리오 대사를 미리 입력해둘1
	//wchar_t str2[5][100];  //각 시나리오일떄 1번을 카피해서 저장해둘 2
	//wchar_t str3[5][100];  //하나씩 출력할떄 저장해둘 3
	//int i = 0;
	//int j = 0;


public:
	StockGame();
	~StockGame();
	boxObject blackBox = { 900 ,900, 1400, 70, 0, RGB(0, 0, 0) };
	boxObject redBox = { 900, 900, 360, 90 ,0.8 ,RGB(255,0 ,0) };
	boxObject yellowBox = { 900, 900, 260, 70 ,0.7 ,RGB(255,255 ,0) };

	//박스충돌확인
	bool isCollide(boxObject obj1, boxObject obj2);

	//박스가 70퍼이상속해있는지 확인후 염도조절
	void Overlab(boxObject obj1, boxObject obj2);

	//염도값 얻기
	int GetSalinity();

	//게임시간 확인
	void CheckGameTimeOver(float time);

	//염도 게이지 표시
	void DrawProgressBar();

	//미니게임 막대들 그리기
	void DrawBoxs();

	//스테이지별 설정
	void SetGame(int stage);

	//랜덤으로 빨간박스 움직임
	void UpdateRedBox(float delta);

	//입력받아서 노란박스 움직임
	void UpdateYellowBox(float delta);

	//두 박스간 충돌검사밑 염분값 조정
	void UpdateGame(float delta);

	//StockGame 전체렌더
	void RenderStockGame();

	//게임 스코어 반환
	int GameScore();



	////키입력시 빠르게 업데이트 or 한줄 다 업데이트 후 다음줄로
	//void SkipText(float delta);

	////텍스트를 한글자씩 복사해서 업데이트
	//void UpdateText();
	//
	////텍스트 출력
	//void PrintText();



};
