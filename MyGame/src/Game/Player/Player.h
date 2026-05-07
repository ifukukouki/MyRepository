#pragma once

#include <DxLib.h>

// 各アニメで使える画像の最大数
#define ANIME_IMG_MAX	(3)

// プレイヤー画像のサイズ
const int PLAYER_SIZE = 60;

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();

	// 移動後の座標を取得
	int GetNextPosX() { return m_nextPosX; }
	int GetNextPosY() { return m_nextPosY; }

	// 現在の座標を取得
	int GetPosX() { return m_pos.x; }
	int GetPosY() { return m_pos.y; }

	// 移動後の座標を設定
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posY);

	// 進んでいる方向をチェック
	// 上下左右の順になっている
	void GetMoveDirection(bool* _dirArray);

	// 座標を更新
	void UpdatePos();

private:
	VECTOR m_pos;

	// 移動後の座標
	int m_nextPosX;
	int m_nextPosY;

	// アニメの種類
	enum AnimeKind
	{
		AnimeKindWait1,	// 待機アニメ 1
		AnimeKindWait2,	// 待機アニメ 2
		AnimeKindWait3,	// 待機アニメ 3
		AnimeKindWait4,	// 待機アニメ 4
		AnimeKindWalk1,	// 歩きアニメ 1
		AnimeKindWalk2,	// 歩きアニメ 2
		AnimeKindWalk3,	// 歩きアニメ 3
		AnimeKindWalk4,	// 歩きアニメ 4

		AnimeKindNum,		//アニメ数 8
	};

	//現在のアニメの種類
	AnimeKind currentAnimeKind;

	//現在のアニメ番号
	int currentAnimeIndex;

	//各アニメの画像ハンドル
	//↓は animeImgHundle[5][3]と書いてあるのと同じ
	int animeImgHundle[AnimeKindNum][ANIME_IMG_MAX];

	//各アニメの画像使用数
	int animeUsedNum[AnimeKindNum];

	//現在のアニメ時間
	float currentAnimeTime;
};


