#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "TextList.h"
#include "LoadData.h"
float printTime = 10;

TextList* textList1 = TextList::GetInstance();
int curChar;     //�����ؼ� ����� ���ڱ���
int maxChar;    //�� ������ ��                  ///���߿� Ű�Է����� ���� �������� �Ѿ�� �׹����� ����� �缭 ����
int curPage;   // ����ϰ��ִ� ���������� �ѹ�
int maxPage;   // �� �ó������� ������ ������ 

int txtLen;              
wchar_t str2[21][500];    //�����ڷ� �߶� ��ƵѺκ�
wchar_t str3[21][500];    //�ѱ��ھ� ����ҷ��� ī���Һκ�

void SetStoryScript(int _stage)
{     
	wchar_t* token;
	wchar_t* p = nullptr;
	curChar = 0;
	maxChar = 0;
	curPage = 0;
	maxPage = 0;
	memset(str2, 0, sizeof(str2));

	if (_stage == 0)
	{
		txtLen = wcslen(textList1->stage0_prologue) + 1;
		wchar_t* str1 = new wchar_t[txtLen];
		wcscpy_s(str1, txtLen,textList1->stage0_prologue);
		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}

		delete[] str1;
	}
	if (_stage == 1)
	{

		txtLen = wcslen(textList1->stage1_story) + 1;
		wchar_t* str1 = new wchar_t[txtLen];
		wcscpy_s(str1, txtLen, textList1->stage1_story);
		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}
		delete[] str1;
	}
	else if (_stage == 2)
	{
		txtLen = wcslen(textList1->stage2_story) + 1;
		wchar_t* str1 = new wchar_t[txtLen];
		wcscpy_s(str1, txtLen, textList1->stage2_story);
		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}

		delete[] str1;
	}
	else if (_stage == 3)
	{
		txtLen = wcslen(textList1->stage3_story) + 1;
		wchar_t* str1 = new wchar_t[txtLen];
		wcscpy_s(str1, txtLen, textList1->stage3_story);
		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}
		delete[] str1;
	}
}

void SetEndingScript(int _stage, bool success)
{
	wchar_t* token;
	wchar_t* p = nullptr;
	curChar = 0;
	maxChar = 0;
	curPage = 0;
	maxPage = 0;
	memset(str2, 0, sizeof(str2));
	if (_stage == 1)
	{
		if (success)
		{
			txtLen = wcslen(textList1->stage1_happy) + 1;
			wchar_t* str1 = new wchar_t[txtLen];
			wcscpy_s(str1, txtLen, textList1->stage1_happy);
			token = wcstok_s(str1, L"&", &p);
			while (token != NULL)
			{
				wcscpy_s(str2[maxPage], token);
				token = wcstok_s(NULL, L"&", &p);
				maxPage++;
			}
			delete[] str1;
		}
		else
		{
			txtLen = wcslen(textList1->stage1_bad) + 1;
			wchar_t* str1 = new wchar_t[txtLen];
			wcscpy_s(str1, txtLen, textList1->stage1_bad);
			token = wcstok_s(str1, L"&", &p);
			while (token != NULL)
			{
				wcscpy_s(str2[maxPage], token);
				token = wcstok_s(NULL, L"&", &p);
				maxPage++;
			}
			delete[] str1;
		}
	}
	else if (_stage == 2)
	{
		if (success)
		{
			txtLen = wcslen(textList1->stage2_happy) + 1;
			wchar_t* str1 = new wchar_t[txtLen];
			wcscpy_s(str1, txtLen, textList1->stage2_happy);
			token = wcstok_s(str1, L"&", &p);
			while (token != NULL)
			{
				wcscpy_s(str2[maxPage], token);
				token = wcstok_s(NULL, L"&", &p);
				maxPage++;
			}
			delete[] str1;
		}
		else
		{
			txtLen = wcslen(textList1->stage2_bad) + 1;
			wchar_t* str1 = new wchar_t[txtLen];
			wcscpy_s(str1, txtLen, textList1->stage2_bad);
			token = wcstok_s(str1, L"&", &p);
			while (token != NULL)
			{
				wcscpy_s(str2[maxPage], token);
				token = wcstok_s(NULL, L"&", &p);
				maxPage++;
			}
			delete[] str1;
		}
	}
	else if (_stage == 3)
	{
		if (success)
		{
			txtLen = wcslen(textList1->stage3_happy) + 1;
			wchar_t* str1 = new wchar_t[txtLen];
			wcscpy_s(str1, txtLen, textList1->stage3_happy);
			token = wcstok_s(str1, L"&", &p);
			while (token != NULL)
			{
				wcscpy_s(str2[maxPage], token);
				token = wcstok_s(NULL, L"&", &p);
				maxPage++;
			}
			delete[] str1;
		}
		else
		{
			txtLen = wcslen(textList1->stage3_bad) + 1;
			wchar_t* str1 = new wchar_t[txtLen];
			wcscpy_s(str1, txtLen, textList1->stage3_bad);
			token = wcstok_s(str1, L"&", &p);
			while (token != NULL)
			{
				wcscpy_s(str2[maxPage], token);
				token = wcstok_s(NULL, L"&", &p);
				maxPage++;
			}
			delete[] str1;
		}
	}
}

void SetTrueEndingScript(bool success)
{
	wchar_t* token;
	wchar_t* p = nullptr;
	curChar = 0;
	maxChar = 0;
	curPage = 0;
	maxPage = 0;
	memset(str2, 0, sizeof(str2));

	if (success)
	{
		txtLen = wcslen(textList1->ture_ending) + 1;
		wchar_t* str1 = new wchar_t[txtLen];
		wcscpy_s(str1, txtLen, textList1->ture_ending);
		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}

		delete[] str1;
	}
	else
	{

		txtLen = wcslen(textList1->ending) + 1;
		wchar_t* str1 = new wchar_t[txtLen];
		wcscpy_s(str1, txtLen, textList1->ending);
		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[maxPage], token);
			token = wcstok_s(NULL, L"&", &p);
			maxPage++;
		}
		delete[] str1;
	}
}

int GetCurPage()
{
	return curPage;
}
int GetMaxPage()
{
	return maxPage;
}
void SkipText(float delta)
{
	static ULONGLONG elapsedTime;
	elapsedTime += delta;
	if(input::IsKeyUp(32))
	{
		if (curChar != maxChar)
		{
			curChar = maxChar;
		}

	}
	if (elapsedTime >= printTime)
	{
		if (curChar < maxChar)                 
		{
			curChar++;
			elapsedTime = 0;
		}
	}
	if (input::IsKeyUp(13))
	{
		if (curChar == maxChar)
		{
				curPage++;
				curChar = 0;
		}
	}
}

void UpdateText()
{
	maxChar = wcslen(str2[curPage]);
	wcsncpy_s(str3[curPage], str2[curPage], curChar + 7);
}
void PrintText()
{	
	render::DrawTextF(340, 820, str3[curPage], RGB(0, 0, 255), 50);
}
void PrintTextEnd()
{
	render::DrawTextF(400, 400, str3[curPage], RGB(0, 0, 255), 50);
}

void Figure::DrawFigure(int _stagenum)
{
	if (isDraw == true)
	{
		if (_stagenum == 1)
		{
			if (expression == 0)
			{
				LoadData::imageManager->DrawPngImage("���̱⺻", 700, 436, 450, 450, 1.0f);
			}
			else if(expression == 1)
			{
				LoadData::imageManager->DrawPngImage("���̿���", 700, 436, 450, 450, 1.0f);
			}
			else if(expression == 2)
			{
				LoadData::imageManager->DrawPngImage("����ȭ��", 700, 436, 450, 450, 1.0f);
			}
			else
			{
				LoadData::imageManager->DrawPngImage("���̿쵿", 700, 436, 450, 450, 1.0f);
			}
		}
		else if (_stagenum == 2)
		{
			if (expression == 0) 
			{
				LoadData::imageManager->DrawPngImage("���⺻", 700, 286, 350, 600, 1.0f);
			}
			else if (expression == 1) 
			{
				LoadData::imageManager->DrawPngImage("������", 700, 286, 350, 600, 1.0f);
			}
			else if (expression == 2) 
			{
				LoadData::imageManager->DrawPngImage("���ȭ��", 700, 286, 350, 600, 1.0f);
			}
			else
			{
				LoadData::imageManager->DrawPngImage("���쵿", 700, 286, 350, 600, 1.0f);
			}
		}
		else
		{
			if (expression == 0) 
			{
				LoadData::imageManager->DrawPngImage("�߳�⺻", 700, 286, 350, 600, 1.0f);
			}
			else if (expression == 1)
			{
				LoadData::imageManager->DrawPngImage("�߳����", 700, 286, 350, 600, 1.0f);
			}
			else if (expression == 2)
			{
				LoadData::imageManager->DrawPngImage("�߳�ȭ��", 700, 286, 350, 600, 1.0f);
			}
			else
			{
				LoadData::imageManager->DrawPngImage("�߳�쵿", 700, 286, 350, 600, 1.0f);
			}
		}
	}
}