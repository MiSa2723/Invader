#include <DxLib.h>
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

namespace
{
	const int ENEMY_NUM = 10 * 7;		//敵の数
	const int ENEMY_COLUMN_SIZE = 10;	//敵の列数
	const int ENEMY_ROW_SIZE = 7;		//敵の行数
	bool IntersectRect(const Rect& a, const Rect& b)
	{
		//x軸方向の当たり判定
		bool xOverlap = (a.x < b.x + b.width) && (b.x < a.x + a.width);

		//y軸方向の当たり判定
		bool yOverlap = (a.y < b.y + b.height) && (b.y < a.y + a.height);

		//x軸とy軸の両方の当たり判定
		return xOverlap && yOverlap;
	}
}

Stage::Stage()
	:GameObject(),player_(nullptr),hBackground_(-1)
{
	AddGameObject(this);	//ステージオブジェクトをゲームオブジェクトに
	player_ = new Player();	//プレイヤーオブジェクトの生成
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COLUMN_SIZE;					//列
		int row = i / ENEMY_COLUMN_SIZE;					//行
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO,ZAKO };	//敵の種類
		enemy_[i] = new Enemy(i, enemyType[row]);			//敵オブジェクトの生成
		enemy_[i]->SetPosition(col * 55.0f, row * 50.0f);	//敵の初期位置を決定
	}
	hBackground_ = LoadGraph("Assets\\画像\\bg.png");
}

Stage::~Stage()
{
}

void Stage::Update()
{
	std::vector<Bullet*> bullets = player_->GetAllBullets();
	for (auto &e : enemy_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFired() && e->IsAlive())
			{
				if (IntersectRect(e->GetRect(), b->GetRect()))
				{
					if (b->IsFired())
					{
						b->SetFired(false);
					}
					if (e->IsAlive())
					{
						e->SetAlive(false);
					}
				}
			}
		}
	}
}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackground_, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
