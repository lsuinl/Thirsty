#include "PlayerData.h"

namespace PlayerData {
	Player player = Player();
	Player::Player()
	{

		stage = Types::STAGE1;

	}

	Player::~Player()
	{
	}

	Types::Stage Player::GetStage()
	{
		return stage;
	}

	void Player::ResetScore()
	{
		sum = 0;
		stock = 0;
		noodleSlice = 0;
		chooseFood = 0;
		//���� ���������� �Ѿ�ϴ�.
		switch (stage)
		{
		case Types::STAGE1:
			stage = Types::STAGE2;
			break;
		case Types::STAGE2:
			stage = Types::STAGE3;
			break;
		case Types::STAGE3:       //�ϴ� ��������3������ 1�κ����� ���Ѽ�ȯ Ÿ��Ʋ�� �������� 
			stage = Types::STAGE4;
			break;
		case Types::STAGE4:         //�������� �⺻���� //������ �б�����
			stage = Types::STAGE1;
			break;
		default:
			break;
		}
	}


	void Player::SetChooseFood(Types::Noodle noodle, Types::Decoration* decoration, Types::Soup* soup)
	{
		this->noodle = noodle;
		this->decoration = decoration;
		this->soup = soup;
		//������ŭ �ݺ��� ������ ��ġ�� Ȯ���ϰ� ������ +
		chooseFood += 1;
	}

	void Player::SetNoodleSlice(int second, bool clear)
	{
		noodleSlice = clear - second;
	}

	void Player::Setstock(int percent)
	{
		stock = percent;
	}

	int Player::GetSumScore()
	{
		return sum;
	}
	Types::Noodle Player::GetNoodle()
	{
		return noodle;
	}

	Types::Decoration* Player::GetDecoation()
	{
		return decoration;
	}

	Types::Soup* Player::GetSoup()
	{
		return soup;
	}

	void Player::GameClear(int _stagenum, bool success)
	{
		if (_stagenum == 1&& isClear1Stage)
		{
			isClear1Stage = success;
		}
		else if (_stagenum == 2&& isClear2Stage)
		{
			isClear2Stage = success;
		}
		else if (_stagenum == 3&& isClear3Stage)
		{
			isClear3Stage = success;
		}
	}

	bool Player::IsGameClear(int _stagenum)
	{
		if (_stagenum == 1)
		{
			return isClear1Stage;
		}
		if (_stagenum == 2)
		{
			return isClear2Stage;
		}
		if (_stagenum == 3)
		{
			return isClear3Stage;
		}
	}
	bool Player::IsTrueEnding()
	{
		return isClear1Stage == true && isClear2Stage == true && isClear3Stage == true;
	}
}