#pragma once


#include <DxLib.h>


#define ENEMY_MAX (30)


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

	// ìGÇåƒÇ—èoÇ∑
	bool Request();

private:
	int m_hndl;
	int m_waitCount;
	ENEMY_DATA m_enemy[ENEMY_MAX];
	
};

