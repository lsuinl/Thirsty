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
	int basketIndex = 0;
	//��� ���ÿ��� ���� ������ �Űܹ޴´�.
	Types::Decoration* a = PlayerData::player.GetDecoation();
	button::DragDrop userPickDeco[8];  

	//�쵿���� �÷����� ������ ������ �迭.
	button::DragDrop userSet[8];

	//�巡���� �϶� �ٸ���ư�� �ȴ��������� �ϱ�
	button::DragDrop* draggingButton = nullptr;
	
	button::Button buttonList[3] =
	{
		button::Button("���ʹ�ư",1500,100, 100, 100, UpBasket),
		button::Button("�Ʒ��ʹ�ư",1500, 900, 100, 100,DownBasket),
		button::Button("�Ϸ��ư",1650, 50, 200, 100, Selected),
	};
	//��� �̹��� �׸���
	void PrintScreen()
	{
		//���׸���
		LoadData::imageManager->DrawBitMapImage("�̴ϰ���", 0, 0);
		//�ٱ��� �׸���
		for (int i = 0; i < 5; i++)
		{
			render::DrawObject(L"resource\\object\\basket.bmp", 150, 100, 1485, 200 + (i * 150), true);
		}
	}
	//�쵿���� ��ǥ��ư ����.
	void InitScreen()
	{
		userSet[0] = button::DragDrop(31, "�ٱ���", 550, 300, 200, 200, Empty);
		userSet[1] = button::DragDrop(31, "�ٱ���", 750, 300, 200, 200, Empty);

		userSet[2] = button::DragDrop(31, "�ٱ���", 350, 450, 200, 200, Empty);
		userSet[3] = button::DragDrop(31, "�ٱ���", 550, 450, 200, 200, Empty);
		userSet[4] = button::DragDrop(31, "�ٱ���", 750, 450, 200, 200, Empty);
		userSet[5] = button::DragDrop(31, "�ٱ���", 950, 450, 200, 200, Empty);

		userSet[6] = button::DragDrop(31, "�ٱ���", 550, 600, 200, 200, Empty);
		userSet[7] = button::DragDrop(31, "�ٱ���", 750, 600, 200, 200, Empty);

		for (int i = 0; i < 8; i++)
		{
			userPickDeco[i] = button::DragDrop((int)(a + i), NULL, 1485, 200 + (i * 150), 100, 100, Test);
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
			for (int i = 0; i < 8; i++)
			{
				if (draggingButton->isDragging)
				{
					int currentX = draggingButton->getXPos();
					int currentY = draggingButton->getYPos();

					if ((currentX > userSet[i].getXPos() - 50 && currentY > userSet[i].getYPos() - 50) && (currentX < userSet[0].getXPos() + 50 && currentY < userSet[0].getYPos() + 50) && userSet[i].nameTag == Types::Basket::BASKET)
					{
						userSet[i].nameTag = draggingButton->nameTag;
						////�ٱ��Ϲ�ư�� �̹������� �����ϰ� ���� ���� Ŭ���Ҽ������� ����.
						draggingButton->nameTag = -1;
						draggingButton->canClick = false;
					}
					//�ٱ��� ���� �ƴѰ�� �����ڸ��� ���ư���.
					else
					{
						draggingButton->setPos(draggingButton->getOriginX(), draggingButton->getOriginY());
						draggingButton->width = 100;
						draggingButton->height = 100;
					}
					//noodleButtonList[i]getdragg6ing ==false�κ���
					draggingButton->isDragging = false;
					//draggingButton�� �ִ� �� ���ֱ�
					draggingButton = nullptr;
					break;
				}
			}
		}
	}
	void PlaceFoodScreen()
	{
		for (int i = 0; i < 8; i++)
		{
			//�ٱ������� ��� ����
			userPickDeco[i].setYPos(basketIndex);
			if (userPickDeco[i].getYPos() > 100 && userPickDeco[i].getYPos() < 900)
			{
				userPickDeco[i].DrawDeco();
			}
			//������ �쵿�����ø��� ��� ����
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
	void Empty(){}

}