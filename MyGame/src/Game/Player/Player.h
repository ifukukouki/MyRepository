#pragma once

#include <DxLib.h>

// 各アニメで使える画像の最大数
#define ANIME_IMG_MAX	(12)

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
		AnimeKindWait,	// 待機アニメ 0
		AnimeKindWalk,	// 歩きアニメ 1

		AnimeKindNum,		//アニメ数 2
	};

	//現在のアニメの種類
	AnimeKind currentAnimeKind;

	//現在のアニメ番号
	int currentAnimeIndex;

	//各アニメの画像ハンドル
	//↓は animeImgHundle[2][6]と書いてあるのと同じ
	int animeImgHundle[AnimeKindNum][ANIME_IMG_MAX];

	//各アニメの画像使用数
	int animeUsedNum[AnimeKindNum];

	//現在のアニメ時間
	float currentAnimeTime;
};

