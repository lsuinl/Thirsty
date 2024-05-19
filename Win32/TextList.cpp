#include <fstream>
#include <string>
#include "TextList.h"


TextList* TextList::instance = nullptr;

void TextList::LoadtTextAll()
{
    //�������� �ó����� �����ó����� �� �߰� 
    stage0_prologue = LoadText("resource /object /prologue.txt");
	stage1_story = LoadText("resource/object/Stage1_story.txt");
    stage1_happy = LoadText("resource/object/Stage1_happy.txt");
    stage1_bad = LoadText("resource/object/Stage1_bad.txt");
    stage2_story = LoadText("resource/object/Stage2_story.txt");
    stage2_happy = LoadText("resource/object/Stage2_happy.txt");
    stage2_bad = LoadText("resource/object/Stage2_bad.txt");
    stage3_story = LoadText("resource/object/Stage3_story.txt");
    stage3_happy = LoadText("resource/object/Stage3_happy.txt");
    stage3_bad = LoadText("resource/object/Stage3_bad.txt");
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