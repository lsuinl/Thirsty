#pragma once
#include "RenderSystem.h"
#include "ScreenSystem.h"
#include "InputSystem.h"
#include "Button.h"
#include "LoadData.h"

namespace Title
{
	void isEsc();
	void TitleCheckClick(int x, int y);
	void StartButton();
	void TutorialButton();
	void ExitButton();
	void TitleRender();
	void TitleCheckHover(int x, int y);
};
