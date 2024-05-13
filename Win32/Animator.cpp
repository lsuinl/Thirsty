#include "Animator.h"

	Animator::Animator(std::string name,int x, int y, int width, int height,int animationLimit, std::string* imageList,bool loop, bool to)
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
	}
	Animator::Animator() {

	}

	Animator::~Animator() {

	}

	void Animator::SetAnimation()
	{
		animation = true;
	}
	
	std::string Animator::GetAnimationName()
	{
		return name;
	}
	
	void Animator::DrawAnimation()
	{
		if (animation)
		{
			animationTime += TimeSystem::GetDeltaTime();
			//�ִϸ��̼� ��ȯ
			if (animationTime < animationLimit) 
			{
				//100/(200)
		
				const char * word = (imageList[animationTime / ( animationLimit / (10)) ].c_str());
				render::DrawBackGround(word, width, height, x, y, to);
			}
			else 
			{
				animationTime = 0;
				const char* word = (imageList[animationTime / (animationLimit / (10))].c_str());
				render::DrawBackGround(word, width, height, x, y, to);
				//��ȯ ����(�ݺ��� ���� �ٽ� ���)
	
				if (!loop) 
				{
					animation = false;
				}
			}
		}
	}