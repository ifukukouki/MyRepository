
#include "Player.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)

static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };
static const VECTOR START_POS{ SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, 0.0f };

//プレイヤーの移動速度
#define PLAYER_WALK_SPEED	(2.0f)

// 各アニメの画像数
#define WAIT_ANIME_IMG_NUM	(1)		// 待機アニメ
#define WALK_ANIME_ING_NUM	(3)		// 歩きアニメ

// 待機アニメ画像
#define WAIT_ANIME_IMG_0	"data/Player/Neko_Base_01.png"	// 正面
#define WAIT_ANIME_IMG_1	"data/Player/Neko_Base_04.png"	// 左
#define WAIT_ANIME_IMG_2	"data/Player/Neko_Base_07.png"	// 右
#define WAIT_ANIME_IMG_3	"data/Player/Neko_Base_10.png"	// 後ろ

// 歩きアニメ画像
#define WALK_ANIME_IMG_0	"data/Player/Neko_Base_00.png"	// 正面1
#define WALK_ANIME_IMG_1	"data/Player/Neko_Base_01.png"	// 正面2
#define WALK_ANIME_IMG_2	"data/Player/Neko_Base_02.png"	// 正面3
#define WALK_ANIME_IMG_3	"data/Player/Neko_Base_03.png"	// 左1
#define WALK_ANIME_IMG_4	"data/Player/Neko_Base_04.png"	// 左2
#define WALK_ANIME_IMG_5	"data/Player/Neko_Base_05.png"	// 左3
#define WALK_ANIME_IMG_6	"data/Player/Neko_Base_06.png"	// 右1
#define WALK_ANIME_IMG_7	"data/Player/Neko_Base_07.png"	// 右2
#define WALK_ANIME_IMG_8	"data/Player/Neko_Base_08.png"	// 右3
#define WALK_ANIME_IMG_9	"data/Player/Neko_Base_09.png"	// 後ろ1
#define WALK_ANIME_IMG_10	"data/Player/Neko_Base_10.png"	// 後ろ2
#define WALK_ANIME_IMG_11	"data/Player/Neko_Base_11.png"	// 後ろ3

//アニメの切り替わり速度（秒）
#define CHANGE_ANIME_TIME	(0.1f)


Player::Player() :m_pos(ZERO), animeImgHundle(), animeUsedNum(), currentAnimeKind(),
					currentAnimeIndex(0), currentAnimeTime(0.0f)
{
}
Player::~Player()
{
}


void Player::Init()
{
	m_pos = START_POS;

	// 開始アニメを設定
	currentAnimeKind = AnimeKindWait1;
	currentAnimeIndex = 0;

	// 時間をクリア
	currentAnimeTime = 0.0f;
}


void Player::Load()
{
	//待機アニメを読み込み
	animeImgHundle[AnimeKindWait1][0] = LoadGraph(WAIT_ANIME_IMG_0);
	animeImgHundle[AnimeKindWait2][0] = LoadGraph(WAIT_ANIME_IMG_1);
	animeImgHundle[AnimeKindWait3][0] = LoadGraph(WAIT_ANIME_IMG_2);
	animeImgHundle[AnimeKindWait4][0] = LoadGraph(WAIT_ANIME_IMG_3);
	animeUsedNum[AnimeKindWait1] = WAIT_ANIME_IMG_NUM;
	animeUsedNum[AnimeKindWait2] = WAIT_ANIME_IMG_NUM;
	animeUsedNum[AnimeKindWait3] = WAIT_ANIME_IMG_NUM;
	animeUsedNum[AnimeKindWait4] = WAIT_ANIME_IMG_NUM;

	//歩きアニメを読み込み
	animeImgHundle[AnimeKindWalk1][0] = LoadGraph(WALK_ANIME_IMG_0);
	animeImgHundle[AnimeKindWalk1][1] = LoadGraph(WALK_ANIME_IMG_1);
	animeImgHundle[AnimeKindWalk1][2] = LoadGraph(WALK_ANIME_IMG_2);
	animeImgHundle[AnimeKindWalk2][0] = LoadGraph(WALK_ANIME_IMG_3);
	animeImgHundle[AnimeKindWalk2][1] = LoadGraph(WALK_ANIME_IMG_4);
	animeImgHundle[AnimeKindWalk2][2] = LoadGraph(WALK_ANIME_IMG_5);
	animeImgHundle[AnimeKindWalk3][0] = LoadGraph(WALK_ANIME_IMG_6);
	animeImgHundle[AnimeKindWalk3][1] = LoadGraph(WALK_ANIME_IMG_7);
	animeImgHundle[AnimeKindWalk3][2] = LoadGraph(WALK_ANIME_IMG_8);
	animeImgHundle[AnimeKindWalk4][0] = LoadGraph(WALK_ANIME_IMG_9);
	animeImgHundle[AnimeKindWalk4][1] = LoadGraph(WALK_ANIME_IMG_10);
	animeImgHundle[AnimeKindWalk4][2] = LoadGraph(WALK_ANIME_IMG_11);
	animeUsedNum[AnimeKindWalk1] = WALK_ANIME_ING_NUM;
	animeUsedNum[AnimeKindWalk2] = WALK_ANIME_ING_NUM;
	animeUsedNum[AnimeKindWalk3] = WALK_ANIME_ING_NUM;
	animeUsedNum[AnimeKindWalk4] = WALK_ANIME_ING_NUM;
}


void Player::Step()
{
	// プレイヤーの移動
// 左右どちらかが押されている
	if (InputKey::IsPushKeyLaw(KEY_INPUT_LEFT) || InputKey::IsPushKeyLaw(KEY_INPUT_RIGHT) ||
		InputKey::IsPushKeyLaw(KEY_INPUT_A) || InputKey::IsPushKeyLaw(KEY_INPUT_D))
	{
		// 左なら左へ移動
		if (InputKey::IsPushKeyLaw(KEY_INPUT_LEFT) || InputKey::IsPushKeyLaw(KEY_INPUT_A))
		{
			m_pos.x -= PLAYER_WALK_SPEED;

			// もし現在待機のアニメをしているなら、
			if (currentAnimeKind == AnimeKindWait1 || currentAnimeKind == AnimeKindWait2 ||
				currentAnimeKind == AnimeKindWait3 || currentAnimeKind == AnimeKindWait4)
			{
				// 歩きアニメに変更する
				currentAnimeKind = AnimeKindWalk2;
			}
		}
		// 右なら右へ移動
		else if (InputKey::IsPushKeyLaw(KEY_INPUT_RIGHT) || InputKey::IsPushKeyLaw(KEY_INPUT_D))
		{
			m_pos.x += PLAYER_WALK_SPEED;

			// もし現在待機のアニメをしているなら、
			if (currentAnimeKind == AnimeKindWait1 || currentAnimeKind == AnimeKindWait2 ||
				currentAnimeKind == AnimeKindWait3 || currentAnimeKind == AnimeKindWait4)
			{
				// 歩きアニメに変更する
				currentAnimeKind = AnimeKindWalk3;
			}
		}
	}
	// 左右どちらも押されていない
	else
	{
		// もし現在歩きアニメをしているなら
		if (currentAnimeKind == AnimeKindWalk2)
		{
			// 待機アニメに変更する
			currentAnimeKind = AnimeKindWait2;
		}
		else if (currentAnimeKind == AnimeKindWalk3)
		{
			currentAnimeKind = AnimeKindWait3;
		}
	}

	// 上下どちらかが押されている
	if (InputKey::IsPushKeyLaw(KEY_INPUT_UP) || InputKey::IsPushKeyLaw(KEY_INPUT_DOWN) ||
		InputKey::IsPushKeyLaw(KEY_INPUT_W) || InputKey::IsPushKeyLaw(KEY_INPUT_S))
	{
		// 上なら上へ移動
		if (InputKey::IsPushKeyLaw(KEY_INPUT_UP) || InputKey::IsPushKeyLaw(KEY_INPUT_W))
		{
			m_pos.y -= PLAYER_WALK_SPEED;

			// もし現在待機のアニメをしているなら、
			if (currentAnimeKind == AnimeKindWait1 || currentAnimeKind == AnimeKindWait2 ||
				currentAnimeKind == AnimeKindWait3 || currentAnimeKind == AnimeKindWait4)
			{
				// 歩きアニメに変更する
				currentAnimeKind = AnimeKindWalk4;
			}
		}
		// 下なら下へ移動
		else if (InputKey::IsPushKeyLaw(KEY_INPUT_DOWN) || InputKey::IsPushKeyLaw(KEY_INPUT_S))
		{
			m_pos.y += PLAYER_WALK_SPEED;
			// もし現在待機のアニメをしているなら、
			if (currentAnimeKind == AnimeKindWait1 || currentAnimeKind == AnimeKindWait2 ||
				currentAnimeKind == AnimeKindWait3 || currentAnimeKind == AnimeKindWait4)
			{
				// 歩きアニメに変更する
				currentAnimeKind = AnimeKindWalk1;
			}
		}
	}
	// 上下どちらも押されていない
	else
	{
		// もし現在歩きアニメをしているなら
		if (currentAnimeKind == AnimeKindWalk4)
		{
			// 待機アニメに変更する
			currentAnimeKind = AnimeKindWait4;
		}
		else if (currentAnimeKind == AnimeKindWalk1)
		{
			currentAnimeKind = AnimeKindWait1;
		}
	}

	// アニメ時間を加算
	currentAnimeTime += 1.0f / 60;

	// アニメ切り替え時間を過ぎた
	if (currentAnimeTime >= CHANGE_ANIME_TIME)
	{
		// 時間をリセット
		currentAnimeTime = 0;
		// ★ココに↑の処理

		// アニメの画像番号を進める
		currentAnimeIndex++;
		// ★ココに↑の処理

		// 次のアニメが無いなら（現在のアニメ画像番号が最後なら）
		if (currentAnimeIndex >= animeUsedNum[currentAnimeKind])
		{
			// 最初のアニメ画像に戻す（ループさせる）
			currentAnimeIndex = 0;
			// ★ココに↑の処理
		}
	}
}


void Player::Draw()
{
	AnimeKind current_anime = currentAnimeKind;
	int current_index = currentAnimeIndex;

	DrawRotaGraph((int)m_pos.x, (int)m_pos.y, 1.0, 0.0,
		animeImgHundle[current_anime][current_index], true);
}


void Player::Exit()
{
	// アニメ種類の数ループ
	for (int anime_kind_index = 0; anime_kind_index < AnimeKindNum; anime_kind_index++)
	{
		// アニメ画像の数ループ
		for (int image_index = 0; image_index < ANIME_IMG_MAX; image_index++)
		{
			// 各アニメ画像を破棄
			DeleteGraph(animeImgHundle[anime_kind_index][image_index]);
		}
	}
}


