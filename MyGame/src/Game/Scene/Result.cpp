
#include "Result.h"
#include "../../Lib/fade.h"
#include "../Sound/Sound.h"


//--------------------------------
// コンストラクタ
//--------------------------------
Result::Result() : m_hndl(-1)
{
	// 最初はデータ初期化
	m_state = INIT;
}


//--------------------------------
// コンストラクタ
//--------------------------------
Result::~Result()
{
}


//--------------------------------
// 初期化
//--------------------------------
int Result::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int result = -1;

	switch (m_state)
	{
	case Result::INIT:
		m_state = Result::LOAD;	// 次へ進む
		break;

	case Result::LOAD:
		m_hndl = LoadGraph("data/image/RESULT.jpg");

		// ゲーム本編のBGMを鳴らす					ループで鳴るように
		Sound::Play(Sound::BGM_RESULT, DX_PLAYTYPE_LOOP);

		// フェードイン開始
		RequestFadeIn();

		m_state = Result::STARTWAIT;	// 次へ進む
		break;

	case Result::STARTWAIT:
		if (IsEndFadeIn())
		{
			m_state = Result::MAIN;	// 次へ進む
		}
		break;

	case Result::MAIN:
		// エンターキーで次へ
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// フェードアウト開始
			RequestFadeOut();

			m_state = Result::ENDWAIT;	// 次へ進む
		}
		break;

	case Result::ENDWAIT:
		if (IsEndFadeOut())
		{
			m_state = Result::END;	// 次へ進む
		}
		break;

	case Result::END:
		// 全ての音楽を止めて次へ
		Sound::AllStop();

		if (m_hndl != -1)
		{
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}

		m_state = Result::INIT;	// 次へ進む
		result = 0;	// ゲームが終わったことを知らせる
		break;
	}

	// 本編が終了したかどうかを外部に伝える
	return result;
}


//--------------------------------
// 描画処理
//--------------------------------
void Result::Draw()
{
	switch (m_state)
	{
	case Result::STARTWAIT:
	case Result::MAIN:
	case Result::ENDWAIT:
		DrawRotaGraph(1280 / 2, 720 / 2, 1.0, 0.0, m_hndl, TRUE);
		DrawFormatString(585, 480, GetColor(255, 255, 255), "Press 'Enter'");
		DrawFormatString(0, 0, GetColor(255, 255, 255), "リザルト");
		break;
	}
}

