#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"

namespace
{
	const float PLAYER_INIT_SPEED = 200.0f;	//プレイヤーの速度
	const int PLAYER_IMAGE_WIDHT = 48;		//プレイヤーの画像の幅
	const int PLAYER_IMAGE_HEIGHT = 48;		//プレイヤーの画像の高さ
	const int PLAYER_BASE_MARGIN = 32;		//プレイヤーの基準マージン

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDHT / 2;	//プレイヤーの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//プレイヤーの初期Y座標
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
	//画像のサイズを開放　後で書いて
}

void Player::Update()
{
	float dt = GetDeltaTime();	//フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ = x_ - speed_ * dt;	//左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ = x_ + speed_ * dt;	//右に移動
	}
}

void Player::Draw()
{
	//プレイヤーの画像を描画(画像の原点は左上)
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDHT, y_ + PLAYER_IMAGE_HEIGHT, hPlayerImage_, TRUE);
}
