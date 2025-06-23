#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"
#include "Bullet.h"

namespace
{
	const float PLAYER_INIT_SPEED = 250.0f;	//プレイヤーの速度
	const int PLAYER_IMAGE_WIDHT = 48;		//プレイヤーの画像の幅
	const int PLAYER_IMAGE_HEIGHT = 48;		//プレイヤーの画像の高さ
	const int PLAYER_BASE_MARGIN = 32;		//プレイヤーの基準マージン

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDHT / 2;	//プレイヤーの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//プレイヤーの初期Y座標
	const int BULLET_IMAGE_MARGIN = 17;		//弾の基準マージン
	const float BULLET_INTERVAL = 0.5f;		//弾の発射間隔
	const int PLAYER_BULLET_NUM = 5;		//プレイヤーが発射できる弾の数
}


Player::Player()
	:GameObject(),hPlayerImage_(-1),x_(0),y_(0),speed_(0),imageSize_({ PLAYER_IMAGE_WIDHT ,PLAYER_IMAGE_HEIGHT })
{
	hPlayerImage_ = LoadGraph("Assets\\画像\\tiny_ship5.png"); //プレイヤーの画像読み込み
	if (hPlayerImage_ == -1)
	{
		//エラーを返してゲーム終了
	}
	x_ = PLAYER_INIT_X;	//初期座標
	y_ = PLAYER_INIT_Y;	//初期座標
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0; i < PLAYER_BULLET_NUM; i++)
	{
		bullets_.push_back(new Bullet());	//弾のベクターを初期化
	}
	AddGameObject(this);
}

Player::~Player()
{
	//画像のサイズを開放　後で書いて
}

void Player::Update()
{
	Point nextPoint = { x_,y_ };
	float dt = GetDeltaTime();	//フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		nextPoint.x = x_ - speed_ * dt;	//左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		nextPoint.x = x_ + speed_ * dt;	//右に移動
	}

	if (nextPoint.x >= 0 && (nextPoint.x + PLAYER_IMAGE_WIDHT) <= WIN_WIDTH)
	{
		x_ = nextPoint.x;
		y_ = nextPoint.y;
	}

	static float bulletTimer = 0.0f;	//弾の発射タイマー

	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;	//タイマーを減らす
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot();									//弾を発射
			//new Bullet(x_ + BULLET_IMAGE_MARGIN, y_);	//弾を発射
			bulletTimer = BULLET_INTERVAL;				//弾の発射間隔をリセット
		}
	}
}

void Player::Draw()
{
	//プレイヤーの画像を描画(画像の原点は左上)
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDHT, y_ + PLAYER_IMAGE_HEIGHT, hPlayerImage_, TRUE);


	DrawFormatString(100, 100, GetColor(255, 255, 0), "Player Draw!");
}

void Player::Shoot()	//弾を撃つ関数
{
	/*for (auto& itr : bullets_)
	{
		if (itr->IsFired() == false)
		{
			itr->SetPosition(x_ + BULLET_IMAGE_MARGIN, y_);
			itr->SetFired(true);
		}
	}*/
	
	Bullet* blt = GetActiveBullet();
	if (blt != nullptr)
	{
		blt->SetPosition(x_ + BULLET_IMAGE_MARGIN, y_);
		blt->SetFired(true);
	}
}

Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr;	//発射されていない弾を返す
		}
	}
	return nullptr;
}

