#pragma once

class TextList
{
private:
	static TextList* instance; // �̱��� �ν��Ͻ� ������ �߸� ���� �����غ��� 

	TextList() {} // �����ڴ� ������� ����
	~TextList() {} // �Ҹ��ڵ� ������� ����
public:
	wchar_t* prologue;
	wchar_t* stage1_story;
	wchar_t* stage1_happy;
	wchar_t* stage1_bad;
	wchar_t* stage2_story;
	wchar_t* stage2_happy;
	wchar_t* stage2_bad;
	wchar_t* stage3_story;
	wchar_t* stage3_happy;
	wchar_t* stage3_bad;

	//�ش��ڵ勚���� �����ڸ� �߰��� �����ص� �Ѱ��� �����ڷ� �� ��ȯ��
	static TextList* GetInstance() {
		if (instance == nullptr) {
			instance = new TextList();
		}
		return instance;
	}
	//txt���� �� �����úκ� ���Ӹ޴����� init�� �־����
	void LoadtTextAll(); 
	
	//LoadtTextAll�� ���� �� ���������� ���ڿ� �ҷ����°� path ��� �����ʿ� 
	wchar_t* LoadText(const char* _path);


};
