
#include "BossEnemy.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define BOSSENEMY_IMG_PATH	"data/Enemy/character_monster_hana_02.png"	// 敵画像のファイルパス
#define BOSSENEMY_SPEED (0.2f)	// 敵の移動速度
#define WAIT_COUNT (600)		// 敵再出現までにかかる時間（１秒＝６０フレーム）


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };
static const int HP = 100;


BossEnemy::BossEnemy() :m_hndl(-1), m_waitCount(0), m_enemy()
{
}
BossEnemy::~BossEnemy()
{
}


// 初期化
void BossEnemy::Init()
{
	m_waitCount = 600;
	for (int i = 0; i < BOSSENEMY_MAX; i++)
	{
		m_enemy[i].m_pos = ZERO;
		m_enemy[i].m_dir = ZERO;
		m_enemy[i].m_isActive = false;
		m_enemy[i].m_hp = HP;
	}
}


// 画像ロード
void BossEnemy::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph(BOSSENEMY_IMG_PATH);
	}
}


// 毎フレーム処理
void BossEnemy::Step(VECTOR playerPos)
{
	for (int i = 0; i < BOSSENEMY_MAX; i++)
	{
		if (m_enemy[i].m_isActive == false)
		{
			continue;
		}

		// プレイヤーを追いかける処理-------------------------------
		m_enemy[i].m_dir = VSub(playerPos, m_enemy[i].m_pos);
		m_enemy[i].m_dir.z = 0.0f;
		m_enemy[i].m_dir = VNorm(m_enemy[i].m_dir);
		m_enemy[i].m_dir = VScale(m_enemy[i].m_dir, BOSSENEMY_SPEED);
		m_enemy[i].m_pos = VAdd(m_enemy[i].m_pos, m_enemy[i].m_dir);
		//----------------------------------------------------------

		// 弾を発射する処理============================================
		m_bossEnemyWeapon.Step(m_enemy[i].m_pos.x, m_enemy[i].m_pos.y);
		//=============================================================

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
void BossEnemy::Draw()
{
	for (int i = 0; i < BOSSENEMY_MAX; i++)
	{
		if (m_enemy[i].m_isActive == true && m_enemy[i].m_hp >= 1)
		{
			DrawRotaGraph(m_enemy[i].m_pos.x, m_enemy[i].m_pos.y, 0.1, 0.0, m_hndl, true);

			// 当たり判定表示
			DrawCircle(m_enemy[i].m_pos.x, m_enemy[i].m_pos.y, 28, GetColor(255, 0, 0), false);
		}
	}
}


// 終了処理
void BossEnemy::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}


// 敵を呼び出す
// 上から出現
bool BossEnemy::Request()
{
	if (m_waitCount < 0)
	{
		for (int i = 0; i < BOSSENEMY_MAX; i++)
		{
			if (m_enemy[i].m_isActive == true)
			{
				continue;
			}

			m_enemy[i].m_isActive = true;
			m_enemy[i].m_pos.x = (float)GetRand(1280) - 0.0f;
			m_enemy[i].m_pos.y = 10.0f;

			m_waitCount = WAIT_COUNT;
			break;
		}
	}
	return true;
}

