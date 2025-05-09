#pragma once
#include "GameObject.h"


class Enemy :
    public GameObject
{
    int hEnemyImage_;   //�摜�̃n���h��
    float x_, y_;       //�v���C���[�̍��W
    float speed_;       //�v���C���[�̈ړ����x
    bool isAlive_;      //�G�̐���

public:
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y) { x_ = x; y_ = y; }  //�G�̍��W���擾
};

