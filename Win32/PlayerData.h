#pragma once
#include "Types.h"
//�÷��̿� �ʿ��� ������ ���� 

namespace PlayerData {
	class Player
	{
		//���� ��������
		Types::Stage stage;
		//����� ����
		int chooseFood;
		//���� ����
		int noodleSlice;
		//���̱� ����
		int stock;
		//���� ����
		int sum;

		//����Ŭ����� �������������� ������� Ȯ���Ұ�
		bool isClear1Stage = true;

		bool isClear2Stage = true;

		bool isClear3Stage = true;


		//���� ��� ����
		Types::Noodle noodle; //��
		Types::Decoration* decoration; //���(������)
		Types::Soup* soup; //����(������)

	public:

		Player();
		~Player();
		//���� �������� ���� ��������
		Types::Stage GetStage();
		//���� �ʱ�ȭ(�������� ���渶�� ����)
		void ResetScore();
		//����� ���� ���� + ��� ���(��� ��ġ����)
		void SetChooseFood(Types::Noodle noodle, Types::Decoration* decoration, Types::Soup* soup);
		//���� ���� ���� (Ŭ����ð�, Ŭ�����)
		void SetNoodleSlice(int second, bool clear);
		//�������̱� ���� ���� (�ۼ������� ��ġ��)
		void Setstock(int percent);
		//��ü���� ��������(�������п���)
		int GetSumScore();

		//�������п���
		void GameClear(int _stagenum, bool success);

		bool IsGameClear(int _stagenum);
		//Ʈ�翣�� Ȯ��
		bool IsTrueEnding();

		Types::Noodle GetNoodle(); //����=�鰡������
		Types::Decoration* GetDecoation(); //�����=���������
		Types::Soup* GetSoup(); //�������̱�=������ᰡ������
	};
	extern Player player;
}

