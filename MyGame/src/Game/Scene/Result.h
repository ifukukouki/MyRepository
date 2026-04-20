#pragma once

#include <DxLib.h>


// リザルト画面を管理するクラス
class Result
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
	tagSCENE m_state;	// 現在の状態遷移
	int m_hndl;			// 画像ハンドル

public:
	// コンストラクタ・デストラクタ
	Result();
	~Result();

	// 実行処理
	int Loop();
	// 描画処理
	void Draw();

private:
};

