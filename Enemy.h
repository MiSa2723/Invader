#pragma once
#include "GameObject.h"

enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
};

class Enemy :
    public GameObject
{
    int hEnemyImage_;   //�摜�̃n���h��
    float x_, y_;       //�v���C���[�̍��W
    float speed_;       //�v���C���[�̈ړ����x
    bool isAlive_;      //�G�̐���
    int ID_;            //�G��ID
    ETYPE type_;        //�G�̎��

public:
    Enemy();
    Enemy(int id,ETYPE type);
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y) { x_ = x; y_ = y; }  //�G�̍��W���擾
    //void SetID(int id) { ID_ = id; }                        //�G��ID��ݒ�
};

