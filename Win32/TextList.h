#pragma once

class TextList
{
private:
	static TextList* instance; // �̱��� �ν��Ͻ� ������ �߸� ���� �����غ��� 

	TextList() {} // �����ڴ� ������� ����
	~TextList() {} // �Ҹ��ڵ� ������� ����
public:
	wchar_t* stage1;
	wchar_t* stage2;
	wchar_t* stage3;

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
