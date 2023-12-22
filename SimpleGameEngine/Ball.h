#pragma once
#include "Actor.h"
#include "DrawCircleComponent.h"
#include "MoveComponent.h"
#include "RectCollisionComponent.h"

class Ball :
    public Actor
{
public:
    Ball();
    Game& game;
    void updateActor(float dt) override;

private:
    DrawCircleComponent* drawCircle{ nullptr };
    RectCollisionComponent* collider{ nullptr };
    MoveComponent* move{ nullptr };
};

