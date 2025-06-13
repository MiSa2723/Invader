#include "globals.h"
#include "Bullet.h"
#include <DxLib.h>
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13;		//弾の画像の幅
	const int BULLET_IMAGE_HEIGHT = 33;		//弾の画像の高さ
	const float BULLET_INIT_SPEED = 200.0f;	//弾の初期移動速度
	const std::string BULLET_IMAGE_PATH = "Assets\\画像\\laserBlue01.png";	//弾の画像パス
}

Bullet::Bullet()
	:GameObject(),hBulletImage_(-1),x_(0),y_(0),
	imageSize_({ BULLET_IMAGE_WIDTH ,BULLET_IMAGE_HEIGHT }),isFired_(false)
{
	hBulletImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());	//弾の画像を読み込む
	speed_ = BULLET_INIT_SPEED;	//移動速度
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hBulletImage_(-1), x_(x), y_(y), 
	imageSize_({ BULLET_IMAGE_WIDTH ,BULLET_IMAGE_HEIGHT }), isFired_(false)
{
	hBulletImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());	//弾の画像を読み込む
	speed_ = BULLET_INIT_SPEED;	//移動速度
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hBulletImage_ != -1)
	{
		DeleteGraph(hBulletImage_);	//画像の解放
	}
	hBulletImage_ = -1;	//画像ハンドルを無効化
}

void Bullet::Update()
{
	float dt = GetDeltaTime();	//デルタタイムの取得
	y_ = y_ - (speed_ * dt);	//弾の移動
	if (y_ < 0)
	{
		isFired_ = false;		//画面外に出たら準備状態に戻す
	}
}

void Bullet::Draw()
{
	//発射されていたら描画
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hBulletImage_, TRUE);	//弾の描画
	}
}

void Bullet::SetPosition(float x, float y)
{
	x_ = x;
	y_ = y;
}
