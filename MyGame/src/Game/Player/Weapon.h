#pragma once

#include <DxLib.h>
#include "Player.h"


#define WEAPON_SPEED (5.0f);


// ïêäÌâÊëúÇÃÉTÉCÉY
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

	bool isActive() { return m_isActive; }

	VECTOR GetPos() { return m_pos; }

	void UpShot();
	void DownShot();
	void LeftShot();
	void RightShot();

private:
	VECTOR m_pos;
	int m_hndl;
	bool m_isActive;
	float m_angle;
	
};

