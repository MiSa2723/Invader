#include "Enemy.h"
#include <DxLib.h>
#include <string>
//#include <assert.h>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;		//�G�̉摜�̕�
	const int ENEMY_IMAGE_HEIGHT = 48;		//�G�̉摜�̍���
	const float ENEMY_INIT_X = 100;			//�G�̏���X���W
	const float ENEMY_INIT_Y = 100;			//�G�̏���Y���W
	const float ENEMY_INIT_SPEED = 100.0f;	//�G�̏����ړ����x
}

Enemy::Enemy()
	:GameObject(), hEnemyImage_(-1), x_(0), y_(0), speed_(0)
{
	hEnemyImage_ = LoadGraph("Assets\\�摜\\tiny_ship10.png");	//�G�̉摜��ǂݍ���
	if (hEnemyImage_ == -1)
	{
		//�摜�̓ǂݍ��݂Ɏ��s�����Ƃ��ɃG���[���b�Z�[�W���o��
	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	//id��type���w�肳��Ȃ��������̏����������ɏ����Ȃ��Ɓc
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(),hEnemyImage_(-1),x_(0),y_(0),speed_(0),ID_(id),type_(type)
{
	/*ETYPE::ZAKO=>"Assets\\�摜\\tiny_ship10.png"
	ETYPE::MID=>"Assets\\�摜\\tiny_ship16.png"
	ETYPE::KNIGHT=>"Assets\\�摜\\tiny_ship9.png"
	ETYPE::BOSS=>"Assets\\�摜\\tiny_ship18.png"*/

	//�摜�̓ǂݍ���
	std::string imagePath[MAX_ETYPE] =
	{
		"Assets\\�摜\\tiny_ship10.png",	//ZAKO
		"Assets\\�摜\\tiny_ship16.png",	//MID
		"Assets\\�摜\\tiny_ship9.png",		//KNIGHT
		"Assets\\�摜\\tiny_ship18.png"		//BOSS
	};
	
	hEnemyImage_ = LoadGraph(imagePath[type_].c_str());	//�G�̉摜��ǂݍ���
	if (hEnemyImage_ == -1)
	{
		//�摜�̓ǂݍ��݂Ɏ��s�����Ƃ��ɃG���[���b�Z�[�W���o��
	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	AddGameObject(this);					//�G�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[
}

Enemy::~Enemy()
{
	if (hEnemyImage_ != -1)
	{
		DeleteGraph(hEnemyImage_);	//�摜�̃n���h�������
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hEnemyImage_, TRUE);
}
