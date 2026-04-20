#pragma once

//各種変数の初期化
void InitFade();
//フェードの実行処理
void StepFade();
//フェードの描画処理
void DrawFade();

//フェードイン呼び出し
void RequestFadeIn();
//フェードアウト呼び出し
void RequestFadeOut();
//フェードインが終了しているか
bool IsEndFadeIn();
//フェードアウトが終了しているか
bool IsEndFadeOut();

