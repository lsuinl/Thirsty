#include "MiniGame1.h"

// ���� ����
int MiniGame1::SetGame(StageNoodle _stage, NoodleType _noodle)
{
	// ���� Ƚ��
	Cnt = 0;
	stage = _stage;
	noodle = _noodle;

	arrSize = (int)stage * (int)noodle;

	CreatArrowArr();
}

// ���ӷ���
int MiniGame1::UpdateGame(ArrowType keyCode)
{
	CompareArrow(keyCode);
}

// �迭 ����
void MiniGame1::ReleaseGame()
{
	delete[] arrowArr;
}

// ����Ű �迭 ����
void MiniGame1::CreatArrowArr()
{
	// �迭 ����
	// (��������.. 38 = ��, 37 = ��, 40 = ��, 39 = ��)
	arrowArr = new Arrow[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		(arrowArr + i)->arrowType = rand() % 4 + 37;
		(arrowArr + i)->isTrue = false;
	}
}

// ����Ű �°� �ƴ��� �˻�
void MiniGame1::CompareArrow(ArrowType keyCode)
{
	if (arrowArr[Cnt].arrowType == (int)keyCode)
	{
		Cnt++;
	}
	else
	{
		Cnt = 0;
	}
}

