#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet :
    public GameObject
{
private:
    int hBulletImage_;              //弾の画像のハンドル
    float x_, y_;                   //弾の座標
    float speed_;                   //弾の移動速度
    int imageSize_x, imageSize_y;   //弾の表示サイズ
    bool isFired_;                  //

public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y);
    void SetFired(bool fired) { isFired_ = fired; } //発射状態を設定
    bool IsFired() const { return isFired_; }       //発射状態を取得
    Rect GetRect() const { return { x_,y_,13.0f,33.0f }; }
};

