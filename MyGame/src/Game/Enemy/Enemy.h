#pragma once


#include <DxLib.h>
#include "../Player/Player.h"


#define ENEMY_MAX (50)


typedef struct {
	VECTOR m_pos;
	VECTOR m_dir;
	bool m_isActive;

	bool isActive() { return m_isActive; }
}ENEMY_DATA;

class Enemy : public Player
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
	bool Request1();	// 上から出現
	bool Request2();	// 下から出現
	bool Request3();	// 左から出現
	bool Request4();	// 右から出現

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

