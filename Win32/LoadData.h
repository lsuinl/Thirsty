#pragma once
#include "SoundManager.h"
//이미지, 사운드, 기본 데이터 로드 
namespace LoadData
{
	//extern Music::SoundManager* soundManager;  // extern을 사용하여 외부에서 접근 가능하도록 선언
	void LoadMusic();

	//로드한 이미지 저장
	void LoadImages();
	
	
	//로드한 애니메이션 저장
	void LoadAnimation();
};

