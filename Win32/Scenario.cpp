#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "TextList.h"

float printTime;

TextList* textList1 = TextList::GetInstance();
int curChar;     //º¹»çÇØ¼­ Ãâ·ÂÇÑ ¹®ÀÚ±æÀÌ
int maxChar;    //ÇÑ ¹®ÀåÀÇ ³¡                  ///³ªÁß¿¡ Å°ÀÔ·ÂÀ¸·Î ´ÙÀ½ ¹®ÀåÀ¸·Î ³Ñ¾î°¡¸é ±×¹®ÀåÀÇ »çÀÌÁî¸¦ Àç¼­ ¼³Á¤
int curPage;   // Ãâ·ÂÇÏ°íÀÖ´Â ÇöÀçÆäÀÌÁö ³Ñ¹ö
int maxPage;   // ÇÑ ½Ã³ª¸®¿ÀÀÇ ¸¶Áö¸· ÆäÀÌÁö 

int txtLen;              
wchar_t str2[20][500];    //±¸ºĞÀÚ·Î Àß¶ó¼­ ´ã¾ÆµÑºÎºĞ
wchar_t str3[20][500];    //ÇÑ±ÛÀÚ¾¿ Ãâ·ÂÇÒ·Á°í Ä«ÇÇÇÒºÎºĞ

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
		if (success)//? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™
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
		if (success)//? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™
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
	//? ì™?™íŠ¸? ì™?™í‚¤? ì™?™å ?™ì˜™? ì™??? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™ == ? ì™?™å ?™ì˜™? ì™??? ì™?™å ?™ì˜™? ì‹¹?‚ì˜™? ì™?™å ?™ì˜™? ì™?™å ?”ì??½ì˜™ ? ì‹¼ê¹ì˜™? ìŒ˜?µì˜™? ì™?™ì¨‰?”ì§¸? ì‹œ?‚ì˜™? ì™?™å ?™ì˜™??
	if (input::IsKey(17))
	{
		printTime = 10;
	}
	else
	{
		printTime = 100;
	}
	//? ìŒ”?ì˜™? ì™?™å ?™ì˜™? ì™??? ì™??? ìŒ©ê³¤ì˜™? ì™?™å ?¸ë¸??
	if(input::IsKeyUp(9))
	{
		if (curChar != maxChar)
		{
			curChar = maxChar;
		}
		//else
		//{
		//	if (curPage < maxPage - 1) // ? ìŒ©ê³¤ì˜™? ì‹­?¸ì˜™ ? ì™?™å ?™ì˜™? ì‹¹ê³¤ì˜™???¤å ?‰ë ¥?™ì˜™ ? ì‹±?ˆê³¤?™å ?™ì˜™? ì™?™å ?™ì˜™ ? ì™?™å ? ë†‚??? ì™?™íŠ¼? ì™?™å ?™ì˜™? ì™?™å ?? ì‹±?ˆê³¤?™å ?™ì˜™? ì™?™å ?™ì˜™
		//	{                          // ? ì™?™íŠ¼? ì‹¼ê³¤ì˜™? ì™??? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™??? ì™?™å ?™ì˜™? ì‹«??™å ?? ì™?™å ?™ì˜™? ìŒ”?½ì˜™ ? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™?? bool? ì™?™å ?™ì˜™? ì™??max? ì™?™å ?™ì˜™? ì™?™å ?? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™??
		//		curPage++;             //?•å ?™ì˜™? ìŒ”?½ì˜™ ? ìŒ”?µì˜™? ì??¸ì˜™? ? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™ ? ì™?™å ?ŒìŠ¤?´å ?™ì˜™? ì‹±?µì˜™? ì™??
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
	//? ì™??? ì™?™í˜Ÿ? ì™?™å ?™ì˜™??? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™? ì™?™å ?™ì˜™ ? ì‹¼ê¹ì˜™è§€??
	if (input::IsKeyUp(16))
	{
			if (curPage < maxPage - 1) // Ãß°¡ÇÊ¿ä ¸·ÀåÀÏ°æ¿ì Å°ÀÔ·Â½Ã ¹Ì´Ï°ÔÀÓÀ¸·Î °¡°Å³ª ¹öÆ°Ãâ·ÂÀ¸·Î ¹Ì´Ï°ÔÀÓÁøÀÔ
			{
				curPage++;
				curChar = 0;
			}
	}
	//? ì™??9   //? ì™?™å ?™ì˜™ 13  //? ì™?™å ?™ì˜™??16
}
void UpdateText()
{
	
	maxChar = wcslen(str2[curPage]);
	wcsncpy_s(str3[curPage], str2[curPage], curChar + 7);
	// if(curPage == maxChar) ¸Æ½º¸é ¹öÆ°Å¬¸¯ °¡´ÉÇÏ°Ô²û
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
			if (expression == 0) // ê¸°ë³¸?œì •
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if(expression == 1) //ê¸°ìœ?œì •
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if(expression == 2)//?¸ì“¸?œí‘œ??
			{
				render::DrawBackGround("resource/object/shrimp.bmp", 350, 600, 700, 286, false);
			}
			else //?°ë™ë¨¹ëŠ” ê·¸ë¦¼
			{
				render::DrawBackGround("resource/object/best.bmp", 350, 600, 700, 286, false);
			}
		}
		else if (_stagenum == 2)
		{
			if (expression == 0) // ê¸°ë³¸?œì •
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 1) //ê¸°ìœ?œì •
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 2) //?¸ì“¸?œí‘œ??
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
			if (expression == 0) // ê¸°ë³¸?œì •
			{
				render::DrawBackGround("resource/object/test.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 1) //?°ëŠ”?œì •
			{
				render::DrawBackGround("resource/object/basket.bmp", 350, 600, 700, 286, false);
			}
			else if (expression == 2) //?¸ì“¸?œí‘œ??
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