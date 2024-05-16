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
		default:
			break;
		}
	}

	void Player::SetChooseFood(Types::Noodle noodle, Types::Decoration* decoration,Types::Soup* soup) 
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
}