
#include "Play.h"
#include "../../Lib/fade.h"
#include "../Sound/Sound.h"
#include "../../Lib/collision.h"


//定義関連-----------------------------
#define END_WAIT (60)	//プレイヤーが死んだ後の待ち時間
//-------------------------------------

static const char BOSS_MODEL_PATH[] = "data/model/enemy/boss.mv1";		// bossモデル
static const char ENEMY_MODEL_PATH[] = "data/model/enemy/enemy.mv1";	// enemyモデル
static const char STRONGENEMY_MODEL_PATH[] = "data/model/enemy/strongenemy.mv1";	// strongenemyモデル

//--------------------------------
// コンストラクタ
//--------------------------------
Play::Play()
{
	// 最初はデータ初期化
	m_state = INIT;
}

//--------------------------------
// デストラクタ
//--------------------------------
Play::~Play()
{
	// 安全のためにデータ破棄処理を呼び出し
	Exit();
}


//--------------------------------
// 初期化
//--------------------------------
int Play::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int result = -1;

	switch (m_state)
	{
	case Play::INIT:
		Init();
		m_state = Play::LOAD;	// 次へ進む
		break;

	case Play::LOAD:
		Load();
		// ゲーム本編のBGMを鳴らす					ループで鳴るように
		Sound::Play(Sound::BGM_GAME, DX_PLAYTYPE_LOOP);

		// フェードイン開始
		RequestFadeIn();

		m_state = Play::STARTWAIT;	// 次へ進む
		break;

	case Play::STARTWAIT:
		if (IsEndFadeIn())
		{
			m_state = Play::MAIN;	// 次へ進む
		}
		break;

	case Play::MAIN:
		Step();
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// フェードアウト開始
			RequestFadeOut();

			m_state = Play::ENDWAIT;	// 次へ進む
		}
		break;

	case Play::ENDWAIT:
		if (IsEndFadeOut())
		{
			m_state = Play::END;	// 次へ進む
		}
		break;

	case Play::END:
		Exit();
		// 全ての音楽を止めて次へ
		Sound::AllStop();
		m_state = Play::INIT;	// 次へ進む
		result = 0;	// ゲームが終わったことを知らせる
		break;

	default:
		break;
	}

	// 本編が終了したかどうかを外部に伝える
	return result;
}


//--------------------------------
// 描画処理
//--------------------------------
void Play::Draw()
{
	m_map.DrawMap();
}


//--------------------------------
// 初期化
//--------------------------------
void Play::Init()
{
	m_map.InitMap();
}


//--------------------------------
// データロード
//--------------------------------
void Play::Load()
{
	m_map.LoadMap();
}


//--------------------------------
// メイン処理
//--------------------------------
void Play::Step()
{
	
}


//--------------------------------
// 終了前処理
//--------------------------------
void Play::Exit()
{
	m_map.FinMap();
}

