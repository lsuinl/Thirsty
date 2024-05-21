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
	//��� ���ÿ��� ���� ������ �Űܹ޴´�.
	Types::Decoration* a = PlayerData::player.GetDecoation();
	button::DragDrop userPickDeco[8];  

	//�쵿���� �÷����� ������ ������ �迭.
	button::DragDrop userSet[8];

	//�巡���� �϶� �ٸ���ư�� �ȴ��������� �ϱ�
	button::DragDrop* draggingButton = nullptr;
	
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
			userPickDeco[i] = button::DragDrop((int)(a + i), NULL, 1485, 200 + (i * 150), 100, 100, Empty);
		}
	}
	 
	void Empty()
	{
		
	}
}