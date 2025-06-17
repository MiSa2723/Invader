#pragma once
#include "GameObject.h"

enum SCENESTATE
{
    TITLE,
    PLAY,
    GAMEOVER,
    MAX_SCENESTATE
};

class SceneTransition :
    public GameObject
{
public:
    SceneTransition();
    ~SceneTransition();
    void Update() override;
    void Draw() override;

protected:

private:
    int state_;
};

