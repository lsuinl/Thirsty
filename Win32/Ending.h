#pragma once
#include "GlobalHeader.h"

//������ũ��Ʈ ���� ���� ���� ���ʿ�
void SetEndingStage(int _stagenum, bool _success);

void DrawEndingBack(int _stagenum);

void ChangeEndingScript(float delta);

struct Decoudong
{
	float posX;
	float posY;
	float width = 50;
	float height = 50;

	int deconum;

	void SetDecoudong(float x, float y);

	void SetDeco(int _num);

	void DrawDeco();
	

};