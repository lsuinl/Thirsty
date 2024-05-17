#pragma once
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

		//담은 재료 종류
		Types::Noodle noodle; //면
		Types::Decoration* decoration; //고명(여러개)
		Types::Soup* soup; //육수(여러개)

		public:
			//다음스테이지갈지 재시작할지 정하는 bool값 //이걸로 배드엔딩 새드엔딩 출력도할예정
			//스테이지별 일정 점수이상시 clearStage값 true 해줄 함수구현필요
			bool clearStage = false;
			Player();
			~Player();
			//현재 스테이지 정보 가져오기
			Types::Stage GetStage();
			//점수 초기화(스테이지 변경마다 실행)
			void ResetScore();
			//재료담기 점수 측정 + 재료 담기(재료 일치여부)
			void SetChooseFood(Types::Noodle noodle, Types::Decoration* decoration, Types::Soup* soup);
			//면썰기 점수 측정 (클리어시간, 클리어여부)
			void SetNoodleSlice(int second, bool clear);
			//육수끓이기 점수 측정 (퍼센테이지 일치율)
			void Setstock(int percent);
			//전체점수 가져오기(성공실패여부)
			int GetSumScore();

			Types::Noodle GetNoodle(); //면썰기=면가져오기
			Types::Decoration* GetDecoation(); //고명얹기=고명가져오기
			Types::Soup* GetSoup(); //육수끓이기=육수재료가져오기
	};
	extern Player player;
}

