
#include "EnemyManager.h"
#include<math.h>


static const char ENEMY_IMG_PATH[] = "data/Enemy/character_monster_ghost_white.png";
static const int WAIT_TIME = 60;	// 敵の再出現時間　60=1秒


//--------------------------------
// コンストラクタ
//--------------------------------
EnemyManager::EnemyManager()
{
	Init();
}


//--------------------------------
// 初期化
//--------------------------------
void EnemyManager::Init()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].Init();	// テスト用
	}

	m_waitTime = 0;
}


//--------------------------------
// モデルデータのロード
//--------------------------------
void EnemyManager::Load()
{
	// モデルのオリジナルデータをロード
	int EnemyHndl = LoadGraph(ENEMY_IMG_PATH);

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].Load(EnemyHndl);
	}

	// 複製が終わったら即破棄
	DeleteGraph(EnemyHndl);
}


//--------------------------------
// 終了処理
//--------------------------------
void EnemyManager::Exit()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].Exit();
	}
}


//--------------------------------
// 毎フレーム処理
//--------------------------------
void EnemyManager::Step(VECTOR playerPos)
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].Step(playerPos);
	}

	// 敵を出現させる
	m_waitTime--;
	if (m_waitTime <= 0)
	{
		Request();
		m_waitTime = WAIT_TIME;
	}
}


//--------------------------------
// 描画処理
//--------------------------------
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		m_enemy[i].Draw();
	}
}


//--------------------------------
// 敵をリクエスト
//--------------------------------
void EnemyManager::Request()
{
	VECTOR EnemyPos = { (float)GetRand(920) - 460.0f, 10.0f, (float)GetRand(920) - 460.0f };
	// Enemyの移動速度
	VECTOR EnemySpeed = { 0.0f,0.0f,-0.5f };

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (m_enemy[i].Request(EnemyPos, EnemySpeed) == true)
		{
			// 一体出現したら終了
			break;
		}
	}
}



