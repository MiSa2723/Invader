#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
    int hEnemyImage_;  //画像のハンドル
    float x_, y_;       //プレイヤーの座標
    float speed_;       //プレイヤーの移動速度

public:
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
};

