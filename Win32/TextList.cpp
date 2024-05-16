#include <fstream>
#include <string>
#include "TextList.h"


TextList* TextList::instance = nullptr;

void TextList::LoadtTextAll()
{
    //스테이지 시나리오 엔딩시나리오 다 추가 
	stage1 = LoadText("resource/object/test.txt");
    stage2 = LoadText("resource/object/test2.txt");
}
wchar_t* TextList::LoadText(const char* _path)
{
	std::wifstream fin;
	fin.open(_path);  
	fin.imbue(std::locale("Korean"));

    int size = 0;
    wchar_t ch;

    // 파일의 끝까지 반복하여 문자 하나씩 읽으면서 크기 계산
    while (fin.get(ch))
    {
        ++size;
    }

    // 읽기가 끝나면 파일을 다시 시작 부분으로 되돌림
    fin.clear();
    fin.seekg(0, std::ios::beg);

    // 문자열을 크기만큼 할당
    wchar_t* Src = new wchar_t[size + 1];

    fin.read(Src, size);
    Src[size] = L'\0'; // 문자열 마지막에 널 종료 문자 추가

    // 파일 닫기
    fin.close();

	return Src;
}