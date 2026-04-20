#pragma once

#include <DxLib.h>


class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Load(int hndl);
	void Step();
	void Draw();
	void Exit();

private:
	VECTOR m_pos;

};

