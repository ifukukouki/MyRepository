
#include "Sound.h"

// staticメンバ変数はここで書く作業が必須！！------

// 配列でのやり方
int Sound::m_hndl[SOUND_NUM];
//-------------------------------------------------


//--------------------------------
// 初期化
//--------------------------------
void Sound::Init()
{
	// 中身を空にする
	// 配列のやり方
	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_hndl[i] = -1;
	}

}


//--------------------------------
// モデルデータのロード
//--------------------------------
void Sound::Load()
{
	// 配列のやり方
	bool ret = true;
	//魔王魂から持ってくる拡張ファイルはoggかwavがおすすめ
	const char* filePath[SOUND_NUM] = {
		"data/sound/bgm00.mp3",
		"data/sound/se_plshot.mp3",
		"data/sound/se_explore.mp3",
		"data/sound/title.mp3",
		"data/sound/game_end.mp3"
	};

	for (int i = 0; i < SOUND_NUM; i++)
	{
		m_hndl[i] = LoadSoundMem(filePath[i]);

		if (m_hndl[i] == -1)
		{
			ret = false;
		}

	}

}


//--------------------------------
// 終了処理
//--------------------------------
void Sound::Exit()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (m_hndl[i] != 1)
		{
			DeleteSoundMem(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}


//--------------------------------
// 音楽再生
//--------------------------------
// デフォルト引数はcppの方では消す( = のこと)。
bool Sound::Play(tagID id, int type, bool isStart)
{
	int ret = PlaySoundMem(m_hndl[id], type, isStart);

	if (ret == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


//--------------------------------
// 音楽停止
//--------------------------------
void Sound::Stop(tagID id)
{
	// 指定された音楽を停止
	StopSoundMem(m_hndl[id]);
}


//--------------------------------
// 全音楽停止
//--------------------------------
void Sound::AllStop()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		StopSoundMem(m_hndl[i]);
	}
}


//--------------------------------
// 音楽を再生中か
//--------------------------------
bool Sound::IsPlay(tagID id)
{
	int result = CheckSoundMem(m_hndl[id]);
	// 1は再生中
	// return CheckSoundMem(m_hndl[id]) == 1 ? true : false; 満たしていたら左の結果(true)、以外だったら右の結果(false)
	if (result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

