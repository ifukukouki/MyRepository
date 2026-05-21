
#include "Weapon.h"
#include "../../Lib/input.h"


// 武器画像のファイルパス
#define WEAPON_IMG_PATH	"data/Weapon/tsurugi_bronze_red.png"


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


Weapon::Weapon() :m_pos(ZERO), m_hndl(-1), m_isActive(false), m_angle(0.0)
{
}
Weapon::~Weapon()
{
}


void Weapon::Init()
{

}


void Weapon::Load()
{
	m_hndl = LoadGraph(WEAPON_IMG_PATH);
}


void Weapon::Step(int playerPosX, int playerPosY)
{
	if (InputKey::IsPushKeyTrg(KEY_INPUT_Z) || InputKey::IsPushKeyTrg(KEY_INPUT_SPACE))
	{
		m_isActive = true;
		m_pos.x = playerPosX;
		m_pos.y = playerPosY;
		
	}
	// プレイヤーからある程度離れたら生存フラグを消す
	if (m_pos.x <= playerPosX - 50 || m_pos.x >= playerPosX + 50 ||
		m_pos.y <= playerPosY - 50 || m_pos.y >= playerPosY + 50)
	{
		m_isActive = false;
	}
}


void Weapon::Draw()
{
	// フラグがオンなら描画
	if (m_isActive == true)
	{
		DrawRotaGraph(m_pos.x, m_pos.y, 0.05, m_angle, m_hndl, true);
	}
}


void Weapon::Exit()
{
	// 画像を破棄
	DeleteGraph(m_hndl);
}


void Weapon::UpShot()
{
	m_angle = 0.8;
	m_pos.y -= WEAPON_SPEED;
}
void Weapon::DownShot()
{
	m_angle = 3.9;
	m_pos.y += WEAPON_SPEED;
}
void Weapon::LeftShot()
{
	m_angle = 5.5;
	m_pos.x -= WEAPON_SPEED;
}
void Weapon::RightShot()
{
	m_angle = 2.35;
	m_pos.x += WEAPON_SPEED;
}

