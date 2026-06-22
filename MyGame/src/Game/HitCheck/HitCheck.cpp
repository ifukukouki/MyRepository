
#include "HitCheck.h"
#include "../../Lib/collision.h"
#include "../Sound/Sound.h"


#define WEAPON_SIZE (16)	// 武器の当たり判定サイズ
#define ENEMY_SIZE (16)		// 敵の当たり判定サイズ
#define BIGENEMY_SIZE (28)	// 大きい敵の当たり判定サイズ
#define BOSSENEMY_SIZE (28)	// ボスの当たり判定サイズ
#define BOSSENEMYWEAPON_SIZE (28)	// ボスの武器の当たり判定サイズ
#define WAIT_COUNT (180)	// プレイヤーの無敵時間用（3秒）


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
				// 効果音再生
				Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

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
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX; enemyIndex++)
	{
		// 敵一体分の情報を取得し生存確認
		ENEMY_DATA& oneEnemy = enemy.GetEnemy(enemyIndex);
		// 敵が生きていなかったらそれはとばす
		if (oneEnemy.m_isActive == false)continue;

		// プレイヤーの座標と半径を取得
		VECTOR playerPos = player.GetPos();
		float playerRadius = player.GetRadius();

		// プレイヤーの体力と生存フラグを取得
		int playerHp = player.GetHp();
		bool playerFlg = player.isActive();

		// 当たり判定開始
		bool isHit = ChekHitCircleToCircle(playerPos, playerRadius, oneEnemy.m_pos, ENEMY_SIZE);

		if (isHit == true)
		{
			// 効果音再生
			Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

			// 体力を減らす
			playerHp -= 1;
			// 敵を消す
			oneEnemy.m_isActive = false;

			if (playerHp <= 0)
			{
				playerFlg = false;
			}
		}
	}
}


// 武器と大きい敵の当たり判定
void HitCheck::CheckHitWeaponToBigEnemy(Weapon& weapon, BigEnemy& enemy)
{
	// 敵の数だけループさせる
	for (int enemyIndex = 0; enemyIndex < BIGENEMY_MAX; enemyIndex++)
	{
		BIGENEMY_DATA& oneEnemy = enemy.GetBigEnemy(enemyIndex);
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
			bool isHit_up = ChekHitCircleToCircle(oneWeaponUp.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BIGENEMY_SIZE);
			bool isHit_down = ChekHitCircleToCircle(oneWeaponDown.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BIGENEMY_SIZE);
			bool isHit_left = ChekHitCircleToCircle(oneWeaponLeft.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BIGENEMY_SIZE);
			bool isHit_right = ChekHitCircleToCircle(oneWeaponRight.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BIGENEMY_SIZE);

			// 当たったらフラグをオンに
			if (isHit_up == true || isHit_down == true ||
				isHit_left == true || isHit_right == true)
			{
				// 効果音再生
				Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

				// それぞれの当たった時の処理
				if (isHit_up == true)
				{
					oneWeaponUp.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
				if (isHit_down == true)
				{
					oneWeaponDown.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
				if (isHit_left == true)
				{
					oneWeaponLeft.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
				if (isHit_right == true)
				{
					oneWeaponRight.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
			}
		}
	}
}


// プレイヤーと大きい敵の当たり判定
void HitCheck::CheckHitPlayerToBigEnemy(Player& player, BigEnemy& enemy)
{
	// プレイヤーが生きていなかったら返す
	if (player.isActive() == false)
	{
		return;
	}

	// 敵の数だけループ
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX; enemyIndex++)
	{
		// 敵一体分の情報を取得し生存確認
		BIGENEMY_DATA& oneEnemy = enemy.GetBigEnemy(enemyIndex);
		// 敵が生きていなかったらそれはとばす
		if (oneEnemy.m_isActive == false)continue;

		// プレイヤーの座標と半径を取得
		VECTOR playerPos = player.GetPos();
		float playerRadius = player.GetRadius();

		// プレイヤーの体力と生存フラグを取得
		int playerHp = player.GetHp();
		bool playerFlg = player.isActive();

		// 当たり判定開始
		bool isHit = ChekHitCircleToCircle(playerPos, playerRadius, oneEnemy.m_pos, BIGENEMY_SIZE);

		if (isHit == true)
		{
			// 効果音再生
			Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

			// 体力を減らす
			playerHp -= 1;
			// 敵を消す
			oneEnemy.m_isActive = false;

			if (playerHp <= 0)
			{
				playerFlg = false;
			}
		}
	}
}


// 武器とボスの当たり判定
void HitCheck::CheckHitWeaponToBossEnemy(Weapon& weapon, BossEnemy& enemy)
{
	// 敵の数だけループさせる
	for (int enemyIndex = 0; enemyIndex < BOSSENEMY_MAX; enemyIndex++)
	{
		BOSSENEMY_DATA& oneEnemy = enemy.GetBossEnemy(enemyIndex);
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
			bool isHit_up = ChekHitCircleToCircle(oneWeaponUp.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BOSSENEMY_SIZE);
			bool isHit_down = ChekHitCircleToCircle(oneWeaponDown.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BOSSENEMY_SIZE);
			bool isHit_left = ChekHitCircleToCircle(oneWeaponLeft.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BOSSENEMY_SIZE);
			bool isHit_right = ChekHitCircleToCircle(oneWeaponRight.m_pos, WEAPON_SIZE, oneEnemy.m_pos, BOSSENEMY_SIZE);

			// 当たったらフラグをオンに
			if (isHit_up == true || isHit_down == true ||
				isHit_left == true || isHit_right == true)
			{
				// 効果音再生
				Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

				// それぞれの当たった時の処理
				if (isHit_up == true)
				{
					oneWeaponUp.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
				if (isHit_down == true)
				{
					oneWeaponDown.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
				if (isHit_left == true)
				{
					oneWeaponLeft.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
				if (isHit_right == true)
				{
					oneWeaponRight.m_isActive = false;
					oneEnemy.m_hp -= 1;
					if (oneEnemy.m_hp <= 0)
					{
						oneEnemy.m_isActive = false;
					}
				}
			}
		}
	}
}


// プレイヤーとボスの当たり判定
void HitCheck::CheckHitPlayerToBossEnemy(Player& player, BossEnemy& enemy)
{
	// プレイヤーが生きていなかったら返す
	if (player.isActive() == false)
	{
		return;
	}

	// 敵の数だけループ
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX; enemyIndex++)
	{
		// 敵一体分の情報を取得し生存確認
		BOSSENEMY_DATA& oneEnemy = enemy.GetBossEnemy(enemyIndex);
		// 敵が生きていなかったらそれはとばす
		if (oneEnemy.m_isActive == false)continue;

		// プレイヤーの座標と半径を取得
		VECTOR playerPos = player.GetPos();
		float playerRadius = player.GetRadius();

		// プレイヤーの体力と生存フラグを取得
		int playerHp = player.GetHp();
		bool playerFlg = player.isActive();

		// 当たり判定開始
		bool isHit = ChekHitCircleToCircle(playerPos, playerRadius, oneEnemy.m_pos, BOSSENEMY_SIZE);

		if (isHit == true)
		{
			// 効果音再生
			Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

			// 体力を減らす
			playerHp -= 1;
			// 敵を消す
			oneEnemy.m_isActive = false;

			if (playerHp <= 0)
			{
				playerFlg = false;
			}
		}
	}
}


// プレイヤーとボスの武器の当たり判定
void HitCheck::CheckHitPlayerToBossEnemyWeapon(Player& player, BossEnemyWeapon& weapon)
{
	// 武器の数だけループさせる
	for (int weaponIndex = 0; weaponIndex < WEAPON_MAX; weaponIndex++)
	{
		BOSSENEMY_WEAPON_DATA& oneWeaponUp = weapon.GetBossEnemyWeaponUp(weaponIndex);
		BOSSENEMY_WEAPON_DATA& oneWeaponDown = weapon.GetBossEnemyWeaponDown(weaponIndex);
		BOSSENEMY_WEAPON_DATA& oneWeaponLeft = weapon.GetBossEnemyWeaponRight(weaponIndex);
		BOSSENEMY_WEAPON_DATA& oneWeaponRight = weapon.GetBossEnemyWeaponLeft(weaponIndex);
		// 武器の生存フラグがオフなら次へ
		if (oneWeaponUp.m_isActive == false && oneWeaponDown.m_isActive == false &&
			oneWeaponLeft.m_isActive == false && oneWeaponRight.m_isActive == false)
		{
			continue;
		}

		// プレイヤーの座標と半径を取得
		VECTOR playerPos = player.GetPos();
		float playerRadius = player.GetRadius();

		// プレイヤーとボスの武器の当たり判定を関数に入れる
		bool isHit_up = ChekHitCircleToCircle(playerPos, playerRadius, oneWeaponUp.m_pos, BOSSENEMY_SIZE);
		bool isHit_down = ChekHitCircleToCircle(playerPos, playerRadius, oneWeaponDown.m_pos, BOSSENEMY_SIZE);
		bool isHit_left = ChekHitCircleToCircle(playerPos, playerRadius, oneWeaponLeft.m_pos, BOSSENEMY_SIZE);
		bool isHit_right = ChekHitCircleToCircle(playerPos, playerRadius, oneWeaponRight.m_pos, BOSSENEMY_SIZE);

		// 当たったらフラグをオンに
		if (isHit_up == true || isHit_down == true ||
			isHit_left == true || isHit_right == true)
		{
			// 効果音再生
			Sound::Play(Sound::SE_EXPLOSION, DX_PLAYTYPE_BACK);

			// それぞれの当たった時の処理
			if (isHit_up == true)
			{
				oneWeaponUp.m_isActive = false;
				oneEnemy.m_hp -= 1;
				if (oneEnemy.m_hp <= 0)
				{
					oneEnemy.m_isActive = false;
				}
			}
			if (isHit_down == true)
			{
				oneWeaponDown.m_isActive = false;
				oneEnemy.m_hp -= 1;
				if (oneEnemy.m_hp <= 0)
				{
					oneEnemy.m_isActive = false;
				}
			}
			if (isHit_left == true)
			{
				oneWeaponLeft.m_isActive = false;
				oneEnemy.m_hp -= 1;
				if (oneEnemy.m_hp <= 0)
				{
					oneEnemy.m_isActive = false;
				}
			}
			if (isHit_right == true)
			{
				oneWeaponRight.m_isActive = false;
				oneEnemy.m_hp -= 1;
				if (oneEnemy.m_hp <= 0)
				{
					oneEnemy.m_isActive = false;
				}
			}
		}
	}
}

