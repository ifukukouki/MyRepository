#pragma once

#ifndef __MAP_H__
#define __MAP_H__

//マップチップ画像読み込み
//※画像の種類を引数で変えられるようにするとよい
void LoadMap();

//マップ初期化
void InitMap();

//マップ通常処理
void StepMap();

//マップ描画処理
void DrawMap();

//マップ後処理
void FinMap();

#endif

