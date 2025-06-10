#pragma once
#include "GameObject.h"
#include "globals.h"

class EnemyBeam :
    public GameObject
{

public:
    EnemyBeam();
    EnemyBeam(float x, float y);
    EnemyBeam(Point pos_);;
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    void SetPosition(float x, float y) { pos_.x = x; pos_.y = y; }  //座標設定
    void SetPosition(const Point& pos) { pos_ = pos; }              //座標設定
    void SetFired(bool fired) { isFired_ = fired; }                 //発射状態を設定
    bool IsFired() const { return isFired_; }                       //発射状態を取得
    Rect GetRect() const { return { pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }

private:
    int hImage_;                        //弾の画像のハンドル
    Point pos_;                         //弾の座標を保持するためのPoint構造体
    float speed_;                       //弾の移動速度
    Point imageSize_;
    //int imageSize_x, imageSize_y;     //弾の表示サイズ
    bool isFired_;                      //発射されているかどうか　true:されている　false:されていない
}; 

