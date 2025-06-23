#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"
#include "Bullet.h"

namespace
{
	const float PLAYER_INIT_SPEED = 250.0f;	//�v���C���[�̑��x
	const int PLAYER_IMAGE_WIDHT = 48;		//�v���C���[�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;		//�v���C���[�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;		//�v���C���[�̊�}�[�W��

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDHT / 2;	//�v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//�v���C���[�̏���Y���W
	const int BULLET_IMAGE_MARGIN = 17;		//�e�̊�}�[�W��
	const float BULLET_INTERVAL = 0.5f;		//�e�̔��ˊԊu
	const int PLAYER_BULLET_NUM = 5;		//�v���C���[�����˂ł���e�̐�
}


Player::Player()
	:GameObject(),hPlayerImage_(-1),x_(0),y_(0),speed_(0),imageSize_({ PLAYER_IMAGE_WIDHT ,PLAYER_IMAGE_HEIGHT })
{
	hPlayerImage_ = LoadGraph("Assets\\�摜\\tiny_ship5.png"); //�v���C���[�̉摜�ǂݍ���
	if (hPlayerImage_ == -1)
	{
		//�G���[��Ԃ��ăQ�[���I��
	}
	x_ = PLAYER_INIT_X;	//�������W
	y_ = PLAYER_INIT_Y;	//�������W
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0; i < PLAYER_BULLET_NUM; i++)
	{
		bullets_.push_back(new Bullet());	//�e�̃x�N�^�[��������
	}
	AddGameObject(this);
}

Player::~Player()
{
	//�摜�̃T�C�Y���J���@��ŏ�����
}

void Player::Update()
{
	Point nextPoint = { x_,y_ };
	float dt = GetDeltaTime();	//�t���[���Ԃ̎��ԍ����擾
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		nextPoint.x = x_ - speed_ * dt;	//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		nextPoint.x = x_ + speed_ * dt;	//�E�Ɉړ�
	}

	if (nextPoint.x >= 0 && (nextPoint.x + PLAYER_IMAGE_WIDHT) <= WIN_WIDTH)
	{
		x_ = nextPoint.x;
		y_ = nextPoint.y;
	}

	static float bulletTimer = 0.0f;	//�e�̔��˃^�C�}�[

	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;	//�^�C�}�[�����炷
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot();									//�e�𔭎�
			//new Bullet(x_ + BULLET_IMAGE_MARGIN, y_);	//�e�𔭎�
			bulletTimer = BULLET_INTERVAL;				//�e�̔��ˊԊu�����Z�b�g
		}
	}
}

void Player::Draw()
{
	//�v���C���[�̉摜��`��(�摜�̌��_�͍���)
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDHT, y_ + PLAYER_IMAGE_HEIGHT, hPlayerImage_, TRUE);


	DrawFormatString(100, 100, GetColor(255, 255, 0), "Player Draw!");
}

void Player::Shoot()	//�e�����֐�
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
			return itr;	//���˂���Ă��Ȃ��e��Ԃ�
		}
	}
	return nullptr;
}

