#pragma once
namespace Types
{
	//현재 스테이지
	enum Stage
	{
		STAGE1 = 1, //4
		STAGE2 = 2,//8
		STAGE3 = 3//6
	};

	//면 종류
	enum Noodle
	{
		FLAT, //납작면
		MIDDLE, //중면
		SMALL,//소면
	};

	//육수 종류
	enum Soup
	{
		MAULCHI,//멸치
		SALT,//소금
		TZUYU,//쯔유
		GUKSAUCE,//국간장
		DASIMA,//다시마
		MU,//무
		DRYDIPORI,//말린디포리
		DRYMUSHROOMS,//말린버섯
		GATHOBUSI,//가쓰오부시
		SUGAR,//설탕
		HUCHU,//후추
	};

	//고명 종류
	enum Decoration
	{
		DAEPA,//대파
		SICHIME,//시치미
		CHUPA,//쪽파
		PYOGO,//표고
		PANGE,//팽이
		FIREMEET,//직화고기
		YANGPA,//양파
		DOOBU,//두부
		HOBAK,//호박
		YUBU,//유부
		GOCHIAMUK,//꼬치어묵
		SUKK,//쑥갓
		GOCHUGARU,//고추가루
		CHOUNGYANGGOCHU,//청양고추
		SUNKIM,//썬김
		FLATAMUK,//납작어묵
		SHRIMP,//새우튀김
	};


};

