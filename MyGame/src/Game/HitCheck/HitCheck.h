#pragma once

#include "../Player/Player.h"
#include "../Player/Weapon.h"
#include "../Enemy/Enemy.h"
#include "../Enemy/BigEnemy.h"
#include "../Enemy/BossEnemy.h"
#include "../Enemy/BossEnemyWeapon.h"


class HitCheck
{
public:
	// 武器と敵の当たり判定
	static void CheckHitWeaponToEnemy(Weapon& weapon, Enemy& enemy);
	// プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(Player& player, Enemy& enemy);

	// 武器と大きい敵の当たり判定
	static void CheckHitWeaponToBigEnemy(Weapon& weapon, BigEnemy& enemy);
	// プレイヤーと大きい敵の当たり判定
	static void CheckHitPlayerToBigEnemy(Player& player, BigEnemy& enemy);

	// 武器とボスの当たり判定
	static void CheckHitWeaponToBossEnemy(Weapon& weapon, BossEnemy& enemy);
	// プレイヤーとボスの当たり判定
	static void CheckHitPlayerToBossEnemy(Player& player, BossEnemy& enemy);
	// プレイヤーとボスの武器の当たり判定
	static void CheckHitPlayerToBossEnemyWeapon(Player& player, BossEnemyWeapon& weapon);
};


