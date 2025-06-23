#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "SceneTransition.h"
#include "Stage.h"

namespace
{
	const int BGCOLOR[3] = { 30,30,30 };	//背景色
	int crrTime;
	int prevTime;
}


enum class GameState 
{
	TITLE,
	PLAY,
	GAMEOVER
};


void DrawTitleScreen() 
{
	DrawFormatString(300, 200, GetColor(255, 255, 255), "インベーダーゲーム");
	DrawFormatString(300, 250, GetColor(255, 255, 255), "スペースキーでスタート");
}

void DrawGameOverScreen() 
{
	DrawFormatString(300, 200, GetColor(255, 0, 0), "ゲームオーバー");
	DrawFormatString(300, 250, GetColor(255, 255, 255), "Rキーでリトライ / Tキーでタイトルへ");
}



std::vector<GameObject*> gameObjects;		//ゲームオブジェクトのベクター
std::vector<GameObject*> newObjects;		//ゲームオブジェクトのベクター


float gDeltaTime = 0.0f;	//フレーム間の時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0], BGCOLOR[1], BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	GameState gameState = GameState::TITLE;
	Stage* stage = nullptr;

	//Stage* stage = new Stage();
	//SceneTransition* scene = new SceneTransition();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();	//キー入力の状態を更新

		crrTime = GetNowCount();	//現在の時間を取得
		//前回の時間との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f;	//秒単位に変換
		gDeltaTime = deltaTime;		//グローバル変数に保存


		switch (gameState)
		{
		case GameState::TITLE:
			DrawTitleScreen();
			if (CheckHitKey(KEY_INPUT_SPACE)) {
				stage = new Stage();
				gameState = GameState::PLAY;
			}
			break;

		case GameState::PLAY:
			DrawFormatString(10, 10, GetColor(255, 255, 255), "gameObjects: %d", gameObjects.size());
			// ゲームオブジェクトの追加・更新・描画処理
			// ↓ここにゲームオーバー判定を追加
			if (stage->IsGameOver()) {
				gameState = GameState::GAMEOVER;
			}
			break;

		case GameState::GAMEOVER:
			DrawGameOverScreen();
			if (CheckHitKey(KEY_INPUT_R)) {
				delete stage;
				stage = new Stage();
				gameState = GameState::PLAY;
			}
			else if (CheckHitKey(KEY_INPUT_T)) {
				delete stage;
				gameObjects.clear();
				gameState = GameState::TITLE;
			}
			break;
		}
		//*/

		/*//ゲームオブジェクトの追加
		if (newObjects.size() > 0)
		{
			for (auto& obj : newObjects)
			{
				gameObjects.push_back(obj);	//新しいゲームオブジェクトを追加
			}
			newObjects.clear();				//新しいゲームオブジェクトのベクターをクリア
		}

		//gameObjecsの更新
		for (auto& obj : gameObjects)
		{
			obj->Update();		//ゲームオブジェクトの更新
		}

		//gameObjectsの描画
		for (auto& obj : gameObjects)
		{
			obj->Draw();		//ゲームオブジェクトの描画
		}

		for (auto it = gameObjects.begin(); it != gameObjects.end();)
		{
			if (!(*it)->IsAlive())
			{
				delete* it;					//ゲームオブジェクトを削除
				it = gameObjects.erase(it);	//ベクターから削除
			}
			else
			{
				++it;	//次の要素へ
			}
		}
		:*/

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime;	//現在の時間を前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}