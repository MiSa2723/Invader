#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
    int hEnemyImage_;  //�摜�̃n���h��
    float x_, y_;       //�v���C���[�̍��W
    float speed_;       //�v���C���[�̈ړ����x

public:
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
};

