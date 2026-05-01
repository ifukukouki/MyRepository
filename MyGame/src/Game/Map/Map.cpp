
#include "Map.h"



// マップチップ画像のファイルパス
#define MAP_CHIP_IMG_PATH	"data/Map/WorldMap-A2.png"

// マップチップの種類
enum MAP_CHIP_TYPE
{
	MAP_CHIP_GRASS = 0,		//草
	MAP_CHIP_SEA,			//海
	MAP_CHIP_FOREST,		//森
	MAP_CHIP_MOUNTAIN,		//山

	MAP_CHIP_NUM,	//マップチップの種類数
};

// マップチップ構造体
struct MapChip
{
	int handle;		//画像ハンドル
	int x, y;		//座標
	bool isDraw;	//描画フラグ
};

// マップチップを [縦の数][横の数] で用意
MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

// マップチップの配置データ
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

// マップチップの１つのサイズ
const int MAP_CHIP_SIZE_X = (32);
const int MAP_CHIP_SIZE_Y = (32);

// マップチップ画像読み込み
// ※画像の種類を引数で変えられるようにするとよい
void Map::LoadMap()
{
	// 元画像を読み込む
	int src_handle = LoadGraph(MAP_CHIP_IMG_PATH);

	// 失敗なら終了する
	if (src_handle == -1)
		return;

	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			// マップチップの種類によって、
			// 画像のどの位置を切り取るか決める
			int start_x = 0;
			int start_y = 0;

			// 草のマップチップ
			if (mapChipData[y_index][x_index] == MAP_CHIP_GRASS)
			{
				// 土の画像の切り抜き開始位置を設定する
				start_x = 80;
				start_y = 48;
			}
			// 海のマップチップ
			else if (mapChipData[y_index][x_index] == MAP_CHIP_SEA)
			{
				// 海の画像の切り抜き開始位置を設定する
				// ★ココを考える
				start_x = 336;
				start_y = 48;
			}
			// 森のマップチップ
			else if (mapChipData[y_index][x_index] == MAP_CHIP_FOREST)
			{
				// ブロックの画像の切り抜き開始位置を設定する
				// ★ココを考える
				start_x = 400;
				start_y = 48;
			}
			// 山のマップチップ
			else if (mapChipData[y_index][x_index] == MAP_CHIP_MOUNTAIN)
			{
				// ブロックの画像の切り抜き開始位置を設定する
				// ★ココを考える
				start_x = 336;
				start_y = 240;
			}

			MapChip* map_chip = &mapChip[y_index][x_index];

			// 元画像から各マップチップ画像のハンドルを作成
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle);

			// 座標を決める
			map_chip->x = x_index * MAP_CHIP_SIZE_X;
			map_chip->y = y_index * MAP_CHIP_SIZE_Y;

			// 描画フラグをON
			map_chip->isDraw = true;
		}
	}

	// 元画像を削除
	DeleteGraph(src_handle);
}


// マップ初期化
void Map::InitMap()
{
	// マップチップをすべてゼロで初期化
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			mapChip[y_index][x_index].handle = 0;
			mapChip[y_index][x_index].x = 0;
			mapChip[y_index][x_index].y = 0;
			mapChip[y_index][x_index].isDraw = false;
		}
	}

	isReadFile = false;
}


// マップ描画処理
void Map::DrawMap()
{
	// マップチップを描画
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			// 描画フラグがONのチップのみ
			if (mapChip[y_index][x_index].isDraw)
			{
				// ★ココを考える
				DrawGraph(mapChip[y_index][x_index].x, mapChip[y_index][x_index].y, mapChip[y_index][x_index].handle, true);
			}
		}
	}
}


// マップ後処理
void Map::FinMap()
{
	// すべてのマップチップ画像を削除する
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			// 削除
			if (mapChip[y_index][x_index].handle != 0)
			{
				DeleteGraph(mapChip[y_index][x_index].handle);
			}
		}
	}
}

