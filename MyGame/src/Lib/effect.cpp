
#include "effect.h"
#include <DxLib.h>


// staticメンバ変数はここで書く作業が必須！！------
int Effect::m_hndl[ANIM_NUM];
VECTOR Effect::m_pos;
float Effect::m_animCount;
bool Effect::m_isActive;
//-------------------------------------------------


//データを初期化
void Effect::InitExplosion()
{
	for (int i = 0; i < ANIM_NUM; i++)
	{
		m_hndl[i] = -1;
	}

	m_pos = { 0.0f,0.0f,0.0f };
	m_animCount = 0.0f;
	m_isActive = false;
}

//画像データをロード
void Effect::LoadExplosion()
{
	//すでに画像がロードされていたら-1ではなくなっている
	if (m_hndl[0] == -1)
	{
		int success = -1;

		//画像データ読み込み
		//失敗していたら-1が変数に入る
		success = LoadDivGraph("data/Effect/effect_explosion00.png",
			ANIM_NUM, ANIM_NUM, 1, 180, 180, m_hndl);
	}
}

//毎フレーム処理を行う
void Effect::StepExplosion()
{
	//生存フラグがオフ
	if (m_isActive == false) return;

	//アニメーションの時間をカウント
	m_animCount += ANIM_SPEED;

	//最後の画像を表示したらフラグをオフにする
	if (m_animCount >= ANIM_NUM)
	{
		m_isActive = false;
	}
}

//画像描画
void Effect::DrawExplosion()
{
	//フラグがオフなら終了
	if (m_isActive == false) return;

	//背景画像表示
	//第1引数：X座標、2：Y座標、3：拡大縮小率、4：回転角度（ラジアン角）
	//5：画像ハンドル、6透過処理を有効にするか
	
	//10枚の画像のうち、どれを表示するか
	int nowHndl = m_hndl[(int)m_animCount];

	//爆発画像表示
	DrawRotaGraph((int)m_pos.x, (int)m_pos.y, 1.0, 0.0, nowHndl, TRUE);
}

//終了前に行う
void Effect::ExitExplosion()
{
	for (int i = 0; i < ANIM_NUM; i++)
	{
		//ハンドルが-1でなければ、何かしらロードがされているはず
		if (m_hndl[i] != -1)
		{
			//画像をメモリ上から削除する
			DeleteGraph(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}

//爆発エフェクトの呼び出し
//エフェクトを呼び出すための関数
//@pos : エフェクトの表示場所
void Effect::RequestExplosion(VECTOR pos)
{
	m_isActive = true;
	m_pos = pos;
	m_animCount = 0.0f;
}