
#include "Enemy.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define ENEMY_IMG_PATH	"data/Enemy/character_monster_ghost_white.png"	// “G‰æ‘œ‚Ìƒtƒ@ƒCƒ‹ƒpƒX


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };
static const float ROT_Y = 0.0f;


Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}


void Enemy::Init()
{
	m_pos = ZERO;
	m_speed = ZERO;
	m_dir = ZERO;
	m_rotY;
	m_hndl;
	m_isActive;

}


void Enemy::Load()
{
	m_hndl = LoadGraph(ENEMY_IMG_PATH);
}


void Enemy::Step()
{
	
}


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


void Enemy::Exit()
{
	DeleteGraph(m_hndl);	
}


bool Enemy::Request(const VECTOR& pos, const VECTOR& speed)
{
	// ‚·‚Å‚ÉoŒ»‚³‚ê‚Ä‚¢‚é“G‚Í¶¬Ž¸”s
	if (m_isActive) return false;

	// •K—v‚Èî•ñ‚ð“n‚µ‚Ä‚¢‚­
	m_isActive = true;
	m_pos = pos;
	m_speed = speed;

	return true;
}





