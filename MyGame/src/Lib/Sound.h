#pragma once

#include <DxLib.h>


// BGM・SEを管理するクラス 最終的にはBGMとSEを分けるようになっておくとよい
class Sound
{
	// 外部で使うのでpublic
public:
	// ゲームで使う音一覧
	enum tagID
	{
		BGM_GAME,		// ゲーム本編
		SE_PLSHOT,		// SE プレイヤーの弾
		SE_EXPLOSION,	// SE 爆発音
		BGM_TITLE,		// タイトル
		BGM_RESULT,		// リザルト
		// 追加する場合はここに

		SOUND_NUM
	};

private:
	// 配列でのやり方
	static int m_hndl[SOUND_NUM];


public:
	// staticクラスはコンストラクタデストラクタは呼ばれない
	// 初期化
	static void Init();
	// データ関連のロード
	static void Load();
	// 終了時のデータ破棄など
	static void Exit();

	//音楽再生
	// @id		:	再生する音楽
	// @type	:	DX_PLAYTYPE_BACK = 1回再生
	//				DX_PLAYTYPE_LOOP = 繰り返し再生
	// @isStart	:	true = 最初から再生, false = 途中から
	// @return	:	true = 再生成功, false = 再生失敗
	static bool Play(tagID id, int type = DX_PLAYTYPE_BACK, bool isStart = true);

	// 音楽停止
	static void Stop(tagID id);

	// 全音楽停止
	static void AllStop();

	// 音楽を再生中か
	// @id		:	tagIDの番号
	// @return	:	true = 再生中, false = 停止中
	static bool IsPlay(tagID id);
};

