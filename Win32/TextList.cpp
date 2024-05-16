#include <fstream>
#include <string>
#include "TextList.h"


TextList* TextList::instance = nullptr;

void TextList::LoadtTextAll()
{
    //�������� �ó����� �����ó����� �� �߰� 
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

    // ������ ������ �ݺ��Ͽ� ���� �ϳ��� �����鼭 ũ�� ���
    while (fin.get(ch))
    {
        ++size;
    }

    // �бⰡ ������ ������ �ٽ� ���� �κ����� �ǵ���
    fin.clear();
    fin.seekg(0, std::ios::beg);

    // ���ڿ��� ũ�⸸ŭ �Ҵ�
    wchar_t* Src = new wchar_t[size + 1];

    fin.read(Src, size);
    Src[size] = L'\0'; // ���ڿ� �������� �� ���� ���� �߰�

    // ���� �ݱ�
    fin.close();

	return Src;
}