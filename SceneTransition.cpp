#include "SceneTransition.h"
#include "Stage.h"
#include <DxLib.h>

SceneTransition::SceneTransition()
	:state_(0)
{
	state_ = TITLE;
}

SceneTransition::~SceneTransition()
{

}

void SceneTransition::Update()
{
	if (state_ == TITLE)
	{
		if (CheckHitKey(KEY_INPUT_S))
		{
			state_ = PLAY;
			Stage* stage = new Stage();
		}
	}
	if (state_ == PLAY)
	{

	}
}

void SceneTransition::Draw()
{
	if (state_ == TITLE)
	{
		DrawFormatString(100, 100, GetColor(0, 0, 0), "Invader Game");
	}
	//DrawFormatString(100, 200, GetColor(0, 0, 0), "Invader Game");
}
