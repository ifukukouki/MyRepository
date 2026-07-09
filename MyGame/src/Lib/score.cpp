
#include "score.h"


// 定義関連
#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define NUMBER_SIZE_X (16)	// 数字画像のサイズ　横
#define NUMBER_SIZE_Y (32)	// 数字画像のサイズ　縦
#define DIGIT_NUMBER (10)	// 表示可能な桁数(今回は99999がカンスト)
#define ADD_KILLSCORE_SPD (10)	// 1フレームで加算されるスコア数
#define START_POS_X (650)	// スコア表示開始位置　横
#define START_POS_Y (20)	// スコア表示開始位置　縦
// 画像のパス
#define KILLSCORE_GRAPH_PATH ("data/Score/number16x32_01.png")


// staticメンバ変数はここで書く作業が必須！！----
SCORE_DATA Score::m_score;
//-----------------------------------------------


// 初期化
void Score::Init()
{
	for (int i = 0; i < NUMBER; i++)
	{
		m_score.m_hndl[i] = -1;
	}
	m_score.m_soundHndl = -1;
	m_score.m_numScore = 0;
	m_score.m_dispScore = 0;
}


// ロード
void Score::Load()
{
	// 10個の数字の画像をロード
	LoadDivGraph(KILLSCORE_GRAPH_PATH, NUMBER, NUMBER, 1,
		NUMBER_SIZE_X, NUMBER_SIZE_Y, m_score.m_hndl);
}


// 更新処理
void Score::Update()
{
	// 実際のスコアと表示用スコアが一致していたら何もしない
	if (m_score.m_numScore == m_score.m_dispScore)return;
	// 点数とっている感を出すために効果音を再生
	PlaySoundMem(m_score.m_soundHndl, DX_PLAYTYPE_BACK);
	// 注意！！ この関数は効果音の再生位置を設定する関数です
	// ちゃんと初めから再生されるデータを使っている人は不要です！
	SetCurrentPositionSoundMem(1000, m_score.m_soundHndl);

	// 表示用のスコアを一定の値だけ加算する
	m_score.m_dispScore += ADD_KILLSCORE_SPD;
	// 想定のスコアを表示用スコアがオーバーしたら同じにする
	if (m_score.m_dispScore>= m_score.m_numScore)
	{
		m_score.m_dispScore = m_score.m_numScore;
	}
}


// 描画
void Score::Draw()
{
	int tempKillScore = m_score.m_dispScore;
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		// 下一桁を取り出す
		int num = tempKillScore % 10;
		// 取り出した下一桁を正しい位置に表示
		DrawRotaGraph(START_POS_X - NUMBER_SIZE_X * i,
			START_POS_Y, 1.0, 0.0, m_score.m_hndl[num], TRUE);
		// 下一桁はいらないので削除する
		tempKillScore /= 10;

		//文字を表示
		DrawFormatString(450, 10, GetColor(255, 255, 255), "score");//x=1280 y=720
	}
}
// リザルトシーンで表示する用
void Score::DrawResult()
{
	int tempKillScore = m_score.m_dispScore;
	for (int i = 0; i < DIGIT_NUMBER; i++)
	{
		// 下一桁を取り出す
		int num = tempKillScore % 10;
		// 取り出した下一桁を正しい位置に表示
		DrawRotaGraph(START_POS_X - NUMBER_SIZE_X * i,
			START_POS_Y, 1.0, 0.0, m_score.m_hndl[num], TRUE);
		// 下一桁はいらないので削除する
		tempKillScore /= 10;

		//文字を表示
		DrawFormatString(450, 10, GetColor(255, 255, 255), "score");//x=1280 y=720
	}
}


// 破棄
void Score::Exit()
{
	// 画像データの削除
	for (int i = 0; i < NUMBER; i++)
	{
		if (m_score.m_hndl[i] != -1)
		{
			DeleteGraph(m_score.m_hndl[i]);
			m_score.m_hndl[i] = -1;
		}
	}
	// 効果音削除
	if (m_score.m_soundHndl != -1)
	{
		DeleteGraph(m_score.m_soundHndl);
		m_score.m_soundHndl = -1;
	}
}


// スコア加算
void Score::AddScore(int score)
{
	m_score.m_numScore += score;
}
// スコアセット
void Score::SetScore(int score)
{
	m_score.m_numScore = score;
	m_score.m_dispScore = score;
}
// スコア取得
int Score::GetScore()
{
	return m_score.m_numScore;
}