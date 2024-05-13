#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <string>

#include "InputSystem.h"
#include "RenderSystem.h"
#include "TimeSystem.h"


class NoodleSlice
{
public:

	// ����Ű Ÿ��
	enum ArrowType
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

	// Arrow ����ü �迭 ����
	Arrow** arrowArr;

	// ���������� ���� �� ����
	enum StageNoodle
	{
		STAGE1 = 4,
		STAGE2 = 8,
		STAGE3 = 6
	};

	// �� Ÿ��
	enum NoodleType
	{
		NOODLE1 = 4,
		NOODLE2 = 6,
		NOODLE3 = 8
	};

	// ���� ����
	bool isSuccess;

	// timer
	float resetTimer;
	float playTimer;

	// ���� ����
	void SetGame(StageNoodle _stage, NoodleType _noodle);

	// ���ӷ���
	void UpdateGame();
	// �迭 ����
	void ReleaseGame();

	// ����Ű �Է�
	void InputArrow();

	// cnt ��ȯ
	int GetCnt();

	// setcnt ��ȯ
	int GetSetCnt();

	// arrsize ��ȯ
	int GetArrSize();

	// render
	void NoodleSliceScreen();

private:

	// �迭 ������
	int arrSize;

	// ����Ű ���� Ƚ��
	int cnt;

	// ��Ʈ Ƚ��
	int setCnt;

	// �÷��̾� ����
	int playerScore;

	// �ʱ�ȭ �Ǵ�
	bool isReset;

	// �鰳�� ����
	int stage;

	// ����Ÿ�� ����
	int noodle;

	// ����Ű �迭 ����
	void CreatArrowArr();

	// ����Ű �°� �ƴ��� �˻�
	void CompareArrow(ArrowType keyCode);
};
