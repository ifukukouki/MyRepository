#pragma once


#include <DxLib.h>


#define ENEMY_MAX (30)


class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Load(int hndl);
	void Step(VECTOR playerPos);
	void Draw();
	void Exit();

	// 座標取得
	VECTOR GetPotision() { return m_pos; }

	// Enemyをリクエスト
	// @pos : どこから出現するか
	// @speed : どの方向に進んでいくか
	// @return : 生成成功か失敗か
	// const参照渡し　処理コストを軽くするため
	bool Request(const VECTOR& pos, const VECTOR& speed);

	// ヒットした後の処理
	void HitCalc(VECTOR speed);

private:
	VECTOR m_pos;
	VECTOR m_speed;
	VECTOR m_dir;
	float m_rotY;
	int m_hndl;
	bool m_isActive;
	
};

