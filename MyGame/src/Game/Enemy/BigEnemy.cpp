
#include "BigEnemy.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define BIGENEMY_IMG_PATH	"data/Enemy/character_monster_ghost_black.png"	// 敵画像のファイルパス
#define BIGENEMY_SPEED (0.5f)	// 敵の移動速度
#define WAIT_COUNT (300)		// 敵再出現までにかかる時間（１秒＝６０フレーム）


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


BigEnemy::BigEnemy() :m_hndl(-1), m_waitCount(0), m_requestFlg(0), m_enemy()
{
}
BigEnemy::~BigEnemy()
{
}


// 初期化
void BigEnemy::Init()
{
	m_waitCount = WAIT_COUNT;
	m_requestFlg = 1;
	for (int i = 0; i < BIGENEMY_MAX; i++)
	{
		m_enemy[i].m_pos = ZERO;
		m_enemy[i].m_dir = ZERO;
		m_enemy[i].m_isActive = false;
	}
}


// 画像ロード
void BigEnemy::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph(BIGENEMY_IMG_PATH);
	}
}


// 毎フレーム処理
void BigEnemy::Step(VECTOR playerPos)
{
	for (int i = 0; i < BIGENEMY_MAX; i++)
	{
		if (m_enemy[i].m_isActive == false)
		{
			continue;
		}

		// プレイヤーを追いかける処理-------------------------------
		m_enemy[i].m_dir = VSub(playerPos, m_enemy[i].m_pos);
		m_enemy[i].m_dir.z = 0.0f;
		m_enemy[i].m_dir = VNorm(m_enemy[i].m_dir);
		m_enemy[i].m_dir = VScale(m_enemy[i].m_dir, BIGENEMY_SPEED);
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
	switch (m_requestFlg)
	{
	case 1:
		Request1();
		break;

	case 2:
		Request2();
		break;

	case 3:
		Request3();
		break;

	case 4:
		Request4();
		break;
	}	
}


// 描画処理
void BigEnemy::Draw()
{
	for (int i = 0; i < BIGENEMY_MAX; i++)
	{
		if (m_enemy[i].m_isActive == true)
		{
			DrawRotaGraph(m_enemy[i].m_pos.x, m_enemy[i].m_pos.y, 0.05, 0.0, m_hndl, true);

			// 当たり判定表示
			//DrawCircle(m_enemy[i].m_pos.x, m_enemy[i].m_pos.y, 28, GetColor(255, 0, 0), false);
		}
	}
}


// 終了処理
void BigEnemy::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}


// 敵を呼び出す
// 上から出現
bool BigEnemy::Request1()
{
	if (m_waitCount < 0)
	{
		for (int i = 0; i < BIGENEMY_MAX; i++)
		{
			if (m_enemy[i].m_isActive == true)
			{
				continue;
			}

			m_enemy[i].m_isActive = true;
			m_enemy[i].m_pos.x = (float)GetRand(1280) - 0.0f;
			m_enemy[i].m_pos.y = 10.0f;

			m_waitCount = WAIT_COUNT;
			// 敵の出現場所を変更する(0にならないように+1をする)
			m_requestFlg = GetRand(3) + 1;
			break;
		}
	}
	return true;
}
// 下から出現
bool BigEnemy::Request2()
{
	if (m_waitCount < 0)
	{
		for (int i = 0; i < BIGENEMY_MAX; i++)
		{
			if (m_enemy[i].m_isActive == true)
			{
				continue;
			}

			m_enemy[i].m_isActive = true;
			m_enemy[i].m_pos.x = (float)GetRand(1280) - 0.0f;
			m_enemy[i].m_pos.y = 630.0f;

			m_waitCount = WAIT_COUNT;
			// 敵の出現場所を変更する(0にならないように+1をする)
			m_requestFlg = GetRand(3) + 1;
			break;
		}
	}
	return true;
}
// 左から出現
bool BigEnemy::Request3()
{
	if (m_waitCount < 0)
	{
		for (int i = 0; i < BIGENEMY_MAX; i++)
		{
			if (m_enemy[i].m_isActive == true)
			{
				continue;
			}

			m_enemy[i].m_isActive = true;
			m_enemy[i].m_pos.x = 10.0f;
			m_enemy[i].m_pos.y = (float)GetRand(640) - 0.0f;

			m_waitCount = WAIT_COUNT;
			// 敵の出現場所を変更する(0にならないように+1をする)
			m_requestFlg = GetRand(3) + 1;
			break;
		}
	}
	return true;
}
// 右から出現
bool BigEnemy::Request4()
{
	if (m_waitCount < 0)
	{
		for (int i = 0; i < BIGENEMY_MAX; i++)
		{
			if (m_enemy[i].m_isActive == true)
			{
				continue;
			}

			m_enemy[i].m_isActive = true;
			m_enemy[i].m_pos.x = 1270.0f;
			m_enemy[i].m_pos.y = (float)GetRand(640) - 0.0f;

			m_waitCount = WAIT_COUNT;
			// 敵の出現場所を変更する(0にならないように+1をする)
			m_requestFlg = GetRand(3) + 1;
			break;
		}
	}
	return true;
}

