#pragma once
#include <vector>
#include "Types.h"
//플레이에 필요한 정보를 관리 

namespace PlayerData {

	struct FoodStage {
		Types::Noodle noodle;
		std::vector<Types::Decoration> decoration;
		std::vector<Types::Soup> soup;
	};
	class Player
	{
		//현재 스테이지
		bool stageClear1 = true, stageClear2 = true, stageClear3 = true;

		//담은 재료 종류
		Types::Noodle noodle = Types::SMALL; //면
		std::vector <Types::Decoration> decoration; //고명(여러개)
		std::vector <Types::Soup> soup; //육수(여러개)

		public:
			Types::Stage stage;
			Player();
			~Player();
			//현재 스테이지 정보 가져오기
			Types::Stage GetStage();
			void SetStage(Types::Stage st);
			//점수 초기화(스테이지 변경마다 실행)
			void ResetScore();
			//재료담기 점수 측정 + 재료 담기(재료 일치여부)
			void SetChooseFood(Types::Noodle noodle, std::vector <Types::Decoration> decoration, std::vector <Types::Soup> soup);
			//점수 측정 (클리어시간, 클리어여부)
			void MiniGameClear(bool clear);
			//전체점수 가져오기(성공실패여부)
			int GetSumScore();
			//성공실패여부
			bool IsGameClear(int _stagenum);
			bool IsTrueEnding();
			
			Types::Noodle GetNoodle(); //면썰기=면가져오기
			std::vector<Types::Decoration> GetDecoation(); //고명얹기=고명가져오기
			std::vector <Types::Soup> GetSoup(); //육수끓이기=육수재료가져오기
	};
	extern Player player;
}

