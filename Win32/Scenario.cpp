#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "TextList.h"

float printTime;


wchar_t str1[500]; //���Ͽ��� �ٹ޾ƿúκ�
wchar_t* p = nullptr;
wchar_t* token;
int filecount = 0;
TextList* textList1 = TextList::GetInstance();
int curChar = 0;     //�����ؼ� ����� ���ڱ���
int maxChar = 0; //�� ������ ��                  ///���߿� Ű�Է����� ���� �������� �Ѿ�� �׹����� ����� �缭 ����
int curPage = 0;   // ����ϰ��ִ� ���������� �ѹ�
int maxPage = 0;   // �� �ó������� ������ ������ �� �ó����� ������������ ���ؼ� �ֱ��ʿ�

wchar_t str2[10][500];    // ���ϴ� �޾ƿ°� �����ڷ� �߶� ��ƵѺκ�
wchar_t str3[10][500];    //�ѱ��ھ� ����ҷ��� ī���Һκ�

int i = 0;
void SetScript(int num)
{
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
		/*token = wcstok_s(textList1->stage2, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[i], token);
			token = wcstok_s(NULL, L"&", &p);
			i++;
		}*/

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
		printTime = 1000;
	}
	//�ش������� �� �߰����κ�
	if (input::IsKeyUp(9))
	{
		curChar = maxChar;                     
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
		if (curPage < maxPage - 1) // �߰��ʿ� 5�� maxPage-1 ������ �����ϰ�� Ű�Է½� �̴ϰ������� ���ų� ��ư������� �̴ϰ�������
		{
			curPage++;
			curChar = 0;
		}
	}
	//���� 13  //����Ʈ 16
}
void UpdateText()
{
	maxChar = wcslen(str2[curPage]);
	wcsncpy_s(str3[curPage], str2[curPage], curChar);
}
void PrintText()
{	
	render::DrawTextF(100, 100, str3[curPage], RGB(0, 0, 255), 50);

	
}