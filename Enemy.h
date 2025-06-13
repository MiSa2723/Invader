#pragma once
#include "GameObject.h"
#include "globals.h"

enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
};

class Enemy :
    public GameObject
{
public:
    Enemy();
    Enemy(int id,ETYPE type);
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y) { x_ = x; y_ = y; }  //敵の座標を取得
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; }
    //void SetID(int id) { ID_ = id; }                        //敵のIDを設定
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    //std::vector<EnemyBeam*> GetAllBullets() const { return eneBeam_; }  //全ての弾を取得

protected:

private:
    int hEnemyImage_;   //画像のハンドル
    float x_, y_;       //敵の座標
    float speed_;       //敵の移動速度
    Point imageSize_;
    float xMoveMax_;
    float xorigin_;
    float moveTime_;

    int ID_;            //敵のID
    ETYPE type_;        //敵の種類

    //std::vector<EnemyBeam*> eneBeam_; //エネミーが発射した弾のベクター
};

