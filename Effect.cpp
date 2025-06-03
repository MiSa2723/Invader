#include "Effect.h"
#include <DxLib.h>

namespace
{
	float ANIME_TIME = { 3.0f };
}

Effect::Effect(Point _pos)
	:GameObject(), pos_({ _pos.x, _pos.y}), hImage_(-1),animeTimer_(ANIME_TIME)
{
	hImage_ = LoadGraph("Assets\\‰æ‘œ\\explosion.png");
	AddGameObject(this);
}

Effect::~Effect()
{
	DeleteGraph(hImage_);
}

void Effect::Update()
{
	float dt = GetDeltaTime();
	animeTimer_ = animeTimer_ - dt;
	if (animeTimer_ < 0)
	{
		this->isAlive_ = false;
	}
}

void Effect::Draw()
{
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x + 48, pos_.y + 48, hImage_, TRUE);
}
