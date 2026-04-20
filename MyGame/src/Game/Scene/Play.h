#pragma once

#include <DxLib.h>
#include "../Map/Map.h"



// ゲーム本編を管理するクラス
class Play
{
private:
	// ゲームの処理の流れ
	enum tagSCENE
	{
		INIT,		// データ初期化
		LOAD,		// データ読み込み
		STARTWAIT,	// 開始前の演出
		MAIN,		// ゲーム本編実行
		ENDWAIT,	// 終了前の演出
		END,		// 終了前のデータ破棄
	};

	tagSCENE m_state;		// 現在の状態遷移

	Map m_map;

public:
	// コンストラクタ・デストラクタ
	Play();
	~Play();

	// 実行処理
	int Loop();
	// 描画処理
	void Draw();

private:
	// 初期化
	void Init();

	// データロード
	void Load();

	// メイン処理
	void Step();

	// 終了前処理
	void Exit();

};

