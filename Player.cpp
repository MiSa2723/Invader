#include "Player.h"
#include <DxLib.h>

namespace
{
	const float PLAYER_INIT_X = 0.0f;
	const float PLAYER_INIT_Y = 0.0f;
	const float PLAYER_INIT_SPEED = 5.0f;
	const int PLAYER_IMAGE_WIDHT = 32;
	const int PLAYER_IMAGE_HEIGHT = 32;
}

Player::Player()
	:GameObject(),hPlayerImage_(-1),x_(0),y_(0),speed_(0)
{
	hPlayerImage_ = LoadGraph("Assets\\画像\\tiny_ship5.png"); //プレイヤーの画像読み込み
	if (hPlayerImage_ == 1)
	{
		//エラーを返してゲーム終了
	}
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDHT, y_ + PLAYER_IMAGE_HEIGHT, hPlayerImage_, TRUE);
}
