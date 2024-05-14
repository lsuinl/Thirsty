#include "Animator.h"
#include <string>

#include "Animations.h"
namespace Animations {
	std::wstring* imageList= new std::wstring[10];
	Animator Animation[2];
	void Animations::LoadImageList() {
		for (int i = 1; i <= 10; i++) 
		{
			imageList[i-1] = L"resource\\animation\\test\\" + std::to_wstring(i) + L".bmp";
		}
		Animation[0] = Animator("테스트", 300, 100, 400, 400, 800, imageList, true, false);
		Animation[1] = Animator("아니",600, 300, 400, 400, 1200, imageList, true, true);
	}

	void Animations::SetAnimation(const char* name) {
		for (int i = 0; i < 2; i++) {
			if (Animation[i].GetAnimationName() == name) {
				Animation[i].SetAnimation();
			}
		}
	}
	void Animations::RenderAnimation() {
		for (int i = 0; i < 2; i++) {
			Animation[i].DrawAnimation();
		}
	}
}