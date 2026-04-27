#pragma once

#include "Title.h"
#include "Play.h"
#include "Result.h"


// ゲーム全体を管理するクラス
class SceneManager
{
private:
	// ゲーム中に使用する各シーン
	enum tagSCENE
	{
		TITLE,	// タイトル画面
		GAME,	// プレイ画面
		RESULT,	// リザルト画面
	};

	// 各シーンの変数を用意
	Title m_title;
	Play m_play;
	Result m_result;
	tagSCENE m_sceneID;	// 今のシーンがどれか

public:
	// コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();

	// 実行
	int Loop();
	// 描画
	void Draw();
};

