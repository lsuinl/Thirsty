#pragma once
namespace PlaceFood
{
	void PrintScreen();
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