#include"fade.h"
#include<DxLib.h>

//定義関連
#define FADE_SPEED (5)		//フェードの速度０～２５５
#define FADE_SIZE_X (1280)	//フェード画面の横幅
#define FADE_SIZE_Y (720)	//フェード画面の縦幅


//フェードの各種状態
enum tagFadeState {
	FADE_NON,		//フェードなし
	FADE_IN,		//フェードイン中（徐々に画面が出現）
	FADE_OUT,		//フェードアウト中（徐々に画面が消える）
	FADE_OUT_WAIT,	//フェードアウト後の真っ暗状態
};

//フェード処理構造体
typedef struct {
	tagFadeState m_state;	//現在のフェード状況
	int m_count;			//フェード時間のカウント
}FADE_DATA;

FADE_DATA g_fade;

//フェード初期化
void InitFade()
{
	g_fade.m_state = FADE_OUT;
	g_fade.m_count = 0;
}

//フェード処理更新
void StepFade()
{
	//状態に合わせて行動変化
	//実際に処理をするのは下記の二つだけ
	switch (g_fade.m_state)
	{
	case FADE_IN:
		//徐々に明るくするので、数値は減らす
		g_fade.m_count -= FADE_SPEED;
		//０まで来たらフェードイン修了
		if (g_fade.m_count<=0)
		{
			g_fade.m_count = 0;			//安全策
			g_fade.m_state = FADE_NON;
		}
		break;
	case FADE_OUT:
		//徐々に暗くするので、数値は増やす
		g_fade.m_count += FADE_SPEED;
		//２５５まで来たらフェードアウト終了
		if (g_fade.m_count>=255)
		{
			g_fade.m_count = 255;		//安全策
			g_fade.m_state = FADE_OUT_WAIT;
		}
		break;
	}
}

//フェード用の画像描画
void DrawFade()
{
	//黒画像を描画
	switch (g_fade.m_state)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		//アルファ値を調整する
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, g_fade.m_count);

		//フェード用の黒い四角を表示
		DrawBox(0, 0, FADE_SIZE_X, FADE_SIZE_Y,
			GetColor(0, 0, 0), TRUE);

		//使い終わったら元に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	}
}

//フェードイン呼び出し
void RequestFadeIn()
{
	g_fade.m_state = FADE_IN;
	g_fade.m_count = 255;
}

//フェードアウト呼び出し
void RequestFadeOut()
{
	g_fade.m_state = FADE_OUT;
	g_fade.m_count = 0;
}

//フェードインが終了しているか
bool IsEndFadeIn()
{
	if (g_fade.m_state == FADE_IN)
		return false;
	else
		return true;
}

//フェードアウトが終了しているか
bool IsEndFadeOut()
{
	if (g_fade.m_state == FADE_OUT)
		return false;
	else
		return true;
}

