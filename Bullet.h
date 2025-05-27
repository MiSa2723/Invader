#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet :
    public GameObject
{
private:
    int hBulletImage_;              //�e�̉摜�̃n���h��
    float x_, y_;                   //�e�̍��W
    float speed_;                   //�e�̈ړ����x
    int imageSize_x, imageSize_y;   //�e�̕\���T�C�Y
    bool isFired_;                  //

public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;
    void SetPosition(float x, float y);
    void SetFired(bool fired) { isFired_ = fired; } //���ˏ�Ԃ�ݒ�
    bool IsFired() const { return isFired_; }       //���ˏ�Ԃ��擾
    Rect GetRect() const { return { x_,y_,13.0f,33.0f }; }
};

