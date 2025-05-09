#include "Enemy.h"
#include <DxLib.h>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;		//敵の画像の幅
	const int ENEMY_IMAGE_HEIGHT = 48;		//敵の画像の高さ
	const float ENEMY_INIT_X = 100;			//敵の初期X座標
	const float ENEMY_INIT_Y = 100;			//敵の初期Y座標
	const float ENEMY_INIT_SPEED = 100.0f;	//敵の初期移動速度
}

Enemy::Enemy()
	:GameObject(), hEnemyImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true)
{
	hEnemyImage_ = LoadGraph("Assets\\画像\\tiny_ship10.png");	//敵の画像を読み込む
	if (hEnemyImage_ == -1)
	{
		//画像の読み込みに失敗したときにエラーメッセージを出す
	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
}

Enemy::~Enemy()
{
	if (hEnemyImage_ != -1)
	{
		DeleteGraph(hEnemyImage_);	//画像のハンドルを解放
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hEnemyImage_, TRUE);
}
