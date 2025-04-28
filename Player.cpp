#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"

namespace
{
	const float PLAYER_INIT_SPEED = 200.0f;	//�v���C���[�̑��x
	const int PLAYER_IMAGE_WIDHT = 48;		//�v���C���[�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;		//�v���C���[�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;		//�v���C���[�̊�}�[�W��

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDHT / 2;	//�v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//�v���C���[�̏���Y���W
}

Player::Player()
	:GameObject(),hPlayerImage_(-1),x_(0),y_(0),speed_(0)
{
	hPlayerImage_ = LoadGraph("Assets\\�摜\\tiny_ship5.png"); //�v���C���[�̉摜�ǂݍ���
	if (hPlayerImage_ == 1)
	{
		//�G���[��Ԃ��ăQ�[���I��
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
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ -= speed_ * GetDeltaTime();	//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ += speed_ * GetDeltaTime();	//�E�Ɉړ�
	}
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDHT, y_ + PLAYER_IMAGE_HEIGHT, hPlayerImage_, TRUE);
}
