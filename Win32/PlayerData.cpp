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
		//다음 스테이지로 넘어갑니다.
		switch (stage)
		{
		case Types::STAGE1:
			stage = Types::STAGE2;
			break;
		case Types::STAGE2:
			stage = Types::STAGE3;
			break;
		case Types::STAGE3:       //일단 스테이지3끝나면 1로보내는 무한순환 타이틀로 보내야함 
			stage = Types::STAGE4;
			break;
		case Types::STAGE4:         //최종엔딩 기본엔딩 //진엔딩 분기있음
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
		//개수만큼 반복문 돌리며 일치율 확인하고 맞으면 +
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