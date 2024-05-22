#include "Animator.h"

	Animator::Animator(std::string name,int x, int y, int width, int height,int animationLimit, Gdiplus::Image*** imageList,bool loop, bool to, int imagelength)
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
		this->imageList = new Gdiplus::Image* [imagelength];
		// ���� ���� ����
		for (int i = 0; i < imagelength; i++)
		{
			this->imageList[i] = *(*(imageList)+i);
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
		int index = animationTime / (animationLimit / imagelength);
		if (index>= imagelength-2)
		{
			return false;
		}
		return animation;
	}
	
	void Animator::DrawAnimation()
	{
		if (animation)
		{
			if(imagelength==180)
				render::DrawObjects(*(imageList+imagelength - 1), width, height, x, y, 1.0f, to);
			animationTime += TimeSystem::GetDeltaTime();
			//�ִϸ��̼� ��ȯ
			if ( animationTime < animationLimit)
			{
				int index = animationTime / (animationLimit / imagelength);
				if (index < imagelength)
				{
					render::DrawObjects(*(imageList + index), width, height, x, y, 1.0f, to);
				}
				if (index == imagelength && imagelength ==180)
				{
					render::DrawObjects(*(imageList +179), width, height, x, y, 1.0f, to);
				}
			}
			else 
			{
				render::DrawObjects(*(imageList+imagelength-1), width, height, x, y, 1.0f, to);
				animationTime = 0;
				//��ȯ ����(�ݺ��� ���� �ٽ� ���)
				if (!loop) 
				{
					animation = false;
				}
			}
		}
	}
