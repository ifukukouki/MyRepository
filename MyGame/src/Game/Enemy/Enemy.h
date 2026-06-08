#pragma once


#include <DxLib.h>


#define ENEMY_MAX (10)


typedef struct {
	VECTOR m_pos;
	VECTOR m_dir;
	bool m_isActive;
}ENEMY_DATA;

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Load();
	void Step(VECTOR playerPos);
	void Draw();
	void Exit();

	// 敵を呼び出す
	bool Request();

	//// 生存フラグを取得
	//bool isActive() { return m_enemy->m_isActive; }

	//// 座標取得
	//VECTOR GetPos() { return m_enemy->m_pos; }

	//// ヒット時の処理
	//bool HitCalc() { return m_enemy->m_isActive = false; }

	// 敵１体分の情報取得
	// @id : 配列番号
	// 参照で取得
	ENEMY_DATA& GetEnemy(int id) { return m_enemy[id]; }

private:
	int m_hndl;
	int m_waitCount;
	ENEMY_DATA m_enemy[ENEMY_MAX];

};

