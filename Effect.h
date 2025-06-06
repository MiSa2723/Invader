#pragma once
#include "GameObject.h"
#include "globals.h"
#include <vector>

class Effect :
    public GameObject
{
public:
    Effect(Point _pos);
    ~Effect();
    void Update() override;
    void Draw() override;

protected:

private:
    std::vector<int> hImage_;
    Point pos_;
    float animeTimer_;  //�G�t�F�N�g�̎���
    float frameTimer_;  //�t���[���̃^�C�}�[
    int frame_;         //�t���[���̃R�}�ԍ�
};

