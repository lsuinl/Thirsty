#pragma once
#include "GlobalHeader.h"
class Animator {
	std::string name;
	bool animation = false, loop; //애니메이션 활성화 시키기
	std::wstring* imageList; //애니메이션 리소스
	int x, y; //좌표
	int width, height; //크기
	int animationTime = 0, animationLimit = 2000; //재생시간
	bool to;
	int imagelength;
public:
	~Animator();
	Animator();
	Animator(std::string name,int x, int y, int width, int height, int animationLimit,  std::wstring* imageList, bool loop, bool to, int imagelength);
	//애니메이션 활성화
	void SetAnimation(); 
	//애니메이션 상태보기
	bool GetAnimationCheck();
	//애니메이션 그리기
	void DrawAnimation(); 
};