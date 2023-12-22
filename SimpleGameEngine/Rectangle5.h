#pragma once
#include "Actor.h"
#include "RectCollisionComponent.h"
#include "Game.h"

class Rectangle5 : public Actor
{
public:
	Rectangle5();
	Game& game;

private:
	RectCollisionComponent* rect5Collider;
};

