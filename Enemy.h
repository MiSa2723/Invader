#pragma once
#include "GameObject.h"

enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
};

class Enemy :
    public GameObject
{
    int hEnemyImage_;   //画像のハンドル
    float x_, y_;       //プレイヤーの座標
    float speed_;       //プレイヤーの移動速度
    bool isAlive_;      //敵の生死
    int ID_;            //敵のID
    ETYPE type_;        //敵の種類

public:
    Enemy();
    Enemy(int id,ETYPE type);
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y) { x_ = x; y_ = y; }  //敵の座標を取得
    //void SetID(int id) { ID_ = id; }                        //敵のIDを設定
};

