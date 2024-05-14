#include "Scenario.h"
#include "RenderSystem.h"
#include "InputSystem.h"

float printTime;
const wchar_t* str1[5] = { L"���� �̽¿���  aadwad��� ������ 1234567890 �������� �������� ��������",
	L"���� ���¿���  ��¼�� ��¼��  �ȳ��ϼ��� �����Դϴ٤�����fadwadwad",L"adwadwadd",L"dwadwadwa",L"dwad����������" };  //�ó����� ��縦 �̸� �Է��ص�1
wchar_t str2[5][100];  //�� �ó������ϋ� 1���� ī���ؼ� �����ص� 2
wchar_t str3[5][100];  //�ϳ��� ����ҋ� �����ص� 3
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