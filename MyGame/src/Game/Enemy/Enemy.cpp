
#include "Enemy.h"
#include "../../Lib/input.h"


#define WAIT_COUNT	(60)	//敵再出現までにかかる時間（1秒６０フレーム）
#define ENEMY_SPEED	(3.0f)	//敵の移動速度

// 武器画像のファイルパス
#define WEAPON_IMG_PATH	"data/Enemy/character_monster_ghost_white.png"


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}


void Enemy::Init()
{
	m_hndl = -1;
	m_waitCount = 0;

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].m_pos = ZERO;
		m_enemy[i].m_isActive = false;
	}
}


void Enemy::Load()
{
	m_hndl = LoadGraph("");
}


void Enemy::Step()
{

}


void Enemy::Draw()
{

}


void Enemy::Exit()
{

}


