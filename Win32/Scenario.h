#pragma once
#include <fstream>
#include <string>
#include <iostream>



struct Figure
{
	float x;
	float y;
	float width;
	float heidht;

	int expression =0; //ǥ�� 0�⺻ 1���ǿ��� 2 ��忣�� 3 �쵿�Դ�ĳ���� ���;
	bool isDraw = true;

	void DrawFigure(int _stagenum);


};
//�ش� 
void SetStoryScript(int _stage);

void SetEndingScript(int _stage, bool success);

//Ű�Է½� ������ ������Ʈ or ���� �� ������Ʈ �� �����ٷ�
void SkipText(float delta);

//�ؽ�Ʈ�� �ѱ��ھ� �����ؼ� ������Ʈ
void UpdateText();

//�ؽ�Ʈ ���
void PrintText();

//�ش� ���丮�� ���������ȣ ��ȯ
int GetMaxPage();

//�ó�����ȭ�� (setscript)�� �ش� �ó��������� �� ���ڿ�����
//  >> �ó����� �޹�� �־����  >> �ó����� �ؽ�Ʈ�ڽ� ���(printtext) >> Ű�Է½� �Ѿ�±�� (skiptext)�߰��� ��浵 �ٲ���߰�
//  >> �ؽ�Ʈ ������ �̴ϰ������� �Ѿ�Բ� ��ư����  