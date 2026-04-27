
#include <DxLib.h>
#include "Game/Scene/SceneManager.h"
#include "Lib/input.h"

#include "Game/Map/Map.h"	// テスト用


#define SCREEN_SIZE_X (1280.0f)
#define SCREEN_SIZE_Y (640.0f)

// main関数の代わり
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);			// ウィンドウモードにするか

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);	// 画面のちらつきをなくす

	// シーンの初期化
	SceneManager scene;


	// ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		// 描画した画像をすべて消す
		ClearDrawScreen();

		// ゲーム本体の命令はこれより下に書く

		InputKey::UpdateKey();

		scene.Loop();


		scene.Draw();

		// ゲーム本体の命令はこれより上に書く

		// 作成した画面をモニターへ転送
		ScreenFlip();

	}


	DxLib_End();					// ＤＸライブラリ使用の終了処理

	return 0;						// ソフトの終了 
}


