#pragma once

class TextList
{
private:
	static TextList* instance; // 싱글톤 인스턴스 포인터 잘모름 같이 공부해봐요 

	TextList() {} // 생성자는 비공개로 만듦
	~TextList() {} // 소멸자도 비공개로 만듦
public:
	wchar_t* stage1;
	wchar_t* stage2;
	wchar_t* stage3;

	//해당코드떄문에 생성자를 추가로 생성해도 한개의 생성자로 다 반환됨
	static TextList* GetInstance() {
		if (instance == nullptr) {
			instance = new TextList();
		}
		return instance;
	}
	//txt파일 다 가져올부분 게임메니저의 init에 넣어야함
	void LoadtTextAll(); 
	
	//LoadtTextAll에 들어가는 각 스테이지별 문자열 불러오는곳 path 양식 통일필요 
	wchar_t* LoadText(const char* _path);


};
