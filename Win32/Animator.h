#include "RenderSystem.h"
#include "TimeSystem.h"
#include <string>
#pragma once
class Animator {
	std::string name;
	bool animation = false, loop; //�ִϸ��̼� Ȱ��ȭ ��Ű��
	std::string* imageList; //�ִϸ��̼� ���ҽ�
	int x, y; //��ǥ
	int width, height; //ũ��
	int animationTime = 0, animationLimit = 2000; //����ð�
	bool to;
public:
	~Animator();
	Animator();
	Animator(std::string name,int x, int y, int width, int height, int animationLimit, std::string* imageList, bool loop, bool to);
	//�ִϸ��̼� Ȱ��ȭ
	void SetAnimation(); 
	//�ִϸ��̼� ���º���
	std::string GetAnimationName();
	//�ִϸ��̼� �׸���
	void DrawAnimation(); 
};