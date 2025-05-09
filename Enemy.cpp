#include "Enemy.h"
#include <DxLib.h>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;		//�G�̉摜�̕�
	const int ENEMY_IMAGE_HEIGHT = 48;		//�G�̉摜�̍���
	const float ENEMY_INIT_X = 100;			//�G�̏���X���W
	const float ENEMY_INIT_Y = 100;			//�G�̏���Y���W
	const float ENEMY_INIT_SPEED = 100.0f;	//�G�̏����ړ����x
}

Enemy::Enemy()
	:GameObject(), hEnemyImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true)
{
	hEnemyImage_ = LoadGraph("Assets\\�摜\\tiny_ship10.png");	//�G�̉摜��ǂݍ���
	if (hEnemyImage_ == -1)
	{
		//�摜�̓ǂݍ��݂Ɏ��s�����Ƃ��ɃG���[���b�Z�[�W���o��
	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
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
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hEnemyImage_, TRUE);
}
