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

		soundManager->SetVolume(0.5f, 1);

	}
	void LoadImages()
	{
		//bmp
		imageManager->GetInstance();
		imageManager->LoadBitMapImages("배경화면", "resource/background/back.bmp", 1920, 1080);
		//imageManager->LoadBitMapImages("엔딩", "resource\\background\\story\\123.bmp", 1920, 6035);
		imageManager->LoadBitMapImages("로딩화면", "resource/background/loading.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("타이틀화면", "resource/background/title.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스테이지1_1", "resource/background/story/stage1_1.bmp", 1600, 750);
		imageManager->LoadBitMapImages("스테이지1_2", "resource/background/story/stage1_2.bmp", 1920, 1080);

		imageManager->LoadBitMapImages("스테이지2_1", "resource/background/story/stage2_1.bmp", 1920, 1080);

		imageManager->LoadBitMapImages("스테이지3_2", "resource/background/story/stage3_2.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면3", "resource/background/story/3.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면4", "resource/background/story/4.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("스토리화면5", "resource/background/story/5.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("일시정지", "resource/background/pause.bmp", 1000, 1000);
		imageManager->LoadBitMapImages("미니게임", "resource/background/minigame.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("도마", "resource/background/minigame.bmp", 1300, 900);
		imageManager->LoadBitMapImages("엔딩크레딧", "resource/background/endingcredit.bmp", 1920, 1080);

		imageManager->LoadPngImages("페이드", L"resource\\background\\fade.bmp");
		imageManager->LoadPngImages("우동한그릇", L"resource\\background\\fade.bmp");
		//imageManager->LoadPngImages("페이드", L"resource\\background\\fade2.bmp");

		//면반죽
		imageManager->LoadPngImages("면반죽", L"resource\\object\\noodleSlice\\noodle.bmp");
		imageManager->LoadPngImages("납작면1", L"resource\\object\\noodleSlice\\flat1.bmp");
		imageManager->LoadPngImages("납작면2", L"resource\\object\\noodleSlice\\flat2.bmp");
		imageManager->LoadPngImages("납작면3", L"resource\\object\\noodleSlice\\flat3.bmp");
		imageManager->LoadPngImages("납작면4", L"resource\\object\\noodleSlice\\flat4.bmp");
		imageManager->LoadPngImages("중면1", L"resource\\object\\noodleSlice\\middle1.bmp");
		imageManager->LoadPngImages("중면2", L"resource\\object\\noodleSlice\\middle2.bmp");
		imageManager->LoadPngImages("중면3", L"resource\\object\\noodleSlice\\middle3.bmp");
		imageManager->LoadPngImages("중면4", L"resource\\object\\noodleSlice\\middle4.bmp");
		imageManager->LoadPngImages("중면5", L"resource\\object\\noodleSlice\\middle5.bmp");
		imageManager->LoadPngImages("중면6", L"resource\\object\\noodleSlice\\middle6.bmp");
		imageManager->LoadPngImages("소면1", L"resource\\object\\noodleSlice\\small1.bmp");
		imageManager->LoadPngImages("소면2", L"resource\\object\\noodleSlice\\small2.bmp");
		imageManager->LoadPngImages("소면3", L"resource\\object\\noodleSlice\\small3.bmp");
		imageManager->LoadPngImages("소면4", L"resource\\object\\noodleSlice\\small4.bmp");
		imageManager->LoadPngImages("소면5", L"resource\\object\\noodleSlice\\small5.bmp");
		imageManager->LoadPngImages("소면6", L"resource\\object\\noodleSlice\\small6.bmp");
		imageManager->LoadPngImages("소면7", L"resource\\object\\noodleSlice\\small7.bmp");
		imageManager->LoadPngImages("소면8", L"resource\\object\\noodleSlice\\small8.bmp");
		imageManager->LoadPngImages("칼든손", L"resource\\object\\knife.bmp");


		//png

		imageManager->LoadPngImages("엔딩", L"resource\\background\\story\\123.png");

		imageManager->LoadPngImages("시작버튼", L"resource\\object\\start.bmp");
		imageManager->LoadPngImages("시작화면", L"resource\\background\\title.png");
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
		imageManager->LoadPngImages("쯔유", L"resource\\object\\soup\\tzuyu.png");
		imageManager->LoadPngImages("무", L"resource\\object\\soup\\mu.bmp");
		imageManager->LoadPngImages("건다시마", L"resource\\object\\soup\\dasima.bmp");
		imageManager->LoadPngImages("냄비", L"resource\\object\\soup\\pot.bmp");


		imageManager->LoadPngImages("기본우동", L"resource\\object\\decoration\\udong.bmp");

		imageManager->LoadPngImages("가쓰오부시", L"resource\\object\\decoration\\gathobusi.bmp");
		imageManager->LoadPngImages("반달어묵", L"resource\\object\\decoration\\bandalmuk.bmp");
		imageManager->LoadPngImages("튀김가루", L"resource\\object\\decoration\\frygaru.bmp");
		imageManager->LoadPngImages("대파", L"resource\\object\\decoration\\daepa.bmp");
		imageManager->LoadPngImages("표고버섯", L"resource\\object\\decoration\\pyogo.bmp");
		imageManager->LoadPngImages("직화고기", L"resource\\object\\decoration\\firemeet.bmp");
		imageManager->LoadPngImages("썬유부", L"resource\\object\\decoration\\yubu.bmp");
		imageManager->LoadPngImages("쑥갓", L"resource\\object\\decoration\\sukk.bmp");
		imageManager->LoadPngImages("썬김(김채)", L"resource\\object\\decoration\\sunkim.bmp");
		imageManager->LoadPngImages("납작어묵", L"resource\\object\\decoration\\flatamuk.bmp");
		imageManager->LoadPngImages("새우튀김", L"resource\\object\\decoration\\shirimp.bmp");
		imageManager->LoadPngImages("썬대파", L"resource\\object\\decoration\\sundaepa.bmp");
		imageManager->LoadPngImages("썬청양고추", L"resource\\object\\decoration\\sungochu.bmp");

		imageManager->LoadPngImages("시치미", L"resource\\object\\decoration\\sichime.png");
		
		
		imageManager->LoadPngImages("텍스트박스", L"resource\\object\\figure\\textbox.png");

		imageManager->LoadPngImages("아이기본", L"resource\\object\\figure\\boygibon.bmp");
		imageManager->LoadPngImages("아이웃음", L"resource\\object\\figure\\boysmile.bmp");
		imageManager->LoadPngImages("아이화남", L"resource\\object\\figure\\boyangre.bmp");
		imageManager->LoadPngImages("아이우동", L"resource\\object\\figure\\boyudong.bmp");
		imageManager->LoadPngImages("고삼기본", L"resource\\object\\figure\\girlgibon.bmp");
		imageManager->LoadPngImages("고삼웃음", L"resource\\object\\figure\\girlsmile.bmp");
		imageManager->LoadPngImages("고삼화남", L"resource\\object\\figure\\girlangry.bmp");
		imageManager->LoadPngImages("고삼우동", L"resource\\object\\figure\\girludong.bmp");
		imageManager->LoadPngImages("중년기본", L"resource\\object\\figure\\oldmangibon.bmp");
		imageManager->LoadPngImages("중년웃음", L"resource\\object\\figure\\oldmangibon.bmp");
		imageManager->LoadPngImages("중년화남", L"resource\\object\\figure\\oldmangibon.bmp");
		imageManager->LoadPngImages("중년우동", L"resource\\object\\figure\\oldmangibon.bmp");



	}
	void LoadAnimation()
	{
	}
}