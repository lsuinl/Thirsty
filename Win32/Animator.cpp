#include "Animator.h"

	Animator::Animator(std::string name,int x, int y, int width, int height,int animationLimit, std::wstring* imageList,bool loop, bool to, int imagelength)
	{
		this->name = name;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->animationLimit = animationLimit;
		this->loop = loop;
		this->to;
		this->imageList = imageList;
		this->imagelength = imagelength;
	}
	Animator::Animator() {

	}

	Animator::~Animator() {

	}

	void Animator::SetAnimation()
	{
		animation = true;
	}
	
	bool Animator::GetAnimationCheck()
	{
		return animation;
	}
	
	void Animator::DrawAnimation()
	{
		if (animation)
		{
			animationTime += TimeSystem::GetDeltaTime();
			//애니메이션 젼환
			if (animationTime < animationLimit) 
			{
				//100/(200)		
				std::wstring word = imageList[animationTime / ( animationLimit / imagelength)];
				render::DrawObject(word.c_str(), width, height, x, y, 1.0f,to);
			}
			else 
			{
				animationTime = 0;
				std::wstring word = imageList[animationTime / (animationLimit / imagelength)].c_str();
				render::DrawObject(word.c_str(), width, height, x, y, to);
				//전환 종료(반복인 경우는 다시 재생)
	
				if (!loop) 
				{
					animation = false;
				}
			}
		}
	}