#include "InputSystem.h"
#include "ChooseFood.h"
#include "PlaceFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "LoadData.h"
#include "RenderSystem.h"
#include "PlayerData.h"
#include "Types.h"
#include <vector>
#include "ScreenSystem.h"

namespace PlaceFood
{
	int basketIndex = 0;
	//재료 선택에서 뽑힌 고명들을 옮겨받는다.
	std::vector <Types::Decoration> a;
	button::DragDrop userPickDeco[8];  
	int decoList[8];

	//우동위에 올려지는 고명들을 저장할 배열.
	button::DragDrop userSet[8];

	//드래그중 일때 다른버튼은 안눌러지도록 하기
	button::DragDrop* draggingButton = nullptr;
	
	button::Button buttonList[3] =
	{
		button::Button("위쪽버튼",1500,100, 100, 100, UpBasket),
		button::Button("아래쪽버튼",1500, 900, 100, 100,DownBasket),
		button::Button("완료버튼",1650, 50, 200, 100, Selected),
	};
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
		//바구니 버튼 그리기
		for (int i = 0; i < 3; i++)
		{
			if ((basketIndex == 0 && i == 0) || (basketIndex == 5 && i == 1)) { continue; }
			buttonList[i].DrawButton();
		}
		
		PlaceFoodScreen();
	}
	//우동위에 좌표버튼 생성.
	void InitScreen()
	{
		userSet[0] = button::DragDrop(31, "바구니", 600, 250, 200, 200, Empty);
		userSet[1] = button::DragDrop(31, "바구니", 950, 250, 200, 200, Empty);

		userSet[2] = button::DragDrop(31, "바구니", 500, 450, 200, 200, Empty);
		userSet[3] = button::DragDrop(31, "바구니", 700, 450, 200, 200, Empty);
		userSet[4] = button::DragDrop(31, "바구니", 900, 450, 200, 200, Empty);
		userSet[5] = button::DragDrop(31, "바구니", 1100, 450, 200, 200, Empty);

		userSet[6] = button::DragDrop(31, "바구니", 600, 550, 200, 200, Empty);
		userSet[7] = button::DragDrop(31, "바구니", 950, 550, 200, 200, Empty);

		a = PlayerData::player.GetDecoation();
		for (int i = 0; i < 8; i++)
		{
			userPickDeco[i] = button::DragDrop((int)a[i], NULL, 1485, 200 + (i * 150), 100, 100, Test);
		}
	}
	void CheckButton(int dx, int dy)
	{
		for (int i = 0; i < 3; i++)
		{
			if ((basketIndex == 0 && i == 0) || (basketIndex == 5 && i == 1)) { continue; }
			if (buttonList[i].CheckClick(dx, dy) && draggingButton == nullptr)
			{
				buttonList[i].PlayFunction();
			}
		}
	}
	void CheckDragButton(int dx, int dy)
	{
		if (draggingButton == nullptr)
		{
			for (int i = 0; i < 8; i++)
			{
				if (userPickDeco[i].CheckDrag(dx, dy)&& (userPickDeco[i].canClick))
				{
					draggingButton = &userPickDeco[i];
					draggingButton->isDragging = true;
					userPickDeco[i].PlayFunction();
					break;
				}
			}
		}
		else {
			draggingButton->PlayFunction();
		}
	}

	void CheckDropButton(int dx, int dy)
	{
		if (draggingButton != nullptr)
		{
			if (draggingButton->isDragging)
			{
				int currentX = draggingButton->getXPos();
				int currentY = draggingButton->getYPos();
				for (int i = 0; i < 8; i++)
				{
					if ((currentX > userSet[i].getXPos()  && currentY > userSet[i].getYPos() ) && (currentX < userSet[i].getXPos() + 200 && currentY < userSet[i].getYPos() + 200) && userSet[i].nameTag == Types::Basket::BASKET)
					{
						//놓기
						userSet[i].nameTag = draggingButton->nameTag;
						////바구니버튼에 이미지값을 전달하고 나서 재료는 클릭할수없도록 설정.
						draggingButton->nameTag = -1;
						draggingButton->canClick = false;
						break;
					}
					//바구니 안이 아닌경우 원래자리로 돌아가기.
					//noodleButtonList[i]getdragg6ing ==false로변경
					//draggingButton에 있는 값 없애기
				}
				if (draggingButton->canClick != false)
				{
					draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
					draggingButton->width = 100;
					draggingButton->height = 100;
				}
				draggingButton->isDragging = false;
				draggingButton = nullptr;
			}
		}
	}



	void PlaceFoodScreen()
	{
		for (int i = 0; i < 8; i++)
		{
			//바구니위에 고명 랜더
			if (userPickDeco[i].canClick == true && draggingButton == nullptr)
			{
				userPickDeco[i].setYPos(basketIndex);
			}
			if (userPickDeco[i].getYPos() > 100 && userPickDeco[i].getYPos() < 900)
			{
				userPickDeco[i].DrawDeco();
			}
			//유저가 우동위에올리는 고명 랜더
			if (userSet[i].nameTag != 31)
			{
				userSet[i].DrawDeco();
			}
		}

	}
	void Test()
	{
		if (draggingButton->isDragging) {
			input::UpdateMouse();
			const input::MouseState& mouse = input::GetMouseState();
			int xPos = mouse.x - 50;
			int yPos = mouse.y - 50;
			if (input::GetMouseState().isDragging)
			{
				draggingButton->setSize(150, 150);
				draggingButton->setPos(xPos, yPos);
			}
		}
	}
	void UpBasket()
	{
		basketIndex--;
	}
	void DownBasket()
	{
		basketIndex++;
	}
	void Selected()
	{
		Screen::SetScreen();
	}
	void Empty(){}


	int* GetDeco()
	{

		for (size_t i = 0; i < 8; i++)
		{
			decoList[i] = userSet[i].nameTag;
		}

		return decoList;
	}
	
}