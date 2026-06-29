#pragma once

#include<DxLib.h>


#define ANIM_NUM (10)		//爆発エフェクトの画像枚数
#define ANIM_SPEED (0.25f)	//アニメーション速度


class Effect
{
private:
	static int m_hndl[ANIM_NUM];	//画像ハンドル
	static VECTOR m_pos;			//画像の表示位置
	static float m_animCount;		//時間カウント用
	static bool m_isActive;		//表示フラグ

public:
	//データを初期化
	static void InitExplosion();
	//画像データをロード
	static void LoadExplosion();
	//毎フレーム処理を行う
	static void StepExplosion();
	//画像描画
	static void DrawExplosion();
	//終了前に行う
	static void ExitExplosion();

	//エフェクトを呼び出すための関数
	//@pos : エフェクトの表示場所
	static void RequestExplosion(VECTOR pos);
};

