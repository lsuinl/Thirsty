#pragma once
namespace PlaceFood
{
	//배경 이미지 그리기
	void PrintScreen();
	//값 받아오기
	void InitScreen();

	void CheckButton(int dx, int dy);
	void CheckDragButton(int dx, int dy);
	void CheckDropButton(int dx, int dy);

	void PlaceFoodScreen();

	void Test();

	void UpBasket();
	void DownBasket();
	void Selected();
	void Empty();
 }