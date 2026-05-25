
#include "Weapon.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)

// 武器画像のファイルパス
#define WEAPON_IMG_PATH	"data/Weapon/tsurugi_bronze_red.png"


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


Weapon::Weapon()
{
}
Weapon::~Weapon()
{
}


void Weapon::Init()
{
	m_hndl = -1;
	for (int i = 0; i < WEAPON_MAX; i++)
	{
		m_weapon[i].m_angle = 0.0f;
		m_weapon[i].m_isActive = false;
	}
}


void Weapon::Load()
{
	m_hndl = LoadGraph(WEAPON_IMG_PATH);
}


void Weapon::Step(int playerPosX, int playerPosY, float playerAngle)
{
	if (InputKey::IsPushKeyTrg(KEY_INPUT_Z) || InputKey::IsPushKeyTrg(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < WEAPON_MAX; i++)
		{
			if (m_weapon[i].m_isActive == false)
			{
				m_weapon[i].m_isActive = true;
				m_weapon[i].m_pos.x = playerPosX;
				m_weapon[i].m_pos.y = playerPosY;
				m_weapon[i].m_angle = playerAngle;

				break;
			}
		}
	}

	for (int i = 0; i < WEAPON_MAX; i++)
	{
		UpShot(i);
		DownShot(i);
		LeftShot(i);
		RightShot(i);
	}
}


void Weapon::Draw()
{
	for (int i = 0; i < WEAPON_MAX; i++)
	{
		// フラグがオンなら描画
		if (m_weapon[i].m_isActive == true)
		{
			DrawRotaGraph(m_weapon[i].m_pos.x, m_weapon[i].m_pos.y, 0.05, m_weapon[i].m_angle, m_hndl, true);
		}
	}
}


void Weapon::Exit()
{
	// 画像を破棄
	DeleteGraph(m_hndl);
}


void Weapon::UpShot(int i)
{
	if (m_weapon[i].m_isActive == true)
	{
		m_weapon[i].m_pos.y -= WEAPON_SPEED;
		if (m_weapon[i].m_pos.y < 0)
		{
			m_weapon[i].m_isActive = false;
		}
	}
}
void Weapon::DownShot(int i)
{
	if (m_weapon[i].m_isActive == true)
	{
		m_weapon[i].m_pos.y += WEAPON_SPEED;
		if (m_weapon[i].m_pos.y > SCREEN_SIZE_Y)
		{
			m_weapon[i].m_isActive = false;
		}
	}
}
void Weapon::LeftShot(int i)
{
	if (m_weapon[i].m_isActive == true)
	{
		m_weapon[i].m_pos.x -= WEAPON_SPEED;
		if (m_weapon[i].m_pos.x < 0)
		{
			m_weapon[i].m_isActive = false;
		}
	}
}
void Weapon::RightShot(int i)
{
	if (m_weapon[i].m_isActive == true)
	{
		m_weapon[i].m_pos.x += WEAPON_SPEED;
		if (m_weapon[i].m_pos.y > SCREEN_SIZE_X)
		{
			m_weapon[i].m_isActive = false;
		}
	}
}

