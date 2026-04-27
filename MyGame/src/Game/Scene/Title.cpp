
#include "Title.h"
#include "../../Lib/fade.h"
#include "../Sound/Sound.h"


//--------------------------------
// コンストラクタ
//--------------------------------
Title::Title() : m_hndl(-1)
{
	// 最初はデータ初期化
	m_state = INIT;
}


//--------------------------------
// コンストラクタ
//--------------------------------
Title::~Title()
{
}


//--------------------------------
// 初期化
//--------------------------------
int Title::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int result = -1;

	switch (m_state)
	{
	case Title::INIT:
		m_state = Title::LOAD;	// 次へ進む
		break;

	case Title::LOAD:
		m_hndl = LoadGraph("data/image/TITLE.jpg");

		// ゲーム本編のBGMを鳴らす					ループで鳴るように
		Sound::Play(Sound::BGM_TITLE, DX_PLAYTYPE_LOOP);

		// フェードイン開始
		RequestFadeIn();

		m_state = Title::STARTWAIT;	// 次へ進む
		break;

	case Title::STARTWAIT:
		if (IsEndFadeIn())
		{
			m_state = Title::MAIN;	// 次へ進む
		}
		break;

	case Title::MAIN:
		// エンターキーで次へ
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// フェードアウト開始
			RequestFadeOut();

			m_state = Title::ENDWAIT;	// 次へ進む
		}
		break;

	case Title::ENDWAIT:
		if (IsEndFadeOut())
		{
			m_state = Title::END;	// 次へ進む
		}
		break;

	case Title::END:
		// 全ての音楽を止めて次へ
		Sound::AllStop();

		if (m_hndl != -1)
		{
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}
		

		m_state = Title::INIT;	// 次へ進む
		result = 0;	// ゲームが終わったことを知らせる
		break;
	}

	// 本編が終了したかどうかを外部に伝える
	return result;
}


//--------------------------------
// 描画処理
//--------------------------------
void Title::Draw()
{
	switch (m_state)
	{
	case Title::STARTWAIT:
	case Title::MAIN:
	case Title::ENDWAIT:
		DrawRotaGraph(1280 / 2, 720 / 2, 1.0, 0.0, m_hndl, TRUE);
		DrawFormatString(585, 480, GetColor(255, 255, 255), "Press 'Enter'");
		DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトル");
		break;
	}
}

