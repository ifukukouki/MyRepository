#pragma once

//各キーの割り当て
#define KEY_UP		(0b0000000001)	//上ボタン
#define KEY_DOWN	(0b0000000010)	//下ボタン
#define KEY_RIGHT	(0b0000000100)	//右ボタン
#define KEY_LEFT	(0b0000001000)	//左ボタン
#define KEY_ATTACK	(0b0000010000)	//攻撃ボタン
#define KEY_1		(0b0000100000)	//１キー
#define KEY_2		(0b0001000000)	//２キー
#define KEY_3		(0b0010000000)	//３キー
#define KEY_4		(0b0100000000)	//４キー
#define KEY_5		(0b1000000000)	//５キー

//キー入力情報の初期化
void InitInput();
//キー入力情報を更新
void UpdataInput();
//キーを押したか（通常判定）
bool IsInputRep(unsigned int key);
//キーを押したか（トリガー判定）
bool IsInputTrg(unsigned int key);

