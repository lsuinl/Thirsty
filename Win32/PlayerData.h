#pragma once
#include <vector>
#include "Types.h"
//�÷��̿� �ʿ��� ������ ���� 

namespace PlayerData {

	struct FoodStage {
		Types::Noodle noodle;
		std::vector<Types::Decoration> decoration;
		std::vector<Types::Soup> soup;
	};
	class Player
	{
		//���� ��������
		bool stageClear1 = true, stageClear2 = true, stageClear3 = true;

		//���� ��� ����
		Types::Noodle noodle = Types::SMALL; //��
		std::vector <Types::Decoration> decoration; //���(������)
		std::vector <Types::Soup> soup; //����(������)

		public:
			Types::Stage stage;
			Player();
			~Player();
			//���� �������� ���� ��������
			Types::Stage GetStage();
			void SetStage(Types::Stage st);
			//���� �ʱ�ȭ(�������� ���渶�� ����)
			void ResetScore();
			//����� ���� ���� + ��� ���(��� ��ġ����)
			void SetChooseFood(Types::Noodle noodle, std::vector <Types::Decoration> decoration, std::vector <Types::Soup> soup);
			//���� ���� (Ŭ����ð�, Ŭ�����)
			void MiniGameClear(bool clear);
			//��ü���� ��������(�������п���)
			int GetSumScore();
			//�������п���
			bool IsGameClear(int _stagenum);
			bool IsTrueEnding();
			
			Types::Noodle GetNoodle(); //����=�鰡������
			std::vector<Types::Decoration> GetDecoation(); //�����=���������
			std::vector <Types::Soup> GetSoup(); //�������̱�=������ᰡ������
	};
	extern Player player;
}

