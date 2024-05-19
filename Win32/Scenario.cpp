#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "TextList.h"

float printTime;

TextList* textList1 = TextList::GetInstance();
int curChar;     //복사해서 출력한 문자길이
int maxChar;    //한 문장의 끝                  ///나중에 키입력으로 다음 문장으로 넘어가면 그문장의 사이즈를 재서 설정
int curPage;   // 출력하고있는 현재페이지 넘버
int maxPage;   // 한 시나리오의 마지막 페이지 

int txtLen;              
wchar_t str2[20][500];    //구분자로 잘라서 담아둘부분
wchar_t str3[20][500];    //한글자씩 출력할려고 카피할부분

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
		if (success)//성공내용
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
		if (success)//성공내용
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
	//컨트롤키누르면 빨리나오게함 == 지금은 문자하나씩복사해와서 한글자씩출력되는것처럼보임
	if (input::IsKey(17))
	{
		printTime = 10;
	}
	else
	{
		printTime = 100;
	}
	//해당페이지 다 뜨게핣부분
	if(input::IsKeyUp(9))
	{
		if (curChar != maxChar)
		{
			curChar = maxChar;
		}
		//else
		//{
		//	if (curPage < maxPage - 1) // 추가필요 막장일경우 키입력시 미니게임으로 가거나 버튼출력으로 미니게임진입
		//	{                          // 버튼한개로 몰고싶은대 배경전환과 관련해서 문제가있음  bool값으로 max출력인지 다음페이지인지
		//		curPage++;             //확인해서 해야할듯? 다음페이지는 마우스클릭이었나?
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
	//다 출력됬을때 다음페이지로 넘길부분
	if (input::IsKeyUp(16))
	{
			if (curPage < maxPage - 1) // 추가필요 막장일경우 키입력시 미니게임으로 가거나 버튼출력으로 미니게임진입
			{
				curPage++;
				curChar = 0;
			}
	}
	//탭 9   //엔터 13  //쉬프트 16
}
void UpdateText()
{
	
	maxChar = wcslen(str2[curPage]);
	wcsncpy_s(str3[curPage], str2[curPage], curChar + 7);
	// if(curPage == maxChar) 맥스면 버튼클릭 가능하게끔
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
			if (expression == 0) // 기본표정
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if(expression == 1) //기쁜표정
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if(expression == 2)//쓸쓸한표정
			{
				render::DrawBackGround("resource/object/shrimp.bmp", 350, 600, 700, 286, false);
			}
			else //우동먹는 그림
			{
				render::DrawBackGround("resource/object/best.bmp", 350, 600, 700, 286, false);
			}
		}
		else if (_stagenum == 2)
		{
			if (expression == 0) // 기본표정
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 1) //기쁜표정
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 2) //쓸쓸한표정
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
			if (expression == 0) // 기본표정
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 1) //우는표정
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 2) //쓸쓸한표정
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