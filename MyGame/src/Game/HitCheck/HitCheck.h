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
	// 武器（上方向）と敵の当たり判定
	static void CheckHitWeaponUpToEnemy(Weapon& weapon, Enemy& enemy);
	// 武器（下方向）と敵の当たり判定
	static void CheckHitWeaponDownToEnemy(Weapon& weapon, Enemy& enemy);
	// 武器（左方向）と敵の当たり判定
	static void CheckHitWeaponLeftToEnemy(Weapon& weapon, Enemy& enemy);
	// 武器（右方向）と敵の当たり判定
	static void CheckHitWeaponRightToEnemy(Weapon& weapon, Enemy& enemy);
	// プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(Player& player, Enemy& enemy);

	// 武器（上方向）と大きい敵の当たり判定
	static void CheckHitWeaponUpToBigEnemy(Weapon& weapon, BigEnemy& enemy);
	// 武器（下方向）と大きい敵の当たり判定
	static void CheckHitWeaponDownToBigEnemy(Weapon& weapon, BigEnemy& enemy);
	// 武器（左方向）と大きい敵の当たり判定
	static void CheckHitWeaponLeftToBigEnemy(Weapon& weapon, BigEnemy& enemy);
	// 武器（右方向）と大きい敵の当たり判定
	static void CheckHitWeaponRightToBigEnemy(Weapon& weapon, BigEnemy& enemy);
	// プレイヤーと大きい敵の当たり判定
	static void CheckHitPlayerToBigEnemy(Player& player, BigEnemy& enemy);

	// 武器（上方向）とボスの当たり判定
	static void CheckHitWeaponUpToBossEnemy(Weapon& weapon, BossEnemy& enemy);
	// 武器（下方向）とボスの当たり判定
	static void CheckHitWeaponDownToBossEnemy(Weapon& weapon, BossEnemy& enemy);
	// 武器（左方向）とボスの当たり判定
	static void CheckHitWeaponLeftToBossEnemy(Weapon& weapon, BossEnemy& enemy);
	// 武器（右方向）とボスの当たり判定
	static void CheckHitWeaponRightToBossEnemy(Weapon& weapon, BossEnemy& enemy);
	// プレイヤーとボスの当たり判定
	static void CheckHitPlayerToBossEnemy(Player& player, BossEnemy& enemy);
	// プレイヤーとボスの武器の当たり判定
	static void CheckHitPlayerToBossEnemyWeapon(Player& player, BossEnemyWeapon& weapon);
};


