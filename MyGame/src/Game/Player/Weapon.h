#pragma once

#include <DxLib.h>
#include "Player.h"


#define WEAPON_SPEED (5.0f)	// 移動速度
#define WEAPON_MAX (50)		// 撃てる最大数


// 武器画像のサイズ
const int WEAPON_SIZE = 16;

typedef struct
{
	VECTOR m_pos;
	bool m_isActive;
	float m_angle;
}WEAPON_DATA;

class Weapon
{
public:
	Weapon();
	~Weapon();

	void Init();
	void Load();
	void Step(int playerPosX, int playerPosY, float playerAngle);
	void Draw();
	void Exit();

	void UpShot(int i);
	void DownShot(int i);
	void LeftShot(int i);
	void RightShot(int i);

private:
	int m_hndl;
	WEAPON_DATA m_weapon[WEAPON_MAX];

	Player m_player;
};

