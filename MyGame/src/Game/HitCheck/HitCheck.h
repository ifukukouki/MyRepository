#pragma once

#include "../Player/Player.h"
#include "../Player/Weapon.h"
#include "../Enemy/Enemy.h"


class HitCheck
{
public:
	static void CheckHitPlayerToEnemy(Player& player, EnemyManager& enemy);

};
