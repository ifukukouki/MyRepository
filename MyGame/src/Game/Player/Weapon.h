#pragma once

#include <DxLib.h>
#include "Player.h"


#define WEAPON_MAX (30)		// 撃てる最大数


// 武器画像のサイズ
const int WEAPON_SIZE = 16;

typedef struct
{
	VECTOR m_pos;		// 座標
	bool m_isActive;	// 生存フラグ
	float m_angle;		// 角度
}WEAPON_DATA;

class Weapon
{
public:
	Weapon();
	~Weapon();

	void Init();
	void Load();
	void Step(int playerPosX, int playerPosY, float playerAngle, int playerAnime);
	void Draw();
	void Exit();

	void UpShot(int i);		// 上に飛ぶ処理
	void DownShot(int i);	// 下に飛ぶ処理
	void LeftShot(int i);	// 左に飛ぶ処理
	void RightShot(int i);	// 右に飛ぶ処理

private:
	int m_hndl;
	WEAPON_DATA m_weapon_up[WEAPON_MAX];	// 上に撃つ処理
	WEAPON_DATA m_weapon_down[WEAPON_MAX];	// 下に撃つ処理
	WEAPON_DATA m_weapon_left[WEAPON_MAX];	// 左に撃つ処理
	WEAPON_DATA m_weapon_right[WEAPON_MAX];	// 右に撃つ処理
};

