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

	int expression = 0; //ǥ�� 0�⺻ 1���ǿ��� 2 ��忣�� 3 �쵿�Դ�ĳ���� ��� 4�߳����;
	bool isDraw = true;

	void DrawFigure(int _stagenum);


};
//�ش� 
void SetStoryScript(int _stage);

void SetEndingScript(int _stage, bool success);

void SetTrueEndingScript(bool success);

//Ű�Է½� ������ ������Ʈ or ���� �� ������Ʈ �� �����ٷ�
void SkipText(float delta);

//�ؽ�Ʈ�� �ѱ��ھ� �����ؼ� ������Ʈ
void UpdateText();

//�ؽ�Ʈ ���
void PrintText(float delta);

void PrintTextEnd();

//�ش� ���丮�� ���������ȣ ��ȯ
int GetMaxPage();

int GetCurPage();

//�ó�����ȭ�� (setscript)�� �ش� �ó��������� �� ���ڿ�����
//  >> �ó����� �޹�� �־����  >> �ó����� �ؽ�Ʈ�ڽ� ���(printtext) >> Ű�Է½� �Ѿ�±�� (skiptext)�߰��� ��浵 �ٲ���߰�
//  >> �ؽ�Ʈ ������ �̴ϰ������� �Ѿ�Բ� ��ư����  