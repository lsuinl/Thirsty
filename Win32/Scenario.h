#pragma once
#include <fstream>
#include <string>
#include <iostream>

//�ش� 
void SetScript(int num);

//Ű�Է½� ������ ������Ʈ or ���� �� ������Ʈ �� �����ٷ�
void SkipText(float delta);

//�ؽ�Ʈ�� �ѱ��ھ� �����ؼ� ������Ʈ
void UpdateText();

//�ؽ�Ʈ ���
void PrintText();


//�ó�����ȭ�� (setscript)�� �ش� �ó��������� �� ���ڿ�����
//  >> �ó����� �޹�� �־����  >> �ó����� �ؽ�Ʈ�ڽ� ���(printtext) >> Ű�Է½� �Ѿ�±�� (skiptext)�߰��� ��浵 �ٲ���߰�
//  >> �ؽ�Ʈ ������ �̴ϰ������� �Ѿ�Բ� ��ư����  