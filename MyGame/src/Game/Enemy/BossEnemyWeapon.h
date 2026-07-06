#pragma once

#include <DxLib.h>
#include "BossEnemy.h"


#define BOSSENEMY_WEAPON_MAX (30)		// 撃てる最大数


typedef struct
{
	VECTOR m_pos;		// 座標
	bool m_isActive;	// 生存フラグ
	float m_angle;		// 角度
}BOSSENEMY_WEAPON_DATA;

class BossEnemyWeapon
{
public:
	BossEnemyWeapon();
	~BossEnemyWeapon();

	void Init();
	void Load();
	void Step(int bossPosX, int bossPosY, bool isActive);
	void Draw();
	void Exit();

	void UpShot(int i);		// 上に飛ぶ処理
	void DownShot(int i);	// 下に飛ぶ処理
	void LeftShot(int i);	// 左に飛ぶ処理
	void RightShot(int i);	// 右に飛ぶ処理

	// 武器１つ分の情報取得
	// @id : 配列番号
	// 参照で取得
	BOSSENEMY_WEAPON_DATA& GetBossEnemyWeaponUp(int id) { return m_weapon_up[id]; }
	BOSSENEMY_WEAPON_DATA& GetBossEnemyWeaponDown(int id) { return m_weapon_down[id]; }
	BOSSENEMY_WEAPON_DATA& GetBossEnemyWeaponLeft(int id) { return m_weapon_left[id]; }
	BOSSENEMY_WEAPON_DATA& GetBossEnemyWeaponRight(int id) { return m_weapon_right[id]; }

private:
	int m_hndl;
	int m_waitcount;	// 弾の発射間隔
	BOSSENEMY_WEAPON_DATA m_weapon_up[BOSSENEMY_WEAPON_MAX];	// 上に撃つ処理
	BOSSENEMY_WEAPON_DATA m_weapon_down[BOSSENEMY_WEAPON_MAX];	// 下に撃つ処理
	BOSSENEMY_WEAPON_DATA m_weapon_left[BOSSENEMY_WEAPON_MAX];	// 左に撃つ処理
	BOSSENEMY_WEAPON_DATA m_weapon_right[BOSSENEMY_WEAPON_MAX];	// 右に撃つ処理
};

