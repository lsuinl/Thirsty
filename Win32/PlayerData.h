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
			//���������������� ��������� ���ϴ� bool�� //�̰ɷ� ��忣�� ���忣�� ��µ��ҿ���
			//���������� ���� �����̻�� clearStage�� true ���� �Լ������ʿ�
			bool clearStage = false;
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

