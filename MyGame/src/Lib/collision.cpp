#include"collision.h"


//点と四角の当たり判定
bool ChekHitDotToSquare(VECTOR dotPos, VECTOR squarePos,
	int width, int height)
{
	//四角形の上下左右それぞれの座標を計算する
	float up = squarePos.y - height * 0.5f;
	float down = squarePos.y + height * 0.5f;
	float left = squarePos.x - width * 0.5f;
	float right = squarePos.x + width * 0.5f;

	//４つの端をそれぞれチェックして、すべての条件を満たしたらヒット！
	if (dotPos.x >= left && dotPos.x <= right
		&& dotPos.y >= up && dotPos.y <= down)
	{
		return true;	//無事ヒット！
	}
	else return false;	//ヒットならず
}

//矩形同士の当たり判定
bool ChekHitSquareToSquare(VECTOR squarePos1, int width1, int height1,
	VECTOR squarePos2, int width2, int height2)
{
	//四角形の上下左右それぞれの座標を計算する
	float up1 = squarePos1.y - height1 * 0.5f;
	float down1 = squarePos1.y + height1 * 0.5f;
	float left1 = squarePos1.x - width1 * 0.5f;
	float right1 = squarePos1.x + width1 * 0.5f;

	//四角形の上下左右それぞれの座標を計算する
	float up2 = squarePos2.y - height2 * 0.5f;
	float down2 = squarePos2.y + height2 * 0.5f;
	float left2 = squarePos2.x - width2 * 0.5f;
	float right2 = squarePos2.x + width2 * 0.5f;

	//当たっているかの判定
	if (up1 <= down2 && down1 >= up2
		&& left1 <= right2 && right1 >= left2)
	{
		return true;	//無事ヒット！
	}
	else
	{
		return false;	//ヒットならず
	}
}

//円同士の当たり判定
bool ChekHitCircleToCircle(VECTOR circlePos1, int radius1,
	 VECTOR circlePos2, int radius2)
{
	//横の長さの2乗を調べる
	float lenX = circlePos1.x - circlePos2.x;
	lenX *= lenX;
	//縦の長さの2乗を調べる
	float lenY = circlePos1.y - circlePos2.y;
	lenY *= lenY;
	//最短距離の2乗を計算
	float len = lenX + lenY;

	//半径2個を足した値の2乗を調べる
	float totalRadius = radius1 + radius2;
	totalRadius *= totalRadius;

	if (len <= totalRadius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//IsHitRectの定義
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// 当たっているときの処理
		return true;
	}

	return false;
}