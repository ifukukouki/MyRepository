#pragma once

#include <DxLib.h>


class Player
{
public:
	Player();
	~Player();

	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();

private:
	VECTOR m_pos;

};

