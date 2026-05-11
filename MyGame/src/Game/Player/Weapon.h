#pragma once

#include <DxLib.h>
#include "Player.h"

// •Ší‰æ‘œ‚ÌƒTƒCƒY
const int WEAPON_SIZE = 16;

class Weapon
{
public:
	Weapon();
	~Weapon();

	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();

private:
	VECTOR m_pos;
	int m_hndl;
	bool m_isActive;

	Player m_player;
};

