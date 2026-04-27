
#include "SceneManager.h"
#include "../../Lib/fade.h"
#include "../Sound/Sound.h"


//--------------------------------
// コンストラクタ
//--------------------------------
SceneManager::SceneManager()
{
	// 最初のシーンを設定
	m_sceneID = GAME;	// 提出するときはTITLEに変更する
	// 音の初期化
	// 変数名を作って 変数名.Init() みたいな手間が省けるのがstaticクラスの便利なところ
	Sound::Init();
	Sound::Load();

	// フェードの初期化
	InitFade();
}


//--------------------------------
// デストラクタ
//--------------------------------
SceneManager::~SceneManager()
{
	Sound::Exit();
}


//--------------------------------
// 実行
//--------------------------------
int SceneManager::Loop()
{
	// ゲームが終了したかを外部に伝えるため
	int result = -1;

	switch (m_sceneID)
	{
	case SceneManager::TITLE:
		if (m_title.Loop() != -1)
		{
			m_sceneID = SceneManager::GAME;
		}
		break;
	case SceneManager::GAME:
		// GAMEからクリア画面orゲームオーバー画面に行かせる場合は int res = m_play.Loop(); を最初に呼ぶ
		if (m_play.Loop() != -1)
		{
			m_sceneID = SceneManager::RESULT;
		}
		break;
	case SceneManager::RESULT:
		if (m_result.Loop() != -1)
		{
			m_sceneID = SceneManager::TITLE;
		}
		break;
	}

	// フェード処理の更新
	StepFade();

	// 本編が終了したかどうかを外部に伝える
	return result;
}


//--------------------------------
// 描画処理
//--------------------------------
void SceneManager::Draw()
{
	switch (m_sceneID)
	{
	case SceneManager::TITLE:
		m_title.Draw();
		break;
	case SceneManager::GAME:
		m_play.Draw();
		break;
	case SceneManager::RESULT:
		m_result.Draw();
		break;
	}

	// 最後にフェード描画
	DrawFade();
}


