
#include "Weapon.h"
#include "../../Lib/input.h"


// 武器画像のファイルパス
#define WEAPON_IMG_PATH	"data/Weapon/tsurugi_bronze_red.png"


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


Weapon::Weapon() :m_pos(ZERO), m_hndl(-1), m_isActive(false)
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


void Weapon::Step()
{
	if (InputKey::IsPushKeyTrg(KEY_INPUT_Z) || InputKey::IsPushKeyTrg(KEY_INPUT_SPACE))
	{
		
	}

}


void Weapon::Draw()
{
	// フラグがオンなら描画
	if (m_isActive == true)
	{
		DrawRotaGraph(m_pos.x, m_pos.y, 1.0, 0.0, m_hndl, true);
	}
}


void Weapon::Exit()
{
	// 画像を破棄
	DeleteGraph(m_hndl);
}



