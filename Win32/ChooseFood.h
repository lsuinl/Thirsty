namespace ChooseFood
{
	void ChooseScreen();
	void InitScreen();
	//버튼 클릭 상호작용 체크
	void CheckButton(int dx,int dy);
	void CheckDragButton(int dx,int dy);
	void CheckDropButton(int dx,int dy);
	void CheckCancelButton(int dx, int dy);

	//면, 육수, 고명 선택 화면
	void NoodleScreen();
	void SoupScreen();
	void DecorationScreen();

	//선택창 넘기기
	void LeftPage();
	void RightPage();

	//바구니 위아래로 이동하기
	void UpBasket();
	void DownBasket();

	//선택완료버튼
	void Selected();
	void basketfunction(); 
	void Test();
}
