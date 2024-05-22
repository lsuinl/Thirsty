#pragma once
namespace Types
{
	//현재 스테이지
	enum Stage
	{
		STAGE1 = 1, //4
		STAGE2 = 2,//8
		STAGE3 = 3,//6
		STAGE4 = 4,
	};

	//면 종류
	enum Noodle
	{
		FLAT = 0, //납작면
		MIDDLE = 1, //중면
		SMALL = 2,//소면
	};

	//육수 종류
	enum Soup
	{
		MAULCHI = 3,//멸치
		SALT = 4,//소금
		TZUYU = 5,//쯔유
		GUKSAUCE = 6,//국간장
		DASIMA = 7,//다시마
		MU = 8,//무
		DRYDIPORI = 9,//말린디포리
		DRYMUSHROOMS = 10,//말린버섯
		GATHOBUSI = 11,//가쓰오부시
		SUGAR = 12,//설탕
		HUCHU = 13,//후추
	};

	//고명 종류
	enum Decoration
	{
		DAEPA = 14,//대파
		SICHIME = 15,//시치미
		CHUPA = 16,//쪽파
		PYOGO = 17,//표고
		PANGE = 18,//팽이
		FIREMEET = 19,//직화고기
		YANGPA = 20,//양파
		DOOBU = 21,//두부
		HOBAK = 22,//호박
		YUBU = 23,//유부
		GOCHIAMUK = 24,//꼬치어묵
		SUKK = 25,//쑥갓
		GOCHUGARU = 26,//고추가루
		CHOUNGYANGGOCHU = 27,//청양고추
		SUNKIM = 28,//썬김
		FLATAMUK = 29,//납작어묵
		SHRIMP = 30,//새우튀김
	};
	enum Basket
	{
		BASKET = 31,//바구니
	};

};

