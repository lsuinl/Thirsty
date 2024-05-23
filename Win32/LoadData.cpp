#include "LoadData.h"
#include "GlobalHeader.h"
#include "SoundManager.h"
namespace LoadData
{
	Music::SoundManager* soundManager = Music::SoundManager::GetInstance();
	Images::ImageManager* imageManager = Images::ImageManager::GetInstance();
	Animator* AniManager = new Animator[3];
	void LoadMusic()
	{
		soundManager->GetInstance();
		soundManager->LoadMusic(Music::eSoundList::click, false, "resource//sound//click.ogg"); //��ư Ŭ�� �⺻ ȿ����
		soundManager->LoadMusic(Music::eSoundList::inside, false, "resource//sound//inside.ogg"); //�մ� ���� ȿ����
		soundManager->LoadMusic(Music::eSoundList::typeing, true, "resource//sound//typeing.ogg"); //���丮 Ÿ����
		soundManager->LoadMusic(Music::eSoundList::moveani, false, "resource//sound//moveani.ogg"); //Ŀư ȿ����

		soundManager->LoadMusic(Music::eSoundList::put, false, "resource//sound//put.ogg"); //��� ��������

		soundManager->LoadMusic(Music::eSoundList::stock, false, "resource//sound//stock.ogg"); //�� ���̱�
		soundManager->LoadMusic(Music::eSoundList::stockbgm, false, "resource//sound//stockbgm.ogg"); //�� ���̱� ���

		soundManager->LoadMusic(Music::eSoundList::arrow, false, "resource//sound//arrow.ogg"); //����Ű �Է� �Ϸ��
		soundManager->LoadMusic(Music::eSoundList::right, false, "resource//sound//right.ogg"); //����Ű �¾��� ��
		soundManager->LoadMusic(Music::eSoundList::wrong, false, "resource//sound//wrong.ogg"); //Ű���� Ʋ���� ��
		soundManager->LoadMusic(Music::eSoundList::slice, false, "resource//sound//slice.ogg"); //���ڸ��� ȿ����
		soundManager->LoadMusic(Music::eSoundList::noodleslice, false, "resource//sound//noodleslice.ogg"); //���ڸ��� ���

		soundManager->LoadMusic(Music::eSoundList::eat, false, "resource//sound//eat.ogg"); //�쵿�Ա�
		soundManager->LoadMusic(Music::eSoundList::choose, false, "resource//sound//choose.ogg"); //��� �����
		soundManager->LoadMusic(Music::eSoundList::complete, false, "resource//sound//complete.ogg"); //�쵿�ϼ�

		soundManager->LoadMusic(Music::eSoundList::story, true, "resource//sound//story.ogg"); //���丮 ���� �����
		soundManager->LoadMusic(Music::eSoundList::timemout, true, "resource//sound//timemout.ogg"); //Ÿ�ӿ���
		soundManager->LoadMusic(Music::eSoundList::title, true, "resource//sound//title.ogg"); //Ÿ��Ʋ
		soundManager->LoadMusic(Music::eSoundList::realEnding, true, "resource//sound//realEnding.ogg"); //������
		soundManager->LoadMusic(Music::eSoundList::normalEnding, true, "resource//sound//normalEnding.ogg"); //�븻����

		soundManager->SetVolume(0.5f, 1);

	}
	void LoadImages()
	{
		//bmp
		imageManager->GetInstance();
		//imageManager->LoadBitMapImages("���ȭ��", "resource/background/back.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("�ε�ȭ��", "resource/background/loading.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("Ÿ��Ʋȭ��", "resource/background/title.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("��������1_1", "resource/background/story/stage1_1.bmp", 1935, 1080);
		imageManager->LoadBitMapImages("��������1_2", "resource/background/story/stage1_2.bmp", 1935, 1080);

		imageManager->LoadBitMapImages("��������2_1", "resource/background/story/stage2_1.bmp", 1935, 1080);
		imageManager->LoadBitMapImages("��������2_2", "resource/background/story/stage2_2.bmp", 1935, 1080);

		imageManager->LoadBitMapImages("��������3_1", "resource/background/story/stage3_1.bmp", 1935, 1080);
		imageManager->LoadBitMapImages("��������3_2", "resource/background/story/stage3_2.bmp", 1935, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��3", "resource/background/story/3.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��4", "resource/background/story/4.bmp", 1920, 1080);
		imageManager->LoadBitMapImages("���丮ȭ��5", "resource/background/story/5.bmp", 1920, 1080);
		//imageManager->LoadBitMapImages("�Ͻ�����", "resource/background/pause.bmp", 1000, 1000);
		imageManager->LoadBitMapImages("�̴ϰ���", "resource/background/minigame.bmp", 1935, 1080);
		imageManager->LoadBitMapImages("����", "resource/background/minigame.bmp", 1415, 650);
		imageManager->LoadBitMapImages("����ũ����", "resource/background/endingcredit.bmp", 1920, 1080);

		imageManager->LoadPngImages("���̵�", L"resource\\background\\fade.bmp");
		imageManager->LoadPngImages("�쵿�ѱ׸�", L"resource\\background\\fade2.bmp");
		//imageManager->LoadPngImages("���̵�", L"resource\\background\\fade2.bmp");
		imageManager->LoadPngImages("�Ͻ�����", L"resource\\background\\pause.bmp");

		//�����
		imageManager->LoadPngImages("�����", L"resource\\object\\noodleSlice\\noodle.bmp");
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
		imageManager->LoadPngImages("���ȭ��", L"resource\\background\\back.png");
		imageManager->LoadPngImages("����", L"resource\\background\\story\\123.png");

		imageManager->LoadPngImages("���۹�ư", L"resource\\object\\start1.bmp");
		imageManager->LoadPngImages("����ȭ��", L"resource\\background\\title.png");
		imageManager->LoadPngImages("Ʃ�丮���ư", L"resource\\object\\tutorial1.bmp");

		imageManager->LoadPngImages("�����ư", L"resource\\object\\break.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\logo.bmp");

		imageManager->LoadPngImages("��Ģ", L"resource\\object\\rule.png");
		imageManager->LoadPngImages("¯", L"resource\\object\\best.bmp");

		imageManager->LoadPngImages("�ٱ���", L"resource\\object\\baguni.bmp");
		imageManager->LoadPngImages("����¹ٱ���", L"resource\\object\\ddoma.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\Prriceshrimp.bmp");
		imageManager->LoadPngImages("����۹�ư", L"resource\\object\\restart1.bmp");
		imageManager->LoadPngImages("Ÿ��Ʋ��ư", L"resource\\object\\title.bmp");
		imageManager->LoadPngImages("�丮����", L"resource\\object\\cookstart.bmp");
		imageManager->LoadPngImages("�丮����", L"resource\\object\\cookcomplete.bmp");

		imageManager->LoadPngImages("�Ʒ�", L"resource\\object\\down.bmp");
		imageManager->LoadPngImages("�����Ʒ�", L"resource\\object\\down1.bmp");
		imageManager->LoadPngImages("ȸ���Ʒ�", L"resource\\object\\down2.bmp");
		imageManager->LoadPngImages("��", L"resource\\object\\up.bmp");
		imageManager->LoadPngImages("������", L"resource\\object\\up1.bmp");
		imageManager->LoadPngImages("ȸ����", L"resource\\object\\up2.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\left.bmp");
		imageManager->LoadPngImages("��������", L"resource\\object\\left1.bmp");
		imageManager->LoadPngImages("ȸ������", L"resource\\object\\left2.bmp");
		imageManager->LoadPngImages("������", L"resource\\object\\right.bmp");
		imageManager->LoadPngImages("����������", L"resource\\object\\right1.bmp");
		imageManager->LoadPngImages("ȸ��������", L"resource\\object\\right2.bmp");
		imageManager->LoadPngImages("���ʹ�ư", L"resource\\object\\leftPage.bmp");
		imageManager->LoadPngImages("�����ʹ�ư", L"resource\\object\\rightPage.bmp");
		imageManager->LoadPngImages("���ʹ�ư", L"resource\\object\\upPage.bmp");
		imageManager->LoadPngImages("�Ʒ��ʹ�ư", L"resource\\object\\downPage.bmp");
		imageManager->LoadPngImages("�Ϸ��ư", L"resource\\object\\complete.bmp");
		imageManager->LoadPngImages("�޴�", L"resource\\object\\menu.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\clear.bmp");
		imageManager->LoadPngImages("Ÿ�ӿ���", L"resource\\object\\timeout.bmp");

		imageManager->LoadPngImages("���۸�", L"resource\\object\\noodle\\flat.bmp");
		imageManager->LoadPngImages("�⺻��", L"resource\\object\\noodle\\middle.bmp");
		imageManager->LoadPngImages("�Ҹ�", L"resource\\object\\noodle\\small.bmp");

		imageManager->LoadPngImages("��ġ", L"resource\\object\\soup\\maulchi.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\soup\\tzuyu.png");
		imageManager->LoadPngImages("��", L"resource\\object\\soup\\mu.bmp");
		imageManager->LoadPngImages("�Ǵٽø�", L"resource\\object\\soup\\dasima.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\soup\\pot.bmp");

		imageManager->LoadPngImages("�̰ſ�", L"resource\\object\\soup\\singer.png");
		imageManager->LoadPngImages("«", L"resource\\object\\soup\\zzam.png");

		imageManager->LoadPngImages("�������", L"resource\\object\\soup\\yellowbox.bmp");
		imageManager->LoadPngImages("��������", L"resource\\object\\soup\\redbox.bmp");
		imageManager->LoadPngImages("��������", L"resource\\object\\soup\\blackbox.png");
		imageManager->LoadPngImages("����Ʈ��", L"resource\\object\\soup\\best.bmp");
		imageManager->LoadPngImages("����Ʈ����", L"resource\\object\\soup\\bestword.png");

		imageManager->LoadPngImages("��ҳ���", L"resource\\object\\soup\\weakpot.png");
		imageManager->LoadPngImages("���ҳ���", L"resource\\object\\soup\\strongpot.png");
		imageManager->LoadPngImages("��ġ�³���", L"resource\\object\\soup\\megastrongpot.png");
		imageManager->LoadPngImages("����", L"resource\\object\\soup\\brim.png");

		imageManager->LoadPngImages("�������ν�", L"resource\\object\\decoration\\gathobusi.bmp");
		imageManager->LoadPngImages("�ݴ޾", L"resource\\object\\decoration\\bandalmuk.bmp");
		imageManager->LoadPngImages("��ġ��", L"resource\\object\\decoration\\sichime.bmp");
		imageManager->LoadPngImages("Ƣ�谡��", L"resource\\object\\decoration\\frygaru.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\decoration\\daepa.bmp");
		imageManager->LoadPngImages("ǥ�����", L"resource\\object\\decoration\\pyogo.bmp");
		imageManager->LoadPngImages("��ȭ���", L"resource\\object\\decoration\\firemeet.bmp");
		imageManager->LoadPngImages("������", L"resource\\object\\decoration\\yubu.bmp");
		imageManager->LoadPngImages("����", L"resource\\object\\decoration\\sukk.bmp");
		imageManager->LoadPngImages("���(��ä)", L"resource\\object\\decoration\\sunkim.bmp");
		imageManager->LoadPngImages("���۾", L"resource\\object\\decoration\\flatamuk.bmp");
		imageManager->LoadPngImages("����Ƣ��", L"resource\\object\\decoration\\shirimp.bmp");
		imageManager->LoadPngImages("�����", L"resource\\object\\decoration\\sundaepa.bmp");
		imageManager->LoadPngImages("��û�����", L"resource\\object\\decoration\\sungochu.bmp");
		
		
		imageManager->LoadPngImages("�ؽ�Ʈ�ڽ�", L"resource\\object\\figure\\textbox1.bmp");

		imageManager->LoadPngImages("���ͻ���", L"resource\\object\\figure\\entertext.bmp");


		imageManager->LoadPngImages("���̱⺻", L"resource\\object\\figure\\boygibon.bmp");
		imageManager->LoadPngImages("���̿���", L"resource\\object\\figure\\boysmile.bmp");
		imageManager->LoadPngImages("����ȭ��", L"resource\\object\\figure\\boyangry.bmp");
		imageManager->LoadPngImages("���̿쵿", L"resource\\object\\figure\\boyudong.bmp");

		imageManager->LoadPngImages("���⺻", L"resource\\object\\figure\\girlgibon.bmp");
		imageManager->LoadPngImages("������", L"resource\\object\\figure\\girlsmile.bmp");
		imageManager->LoadPngImages("���ȭ��", L"resource\\object\\figure\\girlangry.bmp");
		imageManager->LoadPngImages("���쵿", L"resource\\object\\figure\\girludong.bmp");
		imageManager->LoadPngImages("�߳�⺻", L"resource\\object\\figure\\oldmangibon.bmp");
		imageManager->LoadPngImages("�߳����", L"resource\\object\\figure\\oldmansmile.bmp");
		imageManager->LoadPngImages("�߳�ȭ��", L"resource\\object\\figure\\oldmanangry.bmp");
		imageManager->LoadPngImages("�߳�쵿", L"resource\\object\\figure\\oldmanudong.bmp");
		imageManager->LoadPngImages("�߳����", L"resource\\object\\figure\\oldmancry.bmp");
		imageManager->LoadPngImages("�⺻�쵿", L"resource\\object\\decoration\\udong.bmp");



	}
	void LoadAnimation()
	{
		//Ŀư�ݱ� �ִϸ��̼�(0)
		Gdiplus::Image** closeList= new Gdiplus::Image*[43];
		for (int i = 1; i <= 43; i++)
		{
			std::wstring path = L"resource\\animation\\curten\\" + std::to_wstring(44 - i) + L".png";
			closeList[i - 1] = Gdiplus::Image::FromFile(path.c_str());
		}
		AniManager[0] = Animator("Ŀư�ݾ�", 0, 0, 1920, 1080, 1000, &closeList, false, true, 43);
		//Ŀư���� (1)
		Gdiplus::Image** openList = new Gdiplus::Image * [43];
		for (int i = 1; i <= 43; i++)
		{
			std::wstring path = L"resource\\animation\\curten\\" + std::to_wstring(i) + L".png";
			openList[i - 1] = Gdiplus::Image::FromFile(path.c_str());
		}
		AniManager[1] = Animator("Ŀư����", 0, 0, 1920, 1080, 2000, &openList, false, true, 43);
		
		//Ÿ��Ʋ
		Gdiplus::Image** titleList = new Gdiplus::Image * [180];
		for (int i = 1; i <= 180; i++)
		{
			std::wstring path = L"resource\\animation\\title\\" + std::to_wstring(i) + L".bmp";
			titleList[i - 1] = Gdiplus::Image::FromFile(path.c_str());
		}
		AniManager[2] = Animator("Ÿ��Ʋ", 0, 0, 1920, 1080, 6000, &titleList, true, false, 180);
		AniManager[2].SetAnimation();
	}
}
