#include "RenderSystem.h"
#include "TimeSystem.h"
#include <string>
#pragma once
class Animator {
	std::string name;
	bool animation = false, loop; //애니메이션 활성화 시키기
	std::string* imageList; //애니메이션 리소스
	int x, y; //좌표
	int width, height; //크기
	int animationTime = 0, animationLimit = 2000; //재생시간
	bool to;
public:
	~Animator();
	Animator();
	Animator(std::string name,int x, int y, int width, int height, int animationLimit, std::string* imageList, bool loop, bool to);
	//애니메이션 활성화
	void SetAnimation(); 
	//애니메이션 상태보기
	std::string GetAnimationName();
	//애니메이션 그리기
	void DrawAnimation(); 
};