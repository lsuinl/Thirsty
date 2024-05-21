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
		this->to=to;
		this->imagelength = imagelength;
		// ��� ���� imageList�� ���� �޸� �Ҵ�
		this->imageList = new std::wstring[imagelength];

		// ���� ���� ����
		for (int i = 0; i < imagelength; i++) {
			this->imageList[i] = imageList[i];
		}
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
			//�ִϸ��̼� ��ȯ
			if ( animationTime < animationLimit && animationTime>0)
			{
 				std::wstring word = imageList[animationTime / (animationLimit / imagelength)];
				render::DrawObject(word.c_str(), width, height, x, y, 1.0f,to);
			}
			else 
			{
				animationTime = 0;
				std::wstring word = imageList[animationTime / (animationLimit / imagelength)].c_str();
				render::DrawObject(word.c_str(), width, height, x, y, to);
				//��ȯ ����(�ݺ��� ���� �ٽ� ���)
				if (!loop) 
				{
					delete[] imageList;
					animation = false;
				}
			}
		}
	}