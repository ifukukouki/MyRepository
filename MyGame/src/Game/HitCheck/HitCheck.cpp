
#include "HitCheck.h"
#include "../../Lib/collision.h"


void HitCheck::CheckHitWeaponToEnemy(Weapon& weapon, Enemy& enemy)
{
	// 敵の数だけループさせる
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX; enemyIndex++)
	{
		ENEMY_DATA& oneEnemy = enemy.GetEnemy(enemyIndex);
		// 敵の生存フラグがオフだったら次へ
		if (oneEnemy.m_isActive == false)
		{
			continue;
		}

		// 武器の数だけループさせる
		for (int weaponIndex = 0; weaponIndex < WEAPON_MAX; weaponIndex++)
		{
			WEAPON_DATA& oneWeaponUp = weapon.GetWeaponUp(weaponIndex);
			WEAPON_DATA& oneWeaponDown = weapon.GetWeaponDown(weaponIndex);
			WEAPON_DATA& oneWeaponLeft = weapon.GetWeaponRight(weaponIndex);
			WEAPON_DATA& oneWeaponRight = weapon.GetWeaponLeft(weaponIndex);
			// 武器の生存フラグがオフなら次へ
			if (oneWeaponUp.m_isActive == false && oneWeaponDown.m_isActive == false &&
				oneWeaponLeft.m_isActive == false && oneWeaponRight.m_isActive == false)
			{
				continue;
			}

			// 武器と敵の当たり判定を関数に入れる
			bool isHit_up = ChekHitCircleToCircle(oneWeaponUp.m_pos, 16, oneEnemy.m_pos, 16);
			bool isHit_down = ChekHitCircleToCircle(oneWeaponDown.m_pos, 16, oneEnemy.m_pos, 16);
			bool isHit_left = ChekHitCircleToCircle(oneWeaponLeft.m_pos, 16, oneEnemy.m_pos, 16);
			bool isHit_right = ChekHitCircleToCircle(oneWeaponRight.m_pos, 16, oneEnemy.m_pos, 16);

			// 当たったらフラグをオンに
			if (isHit_up == true || isHit_down == true ||
				isHit_left == true || isHit_right == true)
			{
				// それぞれの当たった時の処理
				if (isHit_up == true)
				{
					oneWeaponUp.m_isActive = false;
					oneEnemy.m_isActive = false;
				}
				if (isHit_down == true)
				{
					oneWeaponDown.m_isActive = false;
					oneEnemy.m_isActive = false;
				}
				if (isHit_left == true)
				{
					oneWeaponLeft.m_isActive = false;
					oneEnemy.m_isActive = false;
				}
				if (isHit_right == true)
				{
					oneWeaponRight.m_isActive = false;
					oneEnemy.m_isActive = false;
				}
			}
		}
	}
}