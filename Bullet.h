#pragma once
#include "GameObject.h"

class Bullet :
    public GameObject
{
private:
    int hBulletImage_;      //弾の画像のハンドル
    float x_, y_;           //弾の座標
    float speed_;           //弾の移動速度
    int imageSize_x, imageSize_y;   //弾の表示サイズ

public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y);
};

