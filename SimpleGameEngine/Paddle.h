#pragma once
#include "Actor.h"
#include "PaddleMoveComponent.h"
#include "RectCollisionComponent.h"
#include "Game.h"

class Paddle : public Actor
{
public:
    Paddle();
    Game& game;

private:
    PaddleMoveComponent* paddleMove;
    RectCollisionComponent* collider;
};
