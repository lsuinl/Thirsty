#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "TextList.h"

float printTime;

wchar_t* token;
TextList* textList1 = TextList::GetInstance();
int curChar = 0;     //�����ؼ� ����� ���ڱ���
int maxChar = 0; //�� ������ ��                  ///���߿� Ű�Է����� ���� �������� �Ѿ�� �׹����� ����� �缭 ����
int curPage = 0;   // ����ϰ��ִ� ���������� �ѹ�
int maxPage = 0;   // �� �ó������� ������ ������ �� �ó����� ������������ ���ؼ� �ֱ��ʿ�

wchar_t str2[10][500];    // ���ϴ� �޾ƿ°� �����ڷ� �߶� ��ƵѺκ�
wchar_t str3[10][500];    //�ѱ��ھ� ����ҷ��� ī���Һκ�


void SetScript(int num)
{
	wchar_t* p = nullptr;
	curChar = 0;
	maxChar = 0;
	curPage = 0;
	maxPage = 0;
	memset(str2, 0, sizeof(str2));
	//if (num == 0)
	//{
	//	token = wcstok_s(textList1->prologue, L"&", &p);
	//	while (token != NULL)
	//	{
	//		wcscpy_s(str2[maxPage], token);
	//		token = wcstok_s(NULL, L"&", &p);
	//		maxPage++;
	//	}
	//}
	if (num == 1)
	{
		token = wcstok_s(textList1->stage1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}
	}
	else if (num == 2)
	{
		//num�� �������� ��ȣ��� �����ϰ� ���������� �����ʿ�
		token = wcstok_s(textList1->stage2, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}

	}

}

void SkipText(float delta)
{
	static ULONGLONG elapsedTime;
	elapsedTime += delta;
	//��Ʈ��Ű������ ������������ == ������ �����ϳ��������ؿͼ� �ѱ��ھ���µǴ°�ó������
	if (input::IsKey(17))
	{
		printTime = 10;
	}
	else
	{
		printTime = 100;
	}
	//�ش������� �� �߰����κ�
	if(input::IsKeyUp(9))
	{
		if (curChar != maxChar)
		{
			curChar = maxChar;
		}
		//else
		//{
		//	if (curPage < maxPage - 1) // �߰��ʿ� �����ϰ�� Ű�Է½� �̴ϰ������� ���ų� ��ư������� �̴ϰ�������
		//	{                          // ��ư�Ѱ��� ��������� �����ȯ�� �����ؼ� ����������  bool������ max������� ��������������
		//		curPage++;             //Ȯ���ؼ� �ؾ��ҵ�? ������������ ���콺Ŭ���̾���?
		//		curChar = 0;
		//	}
		//}
	}
	if (elapsedTime >= printTime)
	{
		if (curChar < maxChar)                 
		{
			curChar++;
			elapsedTime = 0;
		}
	}
	//�� ������� ������������ �ѱ�κ�
	if (input::IsKeyUp(16))
	{
		if (curPage < maxPage - 1) // �߰��ʿ� �����ϰ�� Ű�Է½� �̴ϰ������� ���ų� ��ư������� �̴ϰ�������
		{
			curPage++;
			curChar = 0;
		}
	}
	//�� 9   //���� 13  //����Ʈ 16
}

void UpdateText()
{
	
	maxChar = wcslen(str2[curPage]);
	wcsncpy_s(str3[curPage], str2[curPage], curChar);
	// if(curPage == maxChar) �ƽ��� ��ưŬ�� �����ϰԲ�
}
void PrintText()
{	
	render::DrawTextF(100, 100, str3[curPage], RGB(0, 0, 255), 50);

	
}