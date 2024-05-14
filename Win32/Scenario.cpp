#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"

float printTime;
const wchar_t* str1[5] = { L"흔히 이승에서  aadwad사는 유령은 1234567890 ㅂㅈㄷㄱ ㅁㄴㅇㄹ ㅋㅌㅊㅍ",
	L"흔히 저승에서  어쩌구 저쩌구  안녕하세요 유령입니다ㅈㅁㅇfadwadwad",L"adwadwadd",L"dwadwadwa",L"dwad끝끝끝끝끝" };  //시나리오 대사를 미리 입력해둘1
wchar_t str2[5][100];  //각 시나리오일떄 1번을 카피해서 저장해둘 2
wchar_t str3[5][100];  //하나씩 출력할떄 저장해둘 3
int i = 0;
int j = 0;
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
		wcscpy_s(str3[j], str2[j]);
	}

	if (elapsedTime >= printTime)
	{
		if (i < 100)
		{
			i++;
			elapsedTime = 0;
		}
	}

}
void UpdateText()
{
	wcscpy_s(str2[j], str1[j]);
	if (wcscmp(str3[j], str2[j]) == 0)
	{
		if (j < 4)
		{
			i = 0;
			j++;
		}
	}
	else
	{
		wcsncpy_s(str3[j], str2[j], i);
	}

}
void PrintText()
{
	render::DrawTextF(100, 100, str3[0], RGB(0, 0, 255), 50);
	render::DrawTextF(100, 200, str3[1], RGB(0, 255, 250), 50);
	render::DrawTextF(100, 300, str3[2], RGB(0, 255, 250), 50);
	render::DrawTextF(100, 400, str3[3], RGB(0, 255, 250), 50);
	render::DrawTextF(100, 500, str3[4], RGB(0, 255, 250), 50);
}