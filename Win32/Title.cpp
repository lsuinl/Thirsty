#include "Title.h"

void Title::TitleUpdate()
{

}

void Title::StartButton()
{

}

void Title::TutorialButton()
{

}

void Title::TitleRender()
{
	render::DrawBackGround("resource\\background\\back.bmp", 0, 0, 0, 0, false);
	render::DrawObject(L"resource\\object\\Logo.png", 1000, 500, 100, 100, false);
}