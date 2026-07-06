#pragma once

#include <DxLib.h>


#define BOSSENEMY_MAX (1)


typedef struct {
	VECTOR m_pos;
	VECTOR m_dir;
	bool m_isActive;
	int m_hp;

}BOSSENEMY_DATA;

class BossEnemy
{
public:
	BossEnemy();
	~BossEnemy();

	void Init();
	void Load();
	void Step(VECTOR playerPos);
	void Draw();
	void Exit();

	// 敵を呼び出す
	bool Request();	// 上から出現

	// 現在の座標を取得
	int GetPosX() { return m_enemy->m_pos.x; }
	int GetPosY() { return m_enemy->m_pos.y; }

	// 生存フラグを取得
	bool GetisActive() { return m_enemy->m_isActive; }

	// 敵１体分の情報取得
	// @id : 配列番号
	// 参照で取得
	BOSSENEMY_DATA& GetBossEnemy(int id) { return m_enemy[id]; }

private:
	int m_hndl;
	int m_waitCount;
	BOSSENEMY_DATA m_enemy[BOSSENEMY_MAX];

public:
	static bool m_isClear;	// ボスを倒したか（true＝倒した、false＝倒していない）
};

