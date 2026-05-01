#pragma once

#include <DxLib.h>

#define MAP_CHIP_X_NUM	(40)	//マップチップ横の数
#define MAP_CHIP_Y_NUM	(20)	//マップチップ縦の数

class Map
{
public:

	// ファイル読み込みフラグ
	bool isReadFile;

	//マップチップ画像読み込み
//※画像の種類を引数で変えられるようにするとよい
	void LoadMap();

	//マップ初期化
	void InitMap();

	//マップ描画処理
	void DrawMap();

	//マップ後処理
	void FinMap();

private:

};

