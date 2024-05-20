#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "TextList.h"

float printTime;

TextList* textList1 = TextList::GetInstance();
int curChar;     //�����ؼ� ����� ���ڱ���
int maxChar;    //�� ������ ��                  ///���߿� Ű�Է����� ���� �������� �Ѿ�� �׹����� ����� �缭 ����
int curPage;   // ����ϰ��ִ� ���������� �ѹ�
int maxPage;   // �� �ó������� ������ ������ 

int txtLen;              
wchar_t str2[20][500];    //�����ڷ� �߶� ��ƵѺκ�
wchar_t str3[20][500];    //�ѱ��ھ� ����ҷ��� ī���Һκ�

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
		if (success)//?�쏙?�占?�옙?�쏙?�占?�옙
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
		if (success)//?�쏙?�占?�옙?�쏙?�占?�옙
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

int GetMaxPage()
{
	return maxPage;
}
void SkipText(float delta)
{
	static ULONGLONG elapsedTime;
	elapsedTime += delta;
	//?�쏙?�트?�쏙?�키?�쏙?�占?�옙?�쏙???�쏙?�占?�옙?�쏙?�占?�옙?�쏙?�占?�옙 == ?�쏙?�占?�옙?�쏙???�쏙?�占?�옙?�싹?�옙?�쏙?�占?�옙?�쏙?�占?��??�옙 ?�싼깍옙?�쌘?�옙?�쏙?�쨉?�째?�시?�옙?�쏙?�占?�옙??
	if (input::IsKey(17))
	{
		printTime = 10;
	}
	else
	{
		printTime = 100;
	}
	//?�쌔?�옙?�쏙?�占?�옙?�쏙???�쏙???�쌩곤옙?�쏙?�占?�븝??
	if(input::IsKeyUp(9))
	{
		if (curChar != maxChar)
		{
			curChar = maxChar;
		}
		//else
		//{
		//	if (curPage < maxPage - 1) // ?�쌩곤옙?�십?�옙 ?�쏙?�占?�옙?�싹곤옙???�占?�력?�옙 ?�싱?�곤?�占?�옙?�쏙?�占?�옙 ?�쏙?�占?�놂???�쏙?�튼?�쏙?�占?�옙?�쏙?�占??�싱?�곤?�占?�옙?�쏙?�占?�옙
		//	{                          // ?�쏙?�튼?�싼곤옙?�쏙???�쏙?�占?�옙?�쏙?�占?�옙?�쏙???�쏙?�占?�옙?�싫??�占??�쏙?�占?�옙?�쌔?�옙 ?�쏙?�占?�옙?�쏙?�占?�옙?�쏙?? bool?�쏙?�占?�옙?�쏙??max?�쏙?�占?�옙?�쏙?�占??�쏙?�占?�옙?�쏙?�占?�옙?�쏙?�占?�옙?�쏙??
		//		curPage++;             //?�占?�옙?�쌔?�옙 ?�쌔?�옙?��??�옙? ?�쏙?�占?�옙?�쏙?�占?�옙?�쏙?�占?�옙 ?�쏙?�占?�스?�占?�옙?�싱?�옙?�쏙??
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
	//?�쏙???�쏙?�혟?�쏙?�占?�옙???�쏙?�占?�옙?�쏙?�占?�옙?�쏙?�占?�옙 ?�싼깍옙觀??
	if (input::IsKeyUp(16))
	{
			if (curPage < maxPage - 1) // �߰��ʿ� �����ϰ�� Ű�Է½� �̴ϰ������� ���ų� ��ư������� �̴ϰ�������
			{
				curPage++;
				curChar = 0;
			}
	}
	//?�쏙??9   //?�쏙?�占?�옙 13  //?�쏙?�占?�옙??16
}
void UpdateText()
{
	
	maxChar = wcslen(str2[curPage]);
	wcsncpy_s(str3[curPage], str2[curPage], curChar + 7);
	// if(curPage == maxChar) �ƽ��� ��ưŬ�� �����ϰԲ�
}
void PrintText()
{	
	render::DrawTextF(250, 730, str3[curPage], RGB(0, 0, 255), 50);

}


void Figure::DrawFigure(int _stagenum)
{
	if (isDraw == true)
	{
		if (_stagenum == 1)
		{
			if (expression == 0) // 기본?�정
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if(expression == 1) //기쁜?�정
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if(expression == 2)//?�쓸?�표??
			{
				render::DrawBackGround("resource/object/shrimp.bmp", 350, 600, 700, 286, false);
			}
			else //?�동먹는 그림
			{
				render::DrawBackGround("resource/object/best.bmp", 350, 600, 700, 286, false);
			}
		}
		else if (_stagenum == 2)
		{
			if (expression == 0) // 기본?�정
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 1) //기쁜?�정
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 2) //?�쓸?�표??
			{
				render::DrawBackGround("resource/object/shrimp.bmp", 350, 600, 700, 286, false);
			}
			else
			{
				render::DrawBackGround("resource/object/best.bmp", 350, 600, 700, 286, false);
			}
		}
		else
		{
			if (expression == 0) // 기본?�정
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 1) //?�는?�정
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 2) //?�쓸?�표??
			{
				render::DrawBackGround("resource/object/shrimp.bmp", 350, 600, 700, 286, false);
			}
			else
			{
				render::DrawBackGround("resource/object/best.bmp", 350, 600, 700, 286, false);
			}
		}
	}
}