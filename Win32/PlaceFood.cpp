#include "InputSystem.h"
#include "ChooseFood.h"
#include "PlaceFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "LoadData.h"
#include "RenderSystem.h"

namespace PlaceFood
{
	//재료 선택에서 뽑힌 고명들을 옮겨받는다.
	button::DragDrop userPickDeco[8];
	//우동위에 올려지는 고명들을 저장할 배열.
	button::DragDrop userSet[8];
	//드래그중 일때 다른버튼은 안눌러지도록 하기
	button::DragDrop* draggingButton = nullptr;
	
	//배경 이미지 그리기
	void PrintScreen()
	{
		//배경그리기
		LoadData::imageManager->DrawBitMapImage("미니게임", 0, 0);
		//바구니 그리기
		for (int i = 0; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 + (i * 150), true);
		}

	}

	
}