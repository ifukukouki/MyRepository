
#include "BossEnemyWeapon.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define BOSSENEMY_WEAPON_SPEED (1.0f)	// 武器の移動速度
#define BOSSENEMY_WEAPON_IMG_PATH	"data/Enemy/crystal_sphere_red.png"	// 武器画像のファイルパス
#define WAIT_COUNT (300)	// 弾発射までにかかる時間（１秒＝６０フレーム）


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


BossEnemyWeapon::BossEnemyWeapon() :m_hndl(-1), m_waitcount(0), m_weapon_up(), m_weapon_down(), m_weapon_left(), m_weapon_right()
{
}
BossEnemyWeapon::~BossEnemyWeapon()
{
}


// 初期化
void BossEnemyWeapon::Init()
{
	m_waitcount = WAIT_COUNT;
	for (int i = 0; i < BOSSENEMY_WEAPON_MAX; i++)
	{
		m_weapon_up[i].m_angle = 0.0f;
		m_weapon_up[i].m_isActive = false;

		m_weapon_down[i].m_angle = 0.0f;
		m_weapon_down[i].m_isActive = false;

		m_weapon_left[i].m_angle = 0.0f;
		m_weapon_left[i].m_isActive = false;

		m_weapon_right[i].m_angle = 0.0f;
		m_weapon_right[i].m_isActive = false;
	}
}


// 画像ロード
void BossEnemyWeapon::Load()
{
	m_hndl = LoadGraph(BOSSENEMY_WEAPON_IMG_PATH);
}


// 毎フレーム処理
void BossEnemyWeapon::Step(int bossPosX, int bossPosY, bool isActive)
{
	m_waitcount -= 1;
	if (m_waitcount <= 0 && isActive == true)
	{
		for (int i = 0; i < BOSSENEMY_WEAPON_MAX; i++)
		{
			if (m_weapon_up[i].m_isActive == false && m_weapon_down[i].m_isActive == false &&
				m_weapon_left[i].m_isActive == false && m_weapon_right[i].m_isActive == false)
			{
				m_weapon_up[i].m_isActive = true;
				m_weapon_up[i].m_pos.x = bossPosX;
				m_weapon_up[i].m_pos.y = bossPosY;

				m_weapon_down[i].m_isActive = true;
				m_weapon_down[i].m_pos.x = bossPosX;
				m_weapon_down[i].m_pos.y = bossPosY;

				m_weapon_left[i].m_isActive = true;
				m_weapon_left[i].m_pos.x = bossPosX;
				m_weapon_left[i].m_pos.y = bossPosY;

				m_weapon_right[i].m_isActive = true;
				m_weapon_right[i].m_pos.x = bossPosX;
				m_weapon_right[i].m_pos.y = bossPosY;

				break;
			}
		}

		m_waitcount = WAIT_COUNT;
	}
}


// 画像描画
void BossEnemyWeapon::Draw()
{
	for (int i = 0; i < BOSSENEMY_WEAPON_MAX; i++)
	{
		// フラグがオンなら描画
		if (m_weapon_up[i].m_isActive == true)
		{
			DrawRotaGraph(m_weapon_up[i].m_pos.x, m_weapon_up[i].m_pos.y, 0.05, m_weapon_up[i].m_angle, m_hndl, true);
		
			// 当たり判定表示
			//DrawCircle(m_weapon_up[i].m_pos.x, m_weapon_up[i].m_pos.y, 16, GetColor(255, 0, 0), false);
		}

		if (m_weapon_down[i].m_isActive == true)
		{
			DrawRotaGraph(m_weapon_down[i].m_pos.x, m_weapon_down[i].m_pos.y, 0.05, m_weapon_down[i].m_angle, m_hndl, true);
		}

		if (m_weapon_left[i].m_isActive == true)
		{
			DrawRotaGraph(m_weapon_left[i].m_pos.x, m_weapon_left[i].m_pos.y, 0.05, m_weapon_left[i].m_angle, m_hndl, true);
		}

		if (m_weapon_right[i].m_isActive == true)
		{
			DrawRotaGraph(m_weapon_right[i].m_pos.x, m_weapon_right[i].m_pos.y, 0.05, m_weapon_right[i].m_angle, m_hndl, true);
		}
	}
}


// 終了処理
void BossEnemyWeapon::Exit()
{
	// 画像を破棄
	DeleteGraph(m_hndl);
}


// 上に飛ぶ処理
void BossEnemyWeapon::UpShot(int i)
{
	if (m_weapon_up[i].m_isActive == true)
	{
		m_weapon_up[i].m_pos.y -= BOSSENEMY_WEAPON_SPEED;
		if (m_weapon_up[i].m_pos.y < 0)
		{
			m_weapon_up[i].m_isActive = false;
		}
	}
}
// 下に飛ぶ処理
void BossEnemyWeapon::DownShot(int i)
{
	if (m_weapon_down[i].m_isActive == true)
	{
		m_weapon_down[i].m_pos.y += BOSSENEMY_WEAPON_SPEED;
		if (m_weapon_down[i].m_pos.y > SCREEN_SIZE_Y)
		{
			m_weapon_down[i].m_isActive = false;
		}
	}
}
// 左に飛ぶ処理
void BossEnemyWeapon::LeftShot(int i)
{
	if (m_weapon_left[i].m_isActive == true)
	{
		m_weapon_left[i].m_pos.x -= BOSSENEMY_WEAPON_SPEED;
		if (m_weapon_left[i].m_pos.x < 0)
		{
			m_weapon_left[i].m_isActive = false;
		}
	}
}
// 右に飛ぶ処理
void BossEnemyWeapon::RightShot(int i)
{
	if (m_weapon_right[i].m_isActive == true)
	{
		m_weapon_right[i].m_pos.x += BOSSENEMY_WEAPON_SPEED;
		if (m_weapon_right[i].m_pos.x > SCREEN_SIZE_X)
		{
			m_weapon_right[i].m_isActive = false;
		}
	}
}




