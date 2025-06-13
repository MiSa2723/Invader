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
    void SetPosition(float x, float y) { x_ = x; y_ = y; }  //�G�̍��W���擾
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; }
    //void SetID(int id) { ID_ = id; }                        //�G��ID��ݒ�
    void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    //std::vector<EnemyBeam*> GetAllBullets() const { return eneBeam_; }  //�S�Ă̒e���擾

protected:

private:
    int hEnemyImage_;   //�摜�̃n���h��
    float x_, y_;       //�G�̍��W
    float speed_;       //�G�̈ړ����x
    Point imageSize_;
    float xMoveMax_;
    float xorigin_;
    float moveTime_;

    int ID_;            //�G��ID
    ETYPE type_;        //�G�̎��

    //std::vector<EnemyBeam*> eneBeam_; //�G�l�~�[�����˂����e�̃x�N�^�[
};

