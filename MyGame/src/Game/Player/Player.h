#pragma once

#include <DxLib.h>

// 各アニメで使える画像の最大数
#define ANIME_IMG_MAX	(3)

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

private:
	VECTOR m_pos;

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

