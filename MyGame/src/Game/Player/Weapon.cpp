
#include "Weapon.h"
#include "../../Lib/input.h"


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)
#define WEAPON_SPEED (5.0f)	// 武器の移動速度

// 武器画像のファイルパス
#define WEAPON_IMG_PATH	"data/Weapon/tsurugi_bronze_red.png"


static const VECTOR ZERO{ 0.0f, 0.0f, 0.0f };


Weapon::Weapon() :m_hndl(0), m_weapon_up(), m_weapon_down(), m_weapon_left(), m_weapon_right()
{
}
Weapon::~Weapon()
{
}


// 初期化
void Weapon::Init()
{
	m_hndl = -1;
	for (int i = 0; i < WEAPON_MAX; i++)
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
void Weapon::Load()
{
	m_hndl = LoadGraph(WEAPON_IMG_PATH);
}


// 毎フレーム処理
void Weapon::Step(int playerPosX, int playerPosY, float playerAngle, int playerAnime)
{
	if (InputKey::IsPushKeyTrg(KEY_INPUT_Z) || InputKey::IsPushKeyTrg(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < WEAPON_MAX; i++)
		{
			// 生存フラグを確認しプレイヤーのアニメーションで撃つ方向を決める
			// 上方向
			if (m_weapon_up[i].m_isActive == false && playerAnime == 1)
			{
				m_weapon_up[i].m_isActive = true;
				m_weapon_up[i].m_pos.x = playerPosX;
				m_weapon_up[i].m_pos.y = playerPosY;
				m_weapon_up[i].m_angle = playerAngle;

				break;
			}

			// 下方向
			if (m_weapon_down[i].m_isActive == false && playerAnime == 2)
			{
				m_weapon_down[i].m_isActive = true;
				m_weapon_down[i].m_pos.x = playerPosX;
				m_weapon_down[i].m_pos.y = playerPosY;
				m_weapon_down[i].m_angle = playerAngle;

				break;
			}

			// 左方向
			if (m_weapon_left[i].m_isActive == false && playerAnime == 3)
			{
				m_weapon_left[i].m_isActive = true;
				m_weapon_left[i].m_pos.x = playerPosX;
				m_weapon_left[i].m_pos.y = playerPosY;
				m_weapon_left[i].m_angle = playerAngle;

				break;
			}

			// 右方向
			if (m_weapon_right[i].m_isActive == false && playerAnime == 4)
			{
				m_weapon_right[i].m_isActive = true;
				m_weapon_right[i].m_pos.x = playerPosX;
				m_weapon_right[i].m_pos.y = playerPosY;
				m_weapon_right[i].m_angle = playerAngle;

				break;
			}
		}
	}
}


// 画像描画
void Weapon::Draw()
{
	for (int i = 0; i < WEAPON_MAX; i++)
	{
		// フラグがオンなら描画
		if (m_weapon_up[i].m_isActive == true)
		{
			DrawRotaGraph(m_weapon_up[i].m_pos.x, m_weapon_up[i].m_pos.y, 0.05, m_weapon_up[i].m_angle, m_hndl, true);
		
			// 当たり判定表示
			//DrawCircle(m_weapon_up[i].m_pos.x, m_weapon_up[i].m_pos.y, 15, GetColor(255, 0, 0), false);
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
void Weapon::Exit()
{
	// 画像を破棄
	DeleteGraph(m_hndl);
}


// 上に飛ぶ処理
void Weapon::UpShot(int i)
{
	if (m_weapon_up[i].m_isActive == true)
	{
		m_weapon_up[i].m_pos.y -= WEAPON_SPEED;
		if (m_weapon_up[i].m_pos.y < 0)
		{
			m_weapon_up[i].m_isActive = false;
		}
	}
}
// 下に飛ぶ処理
void Weapon::DownShot(int i)
{
	if (m_weapon_down[i].m_isActive == true)
	{
		m_weapon_down[i].m_pos.y += WEAPON_SPEED;
		if (m_weapon_down[i].m_pos.y > SCREEN_SIZE_Y)
		{
			m_weapon_down[i].m_isActive = false;
		}
	}
}
// 左に飛ぶ処理
void Weapon::LeftShot(int i)
{
	if (m_weapon_left[i].m_isActive == true)
	{
		m_weapon_left[i].m_pos.x -= WEAPON_SPEED;
		if (m_weapon_left[i].m_pos.x < 0)
		{
			m_weapon_left[i].m_isActive = false;
		}
	}
}
// 右に飛ぶ処理
void Weapon::RightShot(int i)
{
	if (m_weapon_right[i].m_isActive == true)
	{
		m_weapon_right[i].m_pos.x += WEAPON_SPEED;
		if (m_weapon_right[i].m_pos.x > SCREEN_SIZE_X)
		{
			m_weapon_right[i].m_isActive = false;
		}
	}
}




