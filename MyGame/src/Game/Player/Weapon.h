#pragma once

#include <DxLib.h>
#include "Player.h"


#define WEAPON_MAX (30)		// 撃てる最大数


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

	// 生存フラグを取得
	bool Up_isActive() { return m_weapon_up->m_isActive; }
	bool Down_isActive() { return m_weapon_down->m_isActive; }
	bool Left_isActive() { return m_weapon_left->m_isActive; }
	bool Right_isActive() { return m_weapon_right->m_isActive; }

	// 座標取得
	VECTOR Up_GetPos() { return m_weapon_up->m_pos; }
	VECTOR Down_GetPos() { return m_weapon_down->m_pos; }
	VECTOR Left_GetPos() { return m_weapon_left->m_pos; }
	VECTOR Right_GetPos() { return m_weapon_right->m_pos; }

	void UpShot(int i);		// 上に飛ぶ処理
	void DownShot(int i);	// 下に飛ぶ処理
	void LeftShot(int i);	// 左に飛ぶ処理
	void RightShot(int i);	// 右に飛ぶ処理

	// ヒット時の処理
	bool UpShotHitCalc() { return m_weapon_up->m_isActive = false; }
	bool DownShotHitCalc() { return m_weapon_down->m_isActive = false; }
	bool LeftShotHitCalc() { return m_weapon_left->m_isActive = false; }
	bool RightShotHitCalc() { return m_weapon_right->m_isActive = false; }

	// 武器１つ分の情報取得
	// @id : 配列番号
	// 参照で取得
	WEAPON_DATA& GetWeaponUp(int id) { return m_weapon_up[id]; }
	WEAPON_DATA& GetWeaponDown(int id) { return m_weapon_down[id]; }
	WEAPON_DATA& GetWeaponLeft(int id) { return m_weapon_left[id]; }
	WEAPON_DATA& GetWeaponRight(int id) { return m_weapon_right[id]; }

private:
	int m_hndl;
	WEAPON_DATA m_weapon_up[WEAPON_MAX];	// 上に撃つ処理
	WEAPON_DATA m_weapon_down[WEAPON_MAX];	// 下に撃つ処理
	WEAPON_DATA m_weapon_left[WEAPON_MAX];	// 左に撃つ処理
	WEAPON_DATA m_weapon_right[WEAPON_MAX];	// 右に撃つ処理
};

