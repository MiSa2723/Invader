#pragma once
#include "GameObject.h"

class Bullet :
    public GameObject
{
private:
    int hBulletImage_;      //�e�̉摜�̃n���h��
    float x_, y_;           //�e�̍��W
    float speed_;           //�e�̈ړ����x
    int imageSize_x, imageSize_y;   //�e�̕\���T�C�Y

public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y);
};

