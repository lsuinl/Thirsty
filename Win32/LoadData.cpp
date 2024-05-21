#include "LoadData.h"
#include "GlobalHeader.h"
#include "SoundManager.h"
namespace LoadData
{
	Music::SoundManager* soundManager = Music::SoundManager::GetInstance();   
	Images::ImageManager* imageManager = Images::ImageManager::GetInstance(); 
	void LoadMusic()
	{
		//soundManager->GetInstance(); 
		//soundManager->LoadMusic(Music::eSoundList::StartBGM, true, "resource//sound//title.ogg");
		//soundManager->LoadMusic(Music::eSoundList::correct, false, "resource//sound//bgm3.mp3");
		//soundManager->LoadMusic(Music::eSoundList::wrong, false, "resource//sound//bgm3.mp3");
		//soundManager->LoadMusic(Music::eSoundList::hint, false, "resource//sound//bgm3.mp3");
		//soundManager->LoadMusic(Music::eSoundList::win, false, "resource//sound//bgm3.mp3");
		//soundManager->LoadMusic(Music::eSoundList::start, false, "resource//sound//bgm3.mp3"); 
		//soundManager->LoadMusic(Music::eSoundList::success, false, "resource//sound//bgm3.mp3");
		//soundManager->LoadMusic(Music::eSoundList::fail, false, "resource//sound//bgm3.mp3");
		//soundManager->SetVolume(0.5f);
	}
	void LoadImages()
	{
		//bmp
		imageManager->GetInstance();
		imageManager->LoadBitMapImages("���ȭ��", "resource/background/back.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("�ε�ȭ��", "resource/background/loading.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("Ÿ��Ʋȭ��", "resource/background/title.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��1", "resource/background/story/1.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��2", "resource/background/story/2.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��3", "resource/background/story/3.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��4", "resource/background/story/4.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��5", "resource/background/story/5.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("�Ͻ�����", "resource/background/pause.bmp", 1000, 1000);
		imageManager->LoadBitMapImages("�̴ϰ���", "resource/background/minigame.bmp", 1920, 1920);
		imageManager->LoadBitMapImages("����", "resource/background/minigame.bmp", 1300, 900);
		imageManager->LoadBitMapImages("����ũ����", "resource/background/endingcredit.bmp", 1920, 1080);

		imageManager->LoadPngImages("���̵�", L"resource\\background\\fade.bmp");

		//�����
		imageManager->LoadPngImages("�����",  L"resource\\object\\noodleSlice\\noodle.bmp");
		imageManager->LoadPngImages("���۸�1", L"resource\\object\\noodleSlice\\flat1.bmp");
		imageManager->LoadPngImages("���۸�2", L"resource\\object\\noodleSlice\\flat2.bmp");
		imageManager->LoadPngImages("���۸�3", L"resource\\object\\noodleSlice\\flat3.bmp");
		imageManager->LoadPngImages("���۸�4", L"resource\\object\\noodleSlice\\flat4.bmp");
		imageManager->LoadPngImages("�߸�1", L"resource\\object\\noodleSlice\\middle1.bmp");
		imageManager->LoadPngImages("�߸�2", L"resource\\object\\noodleSlice\\middle2.bmp");
		imageManager->LoadPngImages("�߸�3", L"resource\\object\\noodleSlice\\middle3.bmp");
		imageManager->LoadPngImages("�߸�4", L"resource\\object\\noodleSlice\\middle4.bmp");
		imageManager->LoadPngImages("�߸�5", L"resource\\object\\noodleSlice\\middle5.bmp");
		imageManager->LoadPngImages("�߸�6", L"resource\\object\\noodleSlice\\middle6.bmp");
		imageManager->LoadPngImages("�Ҹ�1", L"resource\\object\\noodleSlice\\small1.bmp");
		imageManager->LoadPngImages("�Ҹ�2", L"resource\\object\\noodleSlice\\small2.bmp");
		imageManager->LoadPngImages("�Ҹ�3", L"resource\\object\\noodleSlice\\small3.bmp");
		imageManager->LoadPngImages("�Ҹ�4", L"resource\\object\\noodleSlice\\small4.bmp");
		imageManager->LoadPngImages("�Ҹ�5", L"resource\\object\\noodleSlice\\small5.bmp");
		imageManager->LoadPngImages("�Ҹ�6", L"resource\\object\\noodleSlice\\small6.bmp");
		imageManager->LoadPngImages("�Ҹ�7", L"resource\\object\\noodleSlice\\small7.bmp");
		imageManager->LoadPngImages("�Ҹ�8", L"resource\\object\\noodleSlice\\small8.bmp");
		imageManager->LoadPngImages("Į���", L"resource\\object\\knife.bmp");

		//png
		imageManager->LoadPngImages("���۹�ư", L"resource\\object\\start.bmp");
		imageManager->LoadPngImages("����ȭ��", L"resource\\background\\title.png");
		imageManager->LoadPngImages("Ʃ�丮���ư", L"resource\\object\\tutorial.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\Logo.png");
		imageManager->LoadPngImages("��Ģ", L"resource\\object\\rule.png");
		imageManager->LoadPngImages("¯", L"resource\\object\\best.bmp");
		imageManager->LoadPngImages("�ٱ���", L"resource\\object\\basket.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\Prriceshrimp.bmp");
		imageManager->LoadPngImages("����۹�ư", L"resource\\object\\restart.bmp");
		imageManager->LoadPngImages("Ÿ��Ʋ��ư", L"resource\\object\\title.bmp");

		imageManager->LoadPngImages("�Ʒ�", L"resource\\object\\down.png");
		imageManager->LoadPngImages("�����Ʒ�", L"resource\\object\\down1.png");
		imageManager->LoadPngImages("ȸ���Ʒ�", L"resource\\object\\down2.png");
		imageManager->LoadPngImages("��", L"resource\\object\\up.png");
		imageManager->LoadPngImages("������", L"resource\\object\\up1.png");
		imageManager->LoadPngImages("ȸ����", L"resource\\object\\up2.png");
		imageManager->LoadPngImages("����", L"resource\\object\\left.png");
		imageManager->LoadPngImages("��������", L"resource\\object\\left1.png");
		imageManager->LoadPngImages("ȸ������", L"resource\\object\\left2.png");
		imageManager->LoadPngImages("������", L"resource\\object\\right.png");
		imageManager->LoadPngImages("����������", L"resource\\object\\right1.png");
		imageManager->LoadPngImages("ȸ��������", L"resource\\object\\right2.png");
		imageManager->LoadPngImages("���ʹ�ư", L"resource\\object\\leftPage.bmp");
		imageManager->LoadPngImages("�����ʹ�ư", L"resource\\object\\rightPage.bmp");
		imageManager->LoadPngImages("���ʹ�ư", L"resource\\object\\upPage.bmp");
		imageManager->LoadPngImages("�Ʒ��ʹ�ư", L"resource\\object\\downPage.bmp");
		imageManager->LoadPngImages("�Ϸ��ư", L"resource\\object\\clear.bmp");
		imageManager->LoadPngImages("���۸�", L"resource\\object\\noodle\\flat.bmp");
		imageManager->LoadPngImages("�⺻��", L"resource\\object\\noodle\\middle.bmp");
		imageManager->LoadPngImages("�Ҹ�", L"resource\\object\\noodle\\small.bmp");
		imageManager->LoadPngImages("��ġ", L"resource\\object\\soup\\maulchi.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\soup\\tzuyu.bmp");
		imageManager->LoadPngImages("��", L"resource\\object\\soup\\mu.bmp");
		imageManager->LoadPngImages("�������ν�", L"resource\\object\\soup\\gathobusi.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\decoration\\daepa.bmp");
		imageManager->LoadPngImages("�Ǵٽø�", L"resource\\object\\decoration\\dasima.bmp");
		imageManager->LoadPngImages("��ġ��", L"resource\\object\\decoration\\sichime.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\decoration\\chupa.bmp");
		imageManager->LoadPngImages("ǥ�����", L"resource\\object\\decoration\\pyogo.bmp");
		imageManager->LoadPngImages("��ȭ���", L"resource\\object\\decoration\\firemeet.bmp");
		imageManager->LoadPngImages("������", L"resource\\object\\decoration\\yubu.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\decoration\\sukk.bmp");
		imageManager->LoadPngImages("���(��ä)", L"resource\\object\\decoration\\sunkim.bmp");
		imageManager->LoadPngImages("���۾", L"resource\\object\\decoration\\flatamuk.bmp");
		imageManager->LoadPngImages("����Ƣ��", L"resource\\object\\decoration\\shirimp.bmp");
		
		
		imageManager->LoadPngImages("�ؽ�Ʈ�ڽ�", L"resource\\object\\rect.png");

	}
	void LoadAnimation()
	{
	}
}