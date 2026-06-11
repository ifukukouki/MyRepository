
#include "HitCheck.h"
#include "../../Lib/collision.h"


#define WEAPON_SIZE (16)
#define ENEMY_SIZE (16)
#define PLAYER_SIZE (16)


// 武器と敵の当たり判定
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
			bool isHit_up = ChekHitCircleToCircle(oneWeaponUp.m_pos, WEAPON_SIZE, oneEnemy.m_pos, ENEMY_SIZE);
			bool isHit_down = ChekHitCircleToCircle(oneWeaponDown.m_pos, WEAPON_SIZE, oneEnemy.m_pos, ENEMY_SIZE);
			bool isHit_left = ChekHitCircleToCircle(oneWeaponLeft.m_pos, WEAPON_SIZE, oneEnemy.m_pos, ENEMY_SIZE);
			bool isHit_right = ChekHitCircleToCircle(oneWeaponRight.m_pos, WEAPON_SIZE, oneEnemy.m_pos, ENEMY_SIZE);

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


// プレイヤーと敵の当たり判定
void HitCheck::CheckHitPlayerToEnemy(Player& player, Enemy& enemy)
{
	// プレイヤーが生きていなかったら返す
	if (player.isActive() == false)
	{
		return;
	}

	// 敵の数だけループ
	for (int enemyID = 0; enemyID < ENEMY_MAX; enemyID++)
	{
		// 敵一体分の情報を取得し生存確認
		ENEMY_DATA& oneEnemy = enemy.GetEnemy(enemyID);
		// 敵が生きていなかったらそれはとばす
		if (oneEnemy.isActive() == false)continue;

		// それぞれの座標と半径を取得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy.GetCenter();
		float enemyRadius = oneEnemy.GetRadius();

		// 二点間の距離を取得
		VECTOR enVec = VSub(enemyPos, playerPos);	// Enemyのノックバック用
		VECTOR plVec = VSub(enemyPos, playerPos);	// プレイヤーのノックバック用
		float len = VSize(enVec);

		// 当たり判定開始
		bool isHit = Collision::CheckHitSphereToSphere(playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHit == true)
		{
			// 効果音再生
			SoundManager::Play(SoundManager::SE_EXPLOSION, DX_PLAYTYPE_BACK);

			// あらかじめ「敵の座標-プレイヤーの座標」を計算してたので
			// このベクトルを使用する
			enVec = VNorm(enVec);
			enVec.y = 0.0f;					// 上方向に飛ばす力(上に飛ばさないなら不要)
			enVec = VScale(enVec, 1.3f);	// 全体の吹き飛ばす力をここで調整

			plVec = VNorm(plVec);
			plVec.y = 1.5f;					// 上方向に飛ばす力(上に飛ばさないなら不要)
			plVec = VScale(plVec, 1.3f);	// 全体の吹き飛ばす力をここで調整

			// お互い当たった！！
			player.HitCalc(plVec);
			oneEnemy.HitCalc(enVec);
		}
}

