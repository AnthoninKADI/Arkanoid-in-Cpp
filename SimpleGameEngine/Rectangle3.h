#pragma once
#include "Actor.h"
#include "RectCollisionComponent.h"
#include "Game.h"

class Rectangle3 : public Actor
{
public:
	Rectangle3();
	Game& game;

private:
	RectCollisionComponent* rect3Collider;
};

