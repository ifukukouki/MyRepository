#pragma once


#include <DxLib.h>


#define ENEMY_MAX (30)


typedef struct
{
	VECTOR m_pos;		//表示する座標
	bool m_isActive;	//生存フラグ
}ENEMY_DATA;

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();

private:
	int m_hndl;
	int m_waitCount;
	ENEMY_DATA m_enemy[ENEMY_MAX];
};

