#include "LoadData.h"
#include "GlobalHeader.h"
#include "SoundManager.h"
namespace LoadData
{
	Music::SoundManager* soundManager = Music::SoundManager::GetInstance();   
	Images::ImageManager* imageManager = Images::ImageManager::GetInstance(); 
	void LoadMusic()
	{
		soundManager->GetInstance(); 
		soundManager->LoadMusic(Music::eSoundList::click, false, "resource//sound//click.ogg"); //버튼 클릭 기본 효과음
		soundManager->LoadMusic(Music::eSoundList::inside, false, "resource//sound//inside.ogg"); //손님 입장 효과음
		soundManager->LoadMusic(Music::eSoundList::typeing, false, "resource//sound//typeing.ogg"); //스토리 타이핑
		soundManager->LoadMusic(Music::eSoundList::moveani, false, "resource//sound//moveani.ogg"); //커튼 효과음
		
		soundManager->LoadMusic(Music::eSoundList::put, false, "resource//sound//put.ogg"); //고명 내려놓기

		soundManager->LoadMusic(Music::eSoundList::stock, false, "resource//sound//stock.ogg"); //면 끓이기

		soundManager->LoadMusic(Music::eSoundList::arrow, false, "resource//sound//arrow.ogg"); //방향키 입력 완료시
		soundManager->LoadMusic(Music::eSoundList::right, false, "resource//sound//right.ogg"); //방향키 맞았을 때
		soundManager->LoadMusic(Music::eSoundList::wrong, false, "resource//sound//wrong.ogg"); //키보드 틀렸을 때
		soundManager->LoadMusic(Music::eSoundList::slice, false, "resource//sound//slice.ogg"); //면자르기 효과음
		soundManager->LoadMusic(Music::eSoundList::noodleslice, false, "resource//sound//noodleslice.ogg"); //면자르기 배경

		soundManager->LoadMusic(Music::eSoundList::story, true, "resource//sound//story.ogg"); //스토리 진행 배경음
		soundManager->LoadMusic(Music::eSoundList::timemout, true, "resource//sound//timemout.ogg"); //타임오버
		soundManager->LoadMusic(Music::eSoundList::title, true, "resource//sound//title.ogg"); //타이틀
		soundManager->LoadMusic(Music::eSoundList::realEnding, true, "resource//sound//realEnding.ogg"); //진엔딩
		soundManager->LoadMusic(Music::eSoundList::normalEnding, true, "resource//sound//normalEnding.ogg"); //노말엔딩

		soundManager->SetVolume(0.5f,1);
	}
	void LoadImages()
	{
		//bmp
		imageManager->GetInstance();
		imageManager->LoadBitMapImages("배경화면", "resource/background/back.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("로딩화면", "resource/background/loading.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("타이틀화면", "resource/background/title.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면1", "resource/background/story/1.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면2", "resource/background/story/2.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면3", "resource/background/story/3.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리   화면4", "resource/background/story/4.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면5", "resource/background/story/5.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("일시정지", "resource/background/pause.bmp", 1000, 1000);
		imageManager->LoadBitMapImages("미니게임", "resource/background/minigame.bmp", 1920, 1920);
		imageManager->LoadBitMapImages("도마", "resource/background/minigame.bmp", 1300, 900);

		//png
		imageManager->LoadPngImages("시작버튼", L"resource\\object\\start.bmp");
		imageManager->LoadPngImages("튜토리얼버튼", L"resource\\object\\tutorial.bmp");
		imageManager->LoadPngImages("제목", L"resource\\object\\Logo.png");
		imageManager->LoadPngImages("규칙", L"resource\\object\\rule.png");
		imageManager->LoadPngImages("짱", L"resource\\object\\best.bmp");
		imageManager->LoadPngImages("바구니", L"resource\\object\\basket.bmp");
		imageManager->LoadPngImages("새우", L"resource\\object\\Prriceshrimp.bmp");
		imageManager->LoadPngImages("재시작버튼", L"resource\\object\\restart.bmp");
		imageManager->LoadPngImages("타이틀버튼", L"resource\\object\\title.bmp");

		imageManager->LoadPngImages("아래", L"resource\\object\\down.png");
		imageManager->LoadPngImages("빨간아래", L"resource\\object\\down1.png");
		imageManager->LoadPngImages("회색아래", L"resource\\object\\down2.png");
		imageManager->LoadPngImages("위", L"resource\\object\\up.png");
		imageManager->LoadPngImages("빨간위", L"resource\\object\\up1.png");
		imageManager->LoadPngImages("회색위", L"resource\\object\\up2.png");
		imageManager->LoadPngImages("왼쪽", L"resource\\object\\left.png");
		imageManager->LoadPngImages("빨간왼쪽", L"resource\\object\\left1.png");
		imageManager->LoadPngImages("회색왼쪽", L"resource\\object\\left2.png");
		imageManager->LoadPngImages("오른쪽", L"resource\\object\\right.png");
		imageManager->LoadPngImages("빨간오른쪽", L"resource\\object\\right1.png");
		imageManager->LoadPngImages("회색오른쪽", L"resource\\object\\right2.png");
		imageManager->LoadPngImages("왼쪽버튼", L"resource\\object\\leftPage.bmp");
		imageManager->LoadPngImages("오른쪽버튼", L"resource\\object\\rightPage.bmp");
		imageManager->LoadPngImages("위쪽버튼", L"resource\\object\\upPage.bmp");
		imageManager->LoadPngImages("아래쪽버튼", L"resource\\object\\downPage.bmp");
		imageManager->LoadPngImages("완료버튼", L"resource\\object\\clear.bmp");
		imageManager->LoadPngImages("납작면", L"resource\\object\\noodle\\flat.bmp");
		imageManager->LoadPngImages("기본면", L"resource\\object\\noodle\\middle.bmp");
		imageManager->LoadPngImages("소면", L"resource\\object\\noodle\\small.bmp");
		imageManager->LoadPngImages("멸치", L"resource\\object\\soup\\maulchi.bmp");
		imageManager->LoadPngImages("쯔유", L"resource\\object\\soup\\tzuyu.bmp");
		imageManager->LoadPngImages("무", L"resource\\object\\soup\\mu.bmp");
		imageManager->LoadPngImages("가쓰오부시", L"resource\\object\\soup\\gathobusi.bmp");
		imageManager->LoadPngImages("대파", L"resource\\object\\decoration\\daepa.bmp");
		imageManager->LoadPngImages("건다시마", L"resource\\object\\decoration\\dasima.bmp");
		imageManager->LoadPngImages("시치미", L"resource\\object\\decoration\\sichime.bmp");
		imageManager->LoadPngImages("쪽파", L"resource\\object\\decoration\\chupa.bmp");
		imageManager->LoadPngImages("표고버섯", L"resource\\object\\decoration\\pyogo.bmp");
		imageManager->LoadPngImages("직화고기", L"resource\\object\\decoration\\firemeet.bmp");
		imageManager->LoadPngImages("썬유부", L"resource\\object\\decoration\\yubu.bmp");
		imageManager->LoadPngImages("쑥갓", L"resource\\object\\decoration\\sukk.bmp");
		imageManager->LoadPngImages("썬김(김채)", L"resource\\object\\decoration\\sunkim.bmp");
		imageManager->LoadPngImages("납작어묵", L"resource\\object\\decoration\\flatamuk.bmp");
		imageManager->LoadPngImages("새우튀김", L"resource\\object\\decoration\\shirimp.bmp");

		imageManager->LoadPngImages("꼬마유령기본", L"resource\\object\\test.png");
		imageManager->LoadPngImages("꼬마유령웃음", L"resource\\object\\rule.png");
		imageManager->LoadPngImages("꼬마유령쓸쓸", L"resource\\object\\left.png");
		imageManager->LoadPngImages("꼬마유령우동", L"resource\\object\\right.png");
		imageManager->LoadPngImages("고삼유령기본", L"resource\\object\\test.png");
		imageManager->LoadPngImages("고삼유령웃음", L"resource\\object\\rule.png");
		imageManager->LoadPngImages("고삼유령쓸쓸", L"resource\\object\\left.png");
		imageManager->LoadPngImages("고삼유령우동", L"resource\\object\\right.png");
		imageManager->LoadPngImages("중년유령기본", L"resource\\object\\test.png");
		imageManager->LoadPngImages("중년유령웃음", L"resource\\object\\rule.png");
		imageManager->LoadPngImages("중년유령쓸쓸", L"resource\\object\\left.png");
		imageManager->LoadPngImages("중년유령우동", L"resource\\object\\right.png");
		
		
		imageManager->LoadPngImages("텍스트박스", L"resource\\object\\rect.png");

	}
	void LoadAnimation()
	{
	}
}