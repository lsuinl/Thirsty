#pragma once
#include "GlobalHeader.h"
#include "PlayerData.h"
//������ũ��Ʈ ���� ���� ���� ���ʿ�
void SetEndingStage(int _stagenum, bool _success,int* _decolist);

void DrawEndingBack(int _stagenum,float delta);

void ChangeEndingScript(float delta);

struct Decoudong
{
	float posX;
	float posY;
	float width = 50;
	float height = 50;

	int deconum;

	int udongnum;

	void SetDecoudong(float x, float y);

	void SetDeco(int _num);

	void DrawDeco();

	void Setudong(float x, float y, int _num);

	void Drawudong();
	
};

