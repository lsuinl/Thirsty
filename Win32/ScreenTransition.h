#pragma once
#include <iostream>
#include <string>
#include "ScreenSystem.h"

class ScreenTransition {
public:
    // 페이드 인/아웃 효과를 적용하여 화면을 전환하는 함수
    void Transition(Screen::ScreenName previousScreen, Screen::ScreenName newScreen, float fadeDuration);

private:
    // 페이드 아웃 효과를 적용하는 함수
    void FadeOut(Screen::ScreenName screen, float duration);

    // 페이드 인 효과를 적용하는 함수
    void FadeIn(Screen::ScreenName screen, float duration);
};