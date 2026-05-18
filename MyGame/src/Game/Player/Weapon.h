#pragma once

#include <DxLib.h>


#define WEAPON_SPEED (5.0f);


// •Ší‰æ‘œ‚ÌƒTƒCƒY
const int WEAPON_SIZE = 16;


class Weapon
{
public:
	Weapon();
	~Weapon();

	void Init();
	void Load();
	void Step(int playerPosX, int playerPosY);
	void Draw();
	void Exit();


private:
	VECTOR m_pos;
	int m_hndl;
	bool m_isActive;

};

