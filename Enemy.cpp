#include "Enemy.h"
#include <DxLib.h>
#include <string>
#include "Effect.h"
#include "EnemyBeam.h"
//#include <assert.h>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;		//敵の画像の幅
	const int ENEMY_IMAGE_HEIGHT = 48;		//敵の画像の高さ
	const float ENEMY_INIT_X = 100;			//敵の初期X座標
	const float ENEMY_INIT_Y = 100;			//敵の初期Y座標
	const float ENEMY_INIT_SPEED = 100.0f;	//敵の初期移動速度
}

Enemy::Enemy()
	:GameObject(), hEnemyImage_(-1), x_(0), y_(0), speed_(0),
	imageSize_({ ENEMY_IMAGE_WIDTH ,ENEMY_IMAGE_HEIGHT }),moveTime_(0)
{
	hEnemyImage_ = LoadGraph("Assets\\画像\\tiny_ship10.png");	//敵の画像を読み込む
	if (hEnemyImage_ == -1)
	{
		//画像の読み込みに失敗したときにエラーメッセージを出す
	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	//idとtypeが指定されなかった時の処理をここに書かないと…
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(),hEnemyImage_(-1),x_(0),y_(0),speed_(0),ID_(id),type_(type),
	imageSize_({ ENEMY_IMAGE_WIDTH ,ENEMY_IMAGE_HEIGHT }),moveTime_(0)
{
	/*ETYPE::ZAKO=>"Assets\\画像\\tiny_ship10.png"
	ETYPE::MID=>"Assets\\画像\\tiny_ship16.png"
	ETYPE::KNIGHT=>"Assets\\画像\\tiny_ship9.png"
	ETYPE::BOSS=>"Assets\\画像\\tiny_ship18.png"*/

	//画像の読み込み
	std::string imagePath[MAX_ETYPE] =
	{
		"Assets\\画像\\tiny_ship10.png",	//ZAKO
		"Assets\\画像\\tiny_ship16.png",	//MID
		"Assets\\画像\\tiny_ship9.png",		//KNIGHT
		"Assets\\画像\\tiny_ship18.png"		//BOSS
	};
	
	hEnemyImage_ = LoadGraph(imagePath[type_].c_str());	//敵の画像を読み込む
	if (hEnemyImage_ == -1)
	{
		//画像の読み込みに失敗したときにエラーメッセージを出す
	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	
	AddGameObject(this);
}

Enemy::~Enemy()
{
	new Effect({ x_,y_ });
	if (hEnemyImage_ != -1)
	{
		DeleteGraph(hEnemyImage_);	//画像のハンドルを解放
	}
}

void Enemy::Update()
{
	static float beamTimer = 3.0f;

	float period = 10.0f;
	float omega = 2.0f * 3.14159265f / period;
	moveTime_ = moveTime_ + GetDeltaTime();
	x_ = xorigin_ + xMoveMax_ / 2.0 * sinf(omega * moveTime_);
	y_ = y_;

	if (beamTimer < 0)
	{
		new EnemyBeam(x_ + ENEMY_IMAGE_WIDTH / 2, y_ + ENEMY_IMAGE_HEIGHT);
		beamTimer = 3.0f;
	}

	beamTimer -= GetDeltaTime();
}

void Enemy::Draw()
{
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hEnemyImage_, TRUE);
}
