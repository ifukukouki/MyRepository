#pragma once

#include <DxLib.h>


#define ENEMY_MAX (40)


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
	int m_requestFlg;		// 敵の出現場所を変更する用（１＝上から出現、２＝下、３＝左、４＝右）
	int m_enemySpawnCount;	// 敵が何回出現したか
	ENEMY_DATA m_enemy[ENEMY_MAX];

};

