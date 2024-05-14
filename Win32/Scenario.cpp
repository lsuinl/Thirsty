#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"

float printTime;




wchar_t str1[300]; //파일에서 다받아올부분
wchar_t* p = nullptr;
wchar_t* p2 = nullptr;
wchar_t* token;
wchar_t* token2;
wchar_t s;

int i = 0;
int j = 0;
int k = 0;
int l = 0;
int o = 0;
int tokenlen;
int filecount = 0;
wchar_t str2[10][10][300];      //1차로 분리해서 저장할부분
wchar_t str3[10][10][100];     //한글자씩 출력할려고 카피할부분


void SetScript(int num)
{
	std::wifstream fin;
	if (num == 1)
	{
		int previous = 0;
		int curr1 = 1;
		int curr2 = 2;
		fin.open("resource/object/test.txt");
		fin.imbue(std::locale("Korean"));
		if (!fin.is_open()) {
			return;
		}
		filecount = 0;
		while (filecount < 300 && fin.get(str1[filecount])) // 파일의 끝까지 읽거나 배열의 크기를 초과하지 않을 때까지 반복합니다.
		{
			filecount++;
		}
		str1[filecount] = L'\0';
		fin.close(); //파일닫기

		token = wcstok_s(str1, L"&", &p);
		while (token != NULL)
		{
			wcscpy_s(str2[l][k], token);
			token = wcstok_s(NULL, L"&", &p);
			//token 안에 ^가들어가면 >> 앞부분은 k애넣고 l++후 k0으로 바꾸고 반복?
			tokenlen = wcslen(token);


			token2 = wcstok_s(token, L"^", &p2);
			if (token != NULL && wcscmp(token, L" ^ ") == 0)
			{
				wcscpy_s(str2[l][k], token);
				token++;
				l++;
				k = 0;
			}
			else
			{
				k++;
			}


		}
	}
}

void SkipText(float delta)
{
	static ULONGLONG elapsedTime;
	elapsedTime += delta;
	if (input::IsKey(17))
	{
		printTime = 10;
	}
	else
	{
		printTime = 1000;
	}

	if (input::IsKeyUp(9))
	{
		wcscpy_s(str3[o][j], str2[o][j]);
	}

	if (elapsedTime >= printTime)
	{
		if (i < 100)
		{
			i++;
			elapsedTime = 0;
		}
	}
	if (input::IsKeyUp(16))
	{
		o++;
		j = 0;
	}
	//엔터 13  //쉬프트 16
}
void UpdateText()
{
	if (wcscmp(str3[o][j], str2[o][j]) == 0)
	{
		if (j < 9)
		{
			i = 0;
			j++;
		}
	}
	else
	{
		wcsncpy_s(str3[o][j], str2[o][j], i);
	}

}
void PrintText()
{	
	render::DrawTextF(100, 100, str3[o][0], RGB(0, 0, 255), 50);
	render::DrawTextF(100, 200, str3[o][1], RGB(0, 255, 250), 50);
	render::DrawTextF(100, 300, str3[o][2], RGB(0, 255, 250), 50);
	
}