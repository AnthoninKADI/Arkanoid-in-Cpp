#pragma once
#include "Actor.h"
#include "RectCollisionComponent.h"
#include "Game.h"

class Rectangle2 : public Actor
{
public:
	Rectangle2();
	Game& game;

private:
	RectCollisionComponent* rect2Collider;
};

