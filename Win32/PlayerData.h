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

			Types::Noodle GetNoodle(); //����=�鰡������
			Types::Decoration* GetDecoation(); //�����=���������
			Types::Soup* GetSoup(); //�������̱�=������ᰡ������
	};
	extern Player player;
}

