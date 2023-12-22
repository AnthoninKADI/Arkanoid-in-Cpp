#pragma once
#include "Actor.h"
#include "RectCollisionComponent.h"
#include "Game.h"

class Rectangle4 : public Actor
{
public:
	Rectangle4();
	Game& game;

private:
	RectCollisionComponent* rect4Collider;
};

