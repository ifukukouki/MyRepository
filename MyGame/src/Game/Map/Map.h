#pragma once

#include <DxLib.h>

#define MAP_CHIP_X_NUM	(40)	//マップチップ横の数
#define MAP_CHIP_Y_NUM	(20)	//マップチップ縦の数

// マップサイズ
const int MAP_SIZE = 60;

class Map
{
public:
	Map();
	~Map();

	// ファイル読み込みフラグ
	bool isReadFile;

	// マップデータ
	const int m_MapData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

	// ファイルからのマップデータ
	int m_FileReadMapData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

	//マップチップ画像読み込み
	void LoadMap();

	//マップ初期化
	void InitMap();

	//マップ描画処理
	void DrawMap();

	//マップ後処理
	void FinMap();

private:

};

