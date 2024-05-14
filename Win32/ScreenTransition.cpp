#include "ScreenTransition.h"

// 페이드 인/아웃 효과를 적용하여 화면을 전환하는 함수
void ScreenTransition::Transition(Screen::ScreenName previousScreen, Screen::ScreenName newScreen, float fadeDuration) {
    FadeOut(previousScreen, fadeDuration);
    FadeIn(newScreen, fadeDuration);
}

// 페이드 아웃 효과를 적용하는 함수
void ScreenTransition::FadeOut(Screen::ScreenName screen, float duration) {
    std::cout << "Fading out from " << screen << "..." << std::endl;
    float _timer = 0.0f;
    while (_timer < duration) {

        // 계산된 투명도 값을 화면에 적용하는 코드
        float alpha = _timer / duration; // 경과 시간에 따른 투명도 계산
        // 실제로 화면을 렌더링할 때 alpha 값을 활용하여 투명도를 조절합니다.

        _timer += 0.1f; // 0.1초마다 업데이트

        // 페이드 아웃 중간 과정을 표시할 수 있도록 적절한 로직을 추가합니다.
    }
}

// 페이드 인 효과를 적용하는 함수
void ScreenTransition::FadeIn(Screen::ScreenName screen, float duration) {
    std::cout << "Fading in to " << screen << "..." << std::endl;
    float _timer = 0.0f;
    while (_timer < duration) {

        // 계산된 투명도 값을 화면에 적용하는 코드
        float alpha = 1.0f - (_timer/ duration); // 경과 시간에 따른 투명도 계산
        // 실제로 화면을 렌더링할 때 alpha 값을 활용하여 투명도를 조절합니다.

        _timer += 0.1f; // 0.1초마다 업데이트

        // 페이드 인 중간 과정을 표시할 수 있도록 적절한 로직을 추가합니다.
    }
}
