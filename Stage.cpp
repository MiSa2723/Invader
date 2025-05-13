#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10 * 7;			//�G�̐�
	const int ENEMY_COLUMN_SIZE = 10;	//�G�̗�
	const int ENEMY_ROW_SIZE = 7;		//�G�̍s��
}

Stage::Stage()
	:GameObject(),player_(nullptr)
{
	player_ = new Player();	//�v���C���[�I�u�W�F�N�g�̐���
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COLUMN_SIZE;					//��
		int row = i / ENEMY_ROW_SIZE;						//�s
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO,ZAKO };	//�G�̎��
		enemy_[i] = new Enemy(i, (ETYPE)enemyType[row]);	//�G�I�u�W�F�N�g�̐���
		enemy_[i]->SetPosition(col * 55, row * 50);			//�G�̏����ʒu������
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update();	//�v���C���[�̍X�V
	for (auto& elm : enemy_)
	{
		elm->Update();	//�G�̍X�V
	}
}

void Stage::Draw()
{
	player_->Draw();	//�v���C���[�̕`��
	for (auto& elm : enemy_)
	{
		elm->Draw();	//�G�̕`��
	}
}
