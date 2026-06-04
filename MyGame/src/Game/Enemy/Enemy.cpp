
#include "Enemy.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define ENEMY_IMG_PATH	"data/Enemy/character_monster_ghost_white.png"	// 敵画像のファイルパス
#define ENEMY_SPEED (0.5f)		// 敵の移動速度
#define WAIT_COUNT (60)			// 敵再出現までにかかる時間（1秒６０フレーム）


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


Enemy::Enemy() :m_hndl(-1), m_waitCount(0), m_enemy()
{
}
Enemy::~Enemy()
{
}


// 初期化
void Enemy::Init()
{
	m_hndl = -1;
	m_waitCount = 0;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].m_pos = ZERO;
		m_enemy[i].m_dir = ZERO;
		m_enemy[i].m_isActive = false;
	}
}


// 画像ロード
void Enemy::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph(ENEMY_IMG_PATH);
	}
}


// 毎フレーム処理
void Enemy::Step(VECTOR playerPos)
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (m_enemy[i].m_isActive == false)
		{
			continue;
		}

		// プレイヤーを追いかける処理-------------------------------
		m_enemy[i].m_dir = VSub(playerPos, m_enemy[i].m_pos);
		m_enemy[i].m_dir.z = 0.0f;
		m_enemy[i].m_dir = VNorm(m_enemy[i].m_dir);
		m_enemy[i].m_dir = VScale(m_enemy[i].m_dir, ENEMY_SPEED);
		m_enemy[i].m_pos = VAdd(m_enemy[i].m_pos, m_enemy[i].m_dir);
		//----------------------------------------------------------

		// 画面外に出たら消す
		if (m_enemy[i].m_pos.x < 0.0f || m_enemy[i].m_pos.x > SCREEN_SIZE_X ||
			m_enemy[i].m_pos.y < 0.0f || m_enemy[i].m_pos.y > SCREEN_SIZE_Y)
		{
			m_enemy[i].m_isActive = false;
		}
	}
	m_waitCount--;
	Request();
}


// 描画処理
void Enemy::Draw()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (m_enemy[i].m_isActive == true)
		{
			DrawRotaGraph(m_enemy[i].m_pos.x, m_enemy[i].m_pos.y, 0.05, 0.0, m_hndl, true);
		}
	}
}


// 終了処理
void Enemy::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}


// 敵を呼び出す
bool Enemy::Request()
{
	if (m_waitCount < 0)
	{
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (m_enemy[i].m_isActive == true)
			{
				continue;
			}

			m_enemy[i].m_isActive = true;
			m_enemy[i].m_pos.x = (float)GetRand(1280) - 0.0f;
			m_enemy[i].m_pos.y = 10;

			m_waitCount = WAIT_COUNT;
			break;
		}
	}
	return true;
}


