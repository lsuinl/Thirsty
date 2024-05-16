#pragma once
#include <fstream>
#include <string>
#include <iostream>

//해당 
void SetScript(int num);

//키입력시 빠르게 업데이트 or 한줄 다 업데이트 후 다음줄로
void SkipText(float delta);

//텍스트를 한글자씩 복사해서 업데이트
void UpdateText();

//텍스트 출력
void PrintText();


//시나리오화면 (setscript)로 해당 시나리오에서 쓸 문자열저장
//  >> 시나리오 뒷배경 넣어야함  >> 시나리오 텍스트박스 출력(printtext) >> 키입력시 넘어가는기능 (skiptext)추가로 배경도 바뀌면추가
//  >> 텍스트 끝나면 미니게임으로 넘어가게끔 버튼구현  