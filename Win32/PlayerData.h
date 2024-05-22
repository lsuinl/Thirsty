#pragma once
#include <vector>
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

		//���� ��� ����
		Types::Noodle noodle; //��
		std::vector <Types::Decoration> decoration; //���(������)
		std::vector <Types::Soup> soup; //����(������)

		public:
		
			Player();
			~Player();
			//���� �������� ���� ��������
			Types::Stage GetStage();
			//���� �ʱ�ȭ(�������� ���渶�� ����)
			void ResetScore();
			//����� ���� ���� + ��� ���(��� ��ġ����)
			void SetChooseFood(Types::Noodle noodle, std::vector <Types::Decoration> decoration, std::vector <Types::Soup> soup);
			//���� ���� ���� (Ŭ����ð�, Ŭ�����)
			void SetNoodleSlice(int second, bool clear);
			//�������̱� ���� ���� (�ۼ������� ��ġ��)
			void Setstock(int percent);
			//��ü���� ��������(�������п���)
			int GetSumScore();

			//�������п���
			bool IsGameClear();

			Types::Noodle GetNoodle(); //����=�鰡������
			std::vector<Types::Decoration> GetDecoation(); //�����=���������
			std::vector <Types::Soup> GetSoup(); //�������̱�=������ᰡ������
	};
	extern Player player;
}

