#pragma once
#include "GameObject.h"
#include "globals.h"

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
    int hImage_;
    Point pos_;
    float animeTimer_;
};

