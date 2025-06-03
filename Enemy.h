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
    void SetPosition(float x, float y) { x_ = x; y_ = y; }  //“G‚ÌÀ•W‚ğæ“¾
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; }
    //void SetID(int id) { ID_ = id; }                        //“G‚ÌID‚ğİ’è

protected:

private:
    int hEnemyImage_;   //‰æ‘œ‚Ìƒnƒ“ƒhƒ‹
    float x_, y_;       //“G‚ÌÀ•W
    float speed_;       //“G‚ÌˆÚ“®‘¬“x
    Point imageSize_;

    int ID_;            //“G‚ÌID
    ETYPE type_;        //“G‚Ìí—Ş
};

