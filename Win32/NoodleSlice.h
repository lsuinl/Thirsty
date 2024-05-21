#pragma once
#include "GlobalHeader.h"
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

	// �� Ÿ��
	enum NoodleType
	{
		NOODLE1 = 4,
		NOODLE2 = 6,
		NOODLE3 = 8
	};

	// ����Ű ��ų ����
	bool isSuccess;

	// timer
	float resetTimer;
	float playTimer;

	// ���� ����
	void SetGame(int _stage, NoodleType _noodle);

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

	// success
	bool NoodleSuccess();

	// �ִϸ��̼�
	void SliceAni();

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
