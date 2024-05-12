#pragma once
#include <stdlib.h>
#include <time.h>

class MiniGame1
{
public:

	// ����Ű Ÿ��
	enum class ArrowType
	{
		UPARROW = 38,
		LEFTARROW = 37,
		DOWNARROW = 40,
		RIGHTARROW = 39
	};

	// ���� ����Ű ���� ����ü
	struct Arrow
	{
		int arrowType;
		bool isTrue;
	};

	// ���������� ���� �� ����
	enum class StageNoodle
	{
		STAGE1 = 4,
		STAGE2 = 6,
		STAGE3 = 8
	};

	// �� Ÿ��
	enum class NoodleType
	{
		NOODLE1 = 1,
		NOODLE2 = 2,
		NOODLE3 = 4
	};

	// ���� ����
	int SetGame(StageNoodle _stage, NoodleType _noodle);

	// ���ӷ���
	int UpdateGame(ArrowType keyCode);

	// �迭 ����
	void ReleaseGame();

private:

	// Arrow ����ü �迭 ����
	Arrow* arrowArr;

	// �迭 ������
	int arrSize = 0;

	// ����Ű ���� Ƚ��
	int Cnt = 0;

	// �鰳�� ����
	StageNoodle stage;

	// ����Ÿ�� ����
	NoodleType noodle;

	// ����Ű �迭 ����
	void CreatArrowArr();

	// ����Ű �°� �ƴ��� �˻�
	void CompareArrow(ArrowType keyCode);

};
