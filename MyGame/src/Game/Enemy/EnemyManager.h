#pragma once

#include <DxLib.h>
#include "Enemy.h"


class EnemyManager
{
public:
	void Init();
	void Load();
	void Exit();
	void Step(VECTOR playerPos);
	void Draw();
	void Request();

private:


};

