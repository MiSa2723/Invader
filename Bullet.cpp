#include "globals.h"
#include "Bullet.h"
#include <DxLib.h>
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13;		//�e�̉摜�̕�
	const int BULLET_IMAGE_HEIGHT = 33;		//�e�̉摜�̍���
	const float BULLET_INIT_SPEED = 200.0f;	//�e�̏����ړ����x
	const std::string BULLET_IMAGE_PATH = "Assets\\�摜\\laserBlue01.png";	//�e�̉摜�p�X
}

Bullet::Bullet()
	:GameObject(),hBulletImage_(-1),x_(0),y_(0),
	imageSize_({ BULLET_IMAGE_WIDTH ,BULLET_IMAGE_HEIGHT }),isFired_(false)
{
	hBulletImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());	//�e�̉摜��ǂݍ���
	speed_ = BULLET_INIT_SPEED;	//�ړ����x
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hBulletImage_(-1), x_(x), y_(y), 
	imageSize_({ BULLET_IMAGE_WIDTH ,BULLET_IMAGE_HEIGHT }), isFired_(false)
{
	hBulletImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());	//�e�̉摜��ǂݍ���
	speed_ = BULLET_INIT_SPEED;	//�ړ����x
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hBulletImage_ != -1)
	{
		DeleteGraph(hBulletImage_);	//�摜�̉��
	}
	hBulletImage_ = -1;	//�摜�n���h���𖳌���
}

void Bullet::Update()
{
	float dt = GetDeltaTime();	//�f���^�^�C���̎擾
	y_ = y_ - (speed_ * dt);	//�e�̈ړ�
	if (y_ < 0)
	{
		isFired_ = false;		//��ʊO�ɏo���珀����Ԃɖ߂�
	}
}

void Bullet::Draw()
{
	//���˂���Ă�����`��
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hBulletImage_, TRUE);	//�e�̕`��
	}
}

void Bullet::SetPosition(float x, float y)
{
	x_ = x;
	y_ = y;
}
