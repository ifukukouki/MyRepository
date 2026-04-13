
#include <DxLib.h>
#include "Map.h"

#define MAP_CHIP_X_NUM	(12)	//マップチップ横の数
#define MAP_CHIP_Y_NUM	(10)	//マップチップ縦の数

//マップチップ画像のファイルパス
#define MAP_CHIP_IMG_PATH	"data/Map/MapChip01.png"

//マップチップの種類
enum MAP_CHIP_TYPE
{
	MAP_CHIP_SOIL = 0,		//土
	MAP_CHIP_GRASS,			//草
	MAP_CHIP_SEA,			//海
	MAP_CHIP_BLOCK,			//ブロック

	MAP_CHIP_NUM,	//マップチップの種類数
};

//マップチップ構造体
struct MapChip
{
	int handle;		//画像ハンドル
	int x, y;		//座標
	bool isDraw;	//描画フラグ
};

//マップチップを [縦の数][横の数] で用意
MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

//マップチップの配置データ
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 3, 2, 2, 3, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 3, 2, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 1, 1, 3, 2, 2, 2, 2, 2, 2 },
	{ 0, 0, 0, 1, 1, 3, 2, 2, 3, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1 },
};

//マップチップの１つのサイズ
const int MAP_CHIP_SIZE_X = (32);
const int MAP_CHIP_SIZE_Y = (32);

//マップチップ画像読み込み
//※画像の種類を引数で変えられるようにするとよい
void LoadMap()
{
	//元画像を読み込む
	int src_handle = LoadGraph(MAP_CHIP_IMG_PATH);

	//失敗なら終了する
	if (src_handle == -1)
		return;

	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//マップチップの種類によって、
			//画像のどの位置を切り取るか決める
			int start_x = 0;
			int start_y = 0;

			//土のマップチップ
			if (mapChipData[y_index][x_index] == MAP_CHIP_SOIL)
			{
				//土の画像の切り抜き開始位置を設定する
				start_x = 0;
				start_y = 0;
			}
			//草のマップチップ
			else if (mapChipData[y_index][x_index] == MAP_CHIP_GRASS)
			{
				//草の画像の切り抜き開始位置を設定する
				//★ココを考える
			}
			//海のマップチップ
			else if (mapChipData[y_index][x_index] == MAP_CHIP_SEA)
			{
				//海の画像の切り抜き開始位置を設定する
				//★ココを考える
			}
			//ブロックのマップチップ
			else if (mapChipData[y_index][x_index] == MAP_CHIP_BLOCK)
			{
				//ブロックの画像の切り抜き開始位置を設定する
				//★ココを考える
			}

			MapChip* map_chip = &mapChip[y_index][x_index];

			//元画像から各マップチップ画像のハンドルを作成
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle);

			//座標を決める
			map_chip->x = x_index * MAP_CHIP_SIZE_X;
			map_chip->y = y_index * MAP_CHIP_SIZE_Y;

			//描画フラグをON
			map_chip->isDraw = true;
		}
	}

	//元画像を削除
	DeleteGraph(src_handle);
}

//マップ初期化
void InitMap()
{
	//マップチップをすべてゼロで初期化
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
}

//マップ通常処理
void StepMap()
{
}

//マップ描画処理
void DrawMap()
{
	//マップチップを描画
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//描画フラグがONのチップのみ
			if (mapChip[y_index][x_index].isDraw)
			{
				//★ココを考える
			}
		}
	}
}

//マップ後処理
void FinMap()
{
	//すべてのマップチップ画像を削除する
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//削除
			if (mapChip[y_index][x_index].handle != 0)
			{
				DeleteGraph(mapChip[y_index][x_index].handle);
			}
		}
	}
}
