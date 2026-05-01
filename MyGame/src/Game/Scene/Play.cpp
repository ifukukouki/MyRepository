
#include "Play.h"
#include "../../Lib/fade.h"
#include "../Sound/Sound.h"
#include "../../Lib/collision.h"




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
	m_player.Draw();
}


//--------------------------------
// 初期化
//--------------------------------
void Play::Init()
{
	m_map.InitMap();
	m_player.Init();
}


//--------------------------------
// データロード
//--------------------------------
void Play::Load()
{
	m_map.LoadMap();
	m_player.Load();
}


//--------------------------------
// メイン処理
//--------------------------------
void Play::Step()
{
	m_player.Step();
}


//--------------------------------
// 終了前処理
//--------------------------------
void Play::Exit()
{
	m_map.FinMap();
	m_player.Exit();
}


//--------------------------------
// マップの当たり判定
//--------------------------------
void Play::MapCollision()
{

	// Y方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAP_CHIP_Y_NUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_CHIP_X_NUM; mapIndexX++)
		{
			// ブロック以外は処理しない
			if (m_map.isReadFile) {
				if (m_map.m_FileReadMapData[mapIndexY][mapIndexX] == 0)
					continue;
			}
			else {
				if (m_map.m_mapData[mapIndexY][mapIndexX] == 0)
					continue;
			}

			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。
			bool dirArray[4] = { false,false,false,false };
			m_player.GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			int Ax = m_player.GetPosX();
			int Ay = m_player.GetPosY();
			int Aw = PLAYER_SIZE;
			int Ah = PLAYER_SIZE;

			// オブジェクトの情報
			int Bx = mapIndexX * MAP_SIZE;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ※Y方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = m_player.GetNextPosY();
			Ax = m_player.GetPosX();

			// 当たっているかチェック
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				// 上方向の修正
				if (dirArray[0]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = By + Bh - Ay;
					m_player.SetNextPosY(Ay + overlap);
				}

				// 下方向の修正
				if (dirArray[1]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = Ay + Ah - By;
					m_player.SetNextPosY(Ay - overlap);
				}
			}
		}
	}

	// X方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAP_CHIP_Y_NUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAP_CHIP_X_NUM; mapIndexX++)
		{
			// ブロック以外は処理しない
			if (m_map.m_mapData[mapIndexY][mapIndexX] == 0)
				continue;

			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。
			bool dirArray[4] = { false,false,false,false };
			m_player.GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			int Ax = m_player.GetPosX();
			int Ay = m_player.GetPosY();
			int Aw = PLAYER_SIZE;
			int Ah = PLAYER_SIZE;

			// オブジェクトの情報
			int Bx = mapIndexX * MAP_SIZE;
			int By = mapIndexY * MAP_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// ※X方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = m_player.GetNextPosY();
			Ax = m_player.GetNextPosX();

			// 当たっているかチェック
			if (IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {

				// 左方向の修正
				if (dirArray[2]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = Bx + Bw - Ax;
					m_player.SetNextPosX(Ax + overlap);
				}

				// 右方向の修正
				if (dirArray[3]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = Ax + Aw - Bx;
					m_player.SetNextPosX(Ax - overlap);
				}
			}
		}
	}
}

// 2つの座標がか重なっている量を取得
int Play::GetOverlap(int posA, int posB)
{
	int ret = posA - posB;
	return abs(ret);
}




