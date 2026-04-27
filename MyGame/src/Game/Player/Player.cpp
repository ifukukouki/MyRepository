
#include "Player.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)

static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };
static const VECTOR START_POS{ SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, 0.0f };

//プレイヤーの移動速度
#define PLAYER_WALK_SPEED	(2.0f)

// 各アニメの画像数
#define WAIT_ANIME_IMG_NUM	(4)		// 待機アニメ
#define WALK_ANIME_ING_NUM	(12)	// 歩きアニメ

// 待機アニメ画像
#define WAIT_ANIME_IMG_0	"data/Player/Neko_Base_01.png"
#define WAIT_ANIME_IMG_1	"data/Player/Neko_Base_04.png"
#define WAIT_ANIME_IMG_2	"data/Player/Neko_Base_07.png"
#define WAIT_ANIME_IMG_3	"data/Player/Neko_Base_10.png"

// 歩きアニメ画像
#define WALK_ANIME_IMG_0	"data/Player/Neko_Base_00.png"
#define WALK_ANIME_IMG_1	"data/Player/Neko_Base_01.png"
#define WALK_ANIME_IMG_2	"data/Player/Neko_Base_02.png"
#define WALK_ANIME_IMG_3	"data/Player/Neko_Base_03.png"
#define WALK_ANIME_IMG_4	"data/Player/Neko_Base_04.png"
#define WALK_ANIME_IMG_5	"data/Player/Neko_Base_05.png"
#define WALK_ANIME_IMG_6	"data/Player/Neko_Base_06.png"
#define WALK_ANIME_IMG_7	"data/Player/Neko_Base_07.png"
#define WALK_ANIME_IMG_8	"data/Player/Neko_Base_08.png"
#define WALK_ANIME_IMG_9	"data/Player/Neko_Base_09.png"
#define WALK_ANIME_IMG_10	"data/Player/Neko_Base_10.png"
#define WALK_ANIME_IMG_11	"data/Player/Neko_Base_11.png"

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
	currentAnimeKind = AnimeKindWait;
	currentAnimeIndex = 0;

	// 時間をクリア
	currentAnimeTime = 0.0f;
}


void Player::Load()
{
	//待機アニメを読み込み
	animeImgHundle[AnimeKindWait][0] = LoadGraph(WAIT_ANIME_IMG_0);
	animeImgHundle[AnimeKindWait][1] = LoadGraph(WAIT_ANIME_IMG_1);
	animeImgHundle[AnimeKindWait][2] = LoadGraph(WAIT_ANIME_IMG_2);
	animeImgHundle[AnimeKindWait][3] = LoadGraph(WAIT_ANIME_IMG_3);
	animeUsedNum[AnimeKindWait] = WAIT_ANIME_IMG_NUM;

	//歩きアニメを読み込み
	animeImgHundle[AnimeKindWalk][0] = LoadGraph(WALK_ANIME_IMG_0);
	animeImgHundle[AnimeKindWalk][1] = LoadGraph(WALK_ANIME_IMG_1);
	animeImgHundle[AnimeKindWalk][2] = LoadGraph(WALK_ANIME_IMG_2);
	animeImgHundle[AnimeKindWalk][3] = LoadGraph(WALK_ANIME_IMG_3);
	animeImgHundle[AnimeKindWalk][4] = LoadGraph(WALK_ANIME_IMG_4);
	animeImgHundle[AnimeKindWalk][5] = LoadGraph(WALK_ANIME_IMG_5);
	animeImgHundle[AnimeKindWalk][6] = LoadGraph(WALK_ANIME_IMG_6);
	animeImgHundle[AnimeKindWalk][7] = LoadGraph(WALK_ANIME_IMG_7);
	animeImgHundle[AnimeKindWalk][8] = LoadGraph(WALK_ANIME_IMG_8);
	animeImgHundle[AnimeKindWalk][9] = LoadGraph(WALK_ANIME_IMG_9);
	animeImgHundle[AnimeKindWalk][10] = LoadGraph(WALK_ANIME_IMG_10);
	animeImgHundle[AnimeKindWalk][11] = LoadGraph(WALK_ANIME_IMG_11);
	animeUsedNum[AnimeKindWalk] = WALK_ANIME_ING_NUM;
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
		}
		// 右なら右へ移動
		else
		{
			m_pos.x += PLAYER_WALK_SPEED;
		}
		
		// もし現在待機のアニメをしているなら、
		if (currentAnimeKind == AnimeKindWait)
		{
			// 歩きアニメに変更する
			currentAnimeKind = AnimeKindWalk;
		}
	}
	// 上下どちらかが押されている
	if (InputKey::IsPushKeyLaw(KEY_INPUT_UP) || InputKey::IsPushKeyLaw(KEY_INPUT_DOWN) ||
		InputKey::IsPushKeyLaw(KEY_INPUT_W) || InputKey::IsPushKeyLaw(KEY_INPUT_S))
	{
		// 左なら左へ移動
		if (InputKey::IsPushKeyLaw(KEY_INPUT_UP) || InputKey::IsPushKeyLaw(KEY_INPUT_W))
		{
			m_pos.y -= PLAYER_WALK_SPEED;
		}
		// 右なら右へ移動
		else
		{
			m_pos.y += PLAYER_WALK_SPEED;
		}

		// もし現在待機のアニメをしているなら、
		if (currentAnimeKind == AnimeKindWait)
		{
			// 歩きアニメに変更する
			currentAnimeKind = AnimeKindWalk;
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


