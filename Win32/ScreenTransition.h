#pragma once
#include <iostream>
#include <string>
#include "ScreenSystem.h"

class ScreenTransition {
public:
    // ���̵� ��/�ƿ� ȿ���� �����Ͽ� ȭ���� ��ȯ�ϴ� �Լ�
    void Transition(Screen::ScreenName previousScreen, Screen::ScreenName newScreen, float fadeDuration);

private:
    // ���̵� �ƿ� ȿ���� �����ϴ� �Լ�
    void FadeOut(Screen::ScreenName screen, float duration);

    // ���̵� �� ȿ���� �����ϴ� �Լ�
    void FadeIn(Screen::ScreenName screen, float duration);
};