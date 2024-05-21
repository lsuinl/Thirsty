#include "InputSystem.h"
#include "ChooseFood.h"
#include "PlaceFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "LoadData.h"
#include "RenderSystem.h"
#include "PlayerData.h"
#include "Types.h"

namespace PlaceFood
{
	//재료 선택에서 뽑힌 고명들을 옮겨받는다.
	Types::Decoration* a = PlayerData::player.GetDecoation();
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
	//우동위에 좌표버튼 생성.
	void InitScreen()
	{
		userSet[0] = button::DragDrop(31, "바구니", 550, 300, 200, 200, Empty);
		userSet[1] = button::DragDrop(31, "바구니", 750, 300, 200, 200, Empty);

		userSet[2] = button::DragDrop(31, "바구니", 350, 450, 200, 200, Empty);
		userSet[3] = button::DragDrop(31, "바구니", 550, 450, 200, 200, Empty);
		userSet[4] = button::DragDrop(31, "바구니", 750, 450, 200, 200, Empty);
		userSet[5] = button::DragDrop(31, "바구니", 950, 450, 200, 200, Empty);

		userSet[6] = button::DragDrop(31, "바구니", 550, 600, 200, 200, Empty);
		userSet[7] = button::DragDrop(31, "바구니", 750, 600, 200, 200, Empty);

		for (int i = 0; i < 8; i++)
		{
			userPickDeco[i] = button::DragDrop((int)(a + i), NULL, 1485, 200 + (i * 150), 100, 100, Empty);
		}
	}
	 
	void Empty()
	{
		
	}
}