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
		bool isClearStage = false;

		bool isTrueEnding = false;  // 1 , 2, 3 �������� ���� �� �ʿ� 

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
			bool IsGameClear();

			//Ʈ�翣�� Ȯ��
			bool IsTrueEnding();

			Types::Noodle GetNoodle(); //����=�鰡������
			Types::Decoration* GetDecoation(); //�����=���������
			Types::Soup* GetSoup(); //�������̱�=������ᰡ������
	};
	extern Player player;
}

