#include "input.h"
#include <DxLib.h>

//キー入力情報に必要なデータをまとめた構造体
typedef struct {
	unsigned int m_nowKey;	//現在のボタン情報
	unsigned int m_PrevKey;	//1フレーム前のボタン情報
}INPUT_DATA;

//グローバル変数を作成
static INPUT_DATA g_inputData;

//キー入力情報の初期化
void InitInput()
{
	g_inputData.m_nowKey = g_inputData.m_PrevKey = 0;
}
//キー入力情報を更新
void UpdataInput()
{
	//最新情報は1フレーム前の情報になる
	g_inputData.m_PrevKey = g_inputData.m_nowKey;
	//いったん最新情報は初期化
	g_inputData.m_nowKey = 0;

	//最新情報を取得していく
	//上キー情報取得
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W))
	{
		g_inputData.m_nowKey |= KEY_UP;
	}
	//下キー情報取得
	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S))
	{
		g_inputData.m_nowKey |= KEY_DOWN;
	}
	//右キー情報取得
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D))
	{
		g_inputData.m_nowKey |= KEY_RIGHT;
	}
	//左キー情報取得
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A))
	{
		g_inputData.m_nowKey |= KEY_LEFT;
	}
	//ショットキー情報取得
	if (CheckHitKey(KEY_INPUT_Z) || CheckHitKey(KEY_INPUT_SPACE) || (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		g_inputData.m_nowKey |= KEY_ATTACK;
	}
	//１キー情報取得
	if (CheckHitKey(KEY_INPUT_1))
	{
		g_inputData.m_nowKey |= KEY_1;
	}
	//２キー情報取得
	if (CheckHitKey(KEY_INPUT_2))
	{
		g_inputData.m_nowKey |= KEY_2;
	}
	//３キー情報取得
	if (CheckHitKey(KEY_INPUT_3))
	{
		g_inputData.m_nowKey |= KEY_3;
	}
	//４キー情報取得
	if (CheckHitKey(KEY_INPUT_4))
	{
		g_inputData.m_nowKey |= KEY_4;
	}
	//５キー情報取得
	if (CheckHitKey(KEY_INPUT_5))
	{
		g_inputData.m_nowKey |= KEY_5;
	}
}
//キーを押したか（通常判定）
bool IsInputRep(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//キーを押したか（トリガー判定）
bool IsInputTrg(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) &&
		!(g_inputData.m_PrevKey & key))return 1;
	else return 0;
}
