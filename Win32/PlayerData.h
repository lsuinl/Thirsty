#pragma once
#include <vector>
#include "Types.h"
//플레이에 필요한 정보를 관리 

namespace PlayerData {
	class Player
	{
		//현재 스테이지
		Types::Stage stage;
		//재료담기 점수
		int chooseFood;
		//면썰기 점수
		int noodleSlice;
		//끓이기 점수
		int stock;
		//종합 점수
		int sum;

	 //게임클리어시 다음스테이지로 념겨줄지 확인할거
		bool isClear1Stage = true;

		bool isClear2Stage = true;

		bool isClear3Stage = true;


		//담은 재료 종류
		Types::Noodle noodle; //면
		std::vector <Types::Decoration> decoration; //고명(여러개)
		std::vector <Types::Soup> soup; //육수(여러개)

		public:
		
			Player();
			~Player();
			//현재 스테이지 정보 가져오기
			Types::Stage GetStage();
			//점수 초기화(스테이지 변경마다 실행)
			void ResetScore();
			//재료담기 점수 측정 + 재료 담기(재료 일치여부)
			void SetChooseFood(Types::Noodle noodle, std::vector <Types::Decoration> decoration, std::vector <Types::Soup> soup);
			//면썰기 점수 측정 (클리어시간, 클리어여부)
			void SetNoodleSlice(int second, bool clear);
			//육수끓이기 점수 측정 (퍼센테이지 일치율)
			void Setstock(int percent);
			//전체점수 가져오기(성공실패여부)
			int GetSumScore();

			//성공실패여부
			void GameClear(int _stagenum, bool success);

			bool IsGameClear(int _stagenum);
			//트루엔딩 확인
			bool IsTrueEnding();


			Types::Noodle GetNoodle(); //면썰기=면가져오기
			std::vector<Types::Decoration> GetDecoation(); //고명얹기=고명가져오기
			std::vector <Types::Soup> GetSoup(); //육수끓이기=육수재료가져오기
	};
	extern Player player;
}

