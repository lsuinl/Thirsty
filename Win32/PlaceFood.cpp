#include "InputSystem.h"
#include "ChooseFood.h"
#include "PlaceFood.h"
#include "RenderSystem.h"
#include "Button.h"
#include "LoadData.h"
#include "RenderSystem.h"

namespace PlaceFood
{
	//��� ���ÿ��� ���� ������ �Űܹ޴´�.
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

	
}