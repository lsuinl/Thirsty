#include "PlayerData.h"

namespace PlayerData {

	Player player = Player();
	
	FoodStage FoodStage1 = {
		Types::Noodle::FLAT,
		{Types::Decoration::SHRIMP,Types::Decoration::FRYGARU,Types::Decoration::FLATAMUK,Types::Decoration::SUNDAEPA},
		{Types::Soup::MAULCHI,Types::Soup::DASIMA},
	};

	FoodStage FoodStage2 = {
	Types::Noodle::SMALL,
	{Types::Decoration::DAEPA,Types::Decoration::YUBU,Types::Decoration::SUKK,Types::Decoration::SICHIME,Types::Decoration::CHOUNGYANGGOCHU,Types::Decoration::SUNKIM},
	{Types::Soup::MU,Types::Soup::MAULCHI,Types::Soup::DASIMA},
	};

	FoodStage FoodStage3 = {
	Types::Noodle::MIDDLE,
	{Types::Decoration::DAEPA,Types::Decoration::SUKK,Types::Decoration::PYOGO,Types::Decoration::FIREMEET,Types::Decoration::BANDALAMUK,Types::Decoration::YUBU,Types::Decoration::GATHOBUSI},
	{Types::Soup::MU,Types::Soup::MAULCHI,Types::Soup::DASIMA,Types::Soup::TZUYU}
	};

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

	void Player::SetStage(Types::Stage st) {
		stage = st;
	}
	void Player::ResetScore()
	{
		noodle = Types::SMALL;
		soup.clear();
		decoration.clear();
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
		case Types::STAGE4:
			stage = Types::STAGE1;
			break;
		default:
			break;
		}
	}


	void Player::SetChooseFood(Types::Noodle noodle, std::vector <Types::Decoration> decoration, std::vector <Types::Soup> soup)
	{
		bool check = true;
		this->noodle = noodle;
		this->decoration = decoration;
		this->soup = soup;
		
		if (stage == 1) 
		{
			if (FoodStage1.noodle != noodle) check = false;
			for (int i = 0; i < FoodStage1.decoration.size(); i++)
			{
				Types::Decoration de = FoodStage1.decoration[i];
				for (int j = 0; j < decoration.size(); j++)
				{
					if (decoration[j] == de) {
						break;
					}
					if (j == decoration.size() - 1) check = false;
				}
			}
			for (int i = 0; i < FoodStage1.soup.size(); i++)
			{
				Types::Soup so = FoodStage1.soup[i];
				for (int j = 0; j < soup.size(); j++)
				{
					if (soup[j] == so) {
						break;
					}
					if (j == soup.size() - 1) check = false;
				}
			}
		}
		else if(stage == 2) 
		{
			if (FoodStage2.noodle != noodle) check = false;
			for (int i = 0; i < FoodStage2.decoration.size(); i++)
			{
				Types::Decoration de = FoodStage2.decoration[i];
				for (int j = 0; j < decoration.size(); j++)
				{
					if (decoration[j] == de) {
						break;
					}
					if (j == decoration.size() - 1) check = false;
				}
			}
			for (int i = 0; i < FoodStage2.soup.size(); i++)
			{
				Types::Soup so = FoodStage2.soup[i];
				for (int j = 0; j < soup.size(); j++)
				{
					if (soup[j] == so) {
						break;
					}
					if (j == soup.size() - 1) check = false;
				}
			}
		}
		else 
		{
			if (FoodStage3.noodle != noodle) check = false;
			for (int i = 0; i < FoodStage3.decoration.size(); i++)
			{
				Types::Decoration de = FoodStage3.decoration[i];
				for (int j = 0; j < decoration.size(); j++)
				{
					if (decoration[j] == de) {
						break;
					}
					if (j == decoration.size() - 1) check = false;
				}
			}
			for (int i = 0; i < FoodStage3.soup.size(); i++)
			{
				Types::Soup so = FoodStage3.soup[i];
				for (int j = 0; j < soup.size(); j++)
				{
					if (soup[j] == so) {
						break;
					}
					if (j == soup.size() - 1) check = false;
				}
			}
		}
		MiniGameClear(check);
	}

	void Player::MiniGameClear(bool clear)
	{
		if (this->stage==1 && stageClear1)
		{
			stageClear1 = clear;
		}
		else if (this->stage == 2&& stageClear2)
		{
			stageClear2 = clear;
		}
		else if(stageClear3)
		{
			stageClear3 = clear;
		}
	}
	Types::Noodle Player::GetNoodle()
	{
		return noodle;
	}
	
	std::vector <Types::Decoration> Player::GetDecoation()
	{
		return decoration;
	}

	std::vector <Types::Soup> Player::GetSoup()
	{
		return soup;
	}

	bool Player::IsGameClear(int _stagenum)
	{
		if (_stagenum == 1)
		{
			return stageClear1;
		}
		if (_stagenum == 2)
		{
			return stageClear2;
		}
		if (_stagenum == 3)
		{
			return stageClear3;
		}

	}

	bool Player::IsTrueEnding()
	{
		return stageClear1 == true && stageClear2 == true && stageClear3 == true;
	}

}