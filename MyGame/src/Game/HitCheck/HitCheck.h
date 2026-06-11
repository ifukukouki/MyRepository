#pragma once

#include "../Player/Player.h"
#include "../Player/Weapon.h"
#include "../Enemy/Enemy.h"


class HitCheck
{
public:
	// •Ší‚Æ“G‚Ì“–‚½‚è”»’è
	static void CheckHitWeaponToEnemy(Weapon& weapon, Enemy& enemy);
	// ƒvƒŒƒCƒ„[‚Æ“G‚Ì“–‚½‚è”»’è
	static void CheckHitPlayerToEnemy(Player& player, Enemy& enemy);
};
