#pragma once
#include "Scenario.h"
//#include "TimeSystem.h"
#include "RenderSystem.h"
#include "InputSystem.h"

//뒷배경 붙여야함 키입력시 뒷배경 바껴야함 특정키입력시 i++ i기 몇일떈 해당bmp 몇일떈 해당 bmp출력되게끔

void SetStage(int num);

void DrawBack();

void ChangeBack(float delta);