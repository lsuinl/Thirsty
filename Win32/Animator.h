#pragma once
#include "GlobalHeader.h"
class Animator {
	std::string name;
	bool animation = false, loop; //�ִϸ��̼� Ȱ��ȭ ��Ű��
	std::wstring* imageList; //�ִϸ��̼� ���ҽ�
	int x, y; //��ǥ
	int width, height; //ũ��
	int animationTime = 0, animationLimit = 2000; //����ð�
	bool to;
	int imagelength;
public:
	~Animator();
	Animator();
	Animator(std::string name,int x, int y, int width, int height, int animationLimit,  std::wstring* imageList, bool loop, bool to, int imagelength);
	//�ִϸ��̼� Ȱ��ȭ
	void SetAnimation(); 
	//�ִϸ��̼� ���º���
	bool GetAnimationCheck();
	//�ִϸ��̼� �׸���
	void DrawAnimation(); 
};