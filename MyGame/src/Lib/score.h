#pragma once

#include <DxLib.h>


#define NUMBER (10)			// 読み込む画像「0」～「9」

// スコア表示に必要な変数を集めた構造体
typedef struct {
	int m_hndl[NUMBER];	// 0～9の10個を管理
	int m_soundHndl;	// 効果音ハンドル
	int m_numScore;		// スコア
	int m_dispScore;	// 画面に表示されたスコア
}SCORE_DATA;

class Score
{
public:
	// 初期化
	static void Init();
	// ロード
	static void Load();
	// 更新処理
	static void Update();
	// 描画
	static void Draw();
	static void DrawResult();	// リザルトシーンで表示する用
	// 破棄
	static void Exit();

	// スコア加算
	static void AddScore(int score);
	// スコアセット
	void SetScore(int score);
	// スコア取得
	int GetScore();

private:
	static SCORE_DATA m_score;

};

