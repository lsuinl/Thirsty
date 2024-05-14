#include "ScreenTransition.h"

// ���̵� ��/�ƿ� ȿ���� �����Ͽ� ȭ���� ��ȯ�ϴ� �Լ�
void ScreenTransition::Transition(Screen::ScreenName previousScreen, Screen::ScreenName newScreen, float fadeDuration) {
    FadeOut(previousScreen, fadeDuration);
    FadeIn(newScreen, fadeDuration);
}

// ���̵� �ƿ� ȿ���� �����ϴ� �Լ�
void ScreenTransition::FadeOut(Screen::ScreenName screen, float duration) {
    std::cout << "Fading out from " << screen << "..." << std::endl;
    float _timer = 0.0f;
    while (_timer < duration) {

        // ���� ���� ���� ȭ�鿡 �����ϴ� �ڵ�
        float alpha = _timer / duration; // ��� �ð��� ���� ���� ���
        // ������ ȭ���� �������� �� alpha ���� Ȱ���Ͽ� ������ �����մϴ�.

        _timer += 0.1f; // 0.1�ʸ��� ������Ʈ

        // ���̵� �ƿ� �߰� ������ ǥ���� �� �ֵ��� ������ ������ �߰��մϴ�.
    }
}

// ���̵� �� ȿ���� �����ϴ� �Լ�
void ScreenTransition::FadeIn(Screen::ScreenName screen, float duration) {
    std::cout << "Fading in to " << screen << "..." << std::endl;
    float _timer = 0.0f;
    while (_timer < duration) {

        // ���� ���� ���� ȭ�鿡 �����ϴ� �ڵ�
        float alpha = 1.0f - (_timer/ duration); // ��� �ð��� ���� ���� ���
        // ������ ȭ���� �������� �� alpha ���� Ȱ���Ͽ� ������ �����մϴ�.

        _timer += 0.1f; // 0.1�ʸ��� ������Ʈ

        // ���̵� �� �߰� ������ ǥ���� �� �ֵ��� ������ ������ �߰��մϴ�.
    }
}
