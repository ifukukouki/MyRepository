#pragma once

#include <DxLib.h>
#include "Enemy.h"
#include "../Player/Player.h"


class EnemyManager
{
public:
	void Init();
	void Load();
	void Exit();
	void Step(VECTOR playerPos);
	void Draw();
	void Request();

	Enemy& GetEnemy(int id) { return m_enemy[id]; }

private:
	Enemy m_enemy[ENEMY_MAX];
	
	Player m_player;
	int m_waitTime;
};

