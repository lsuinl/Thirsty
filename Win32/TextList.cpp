#include <fstream>
#include <string>
#include "TextList.h"


TextList* TextList::instance = nullptr;

void TextList::LoadtTextAll()
{
	stage1 = LoadText("resource/object/test.txt");
}
wchar_t* TextList::LoadText(const char* _path)
{
	std::wifstream fin;
	fin.open(_path);  //const char로 경로 앞부분 설정해서 합치는 작업필요
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

    // 문자열을 저장할 버퍼 할당
    wchar_t* Src = new wchar_t[size + 1];

    // 파일 내용을 읽어와서 버퍼에 저장
    fin.read(Src, size);
    Src[size] = L'\0'; // 문자열 마지막에 널 종료 문자 추가

    // 파일 닫기
    fin.close();

	return Src;
}