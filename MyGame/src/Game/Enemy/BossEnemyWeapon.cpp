
#include "BossEnemyWeapon.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define BOSSENEMY_WEAPON_SPEED (3.5f)	// 武器の移動速度
#define BOSSENEMY_WEAPON_IMG_PATH	"data/Enemy/crystal_sphere_red.png"	// 武器画像のファイルパス


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


BossEnemyWeapon::BossEnemyWeapon()
{
}
BossEnemyWeapon::~BossEnemyWeapon()
{
}


// 初期化
void BossEnemyWeapon::Init()
{
	m_hndl = -1;
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
void BossEnemyWeapon::Step(int bossPosX, int bossPosY)
{
	for (int i = 0; i < BOSSENEMY_WEAPON_MAX; i++)
	{
		// 生存フラグを確認しプレイヤーのアニメーションで撃つ方向を決める
		// 上方向
		if (m_weapon_up[i].m_isActive == false)
		{
			m_weapon_up[i].m_isActive = true;
			m_weapon_up[i].m_pos.x = bossPosX;
			m_weapon_up[i].m_pos.y = bossPosY;

			break;
		}

		// 下方向
		if (m_weapon_down[i].m_isActive == false)
		{
			m_weapon_down[i].m_isActive = true;
			m_weapon_down[i].m_pos.x = bossPosX;
			m_weapon_down[i].m_pos.y = bossPosY;

			break;
		}

		// 左方向
		if (m_weapon_left[i].m_isActive == false)
		{
			m_weapon_left[i].m_isActive = true;
			m_weapon_left[i].m_pos.x = bossPosX;
			m_weapon_left[i].m_pos.y = bossPosY;

			break;
		}

		// 右方向
		if (m_weapon_right[i].m_isActive == false)
		{
			m_weapon_right[i].m_isActive = true;
			m_weapon_right[i].m_pos.x = bossPosX;
			m_weapon_right[i].m_pos.y = bossPosY;

			break;
		}
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
			DrawCircle(m_weapon_up[i].m_pos.x, m_weapon_up[i].m_pos.y, 16, GetColor(255, 0, 0), false);
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




