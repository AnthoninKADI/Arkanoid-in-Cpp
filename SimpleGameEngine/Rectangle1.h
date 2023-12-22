#pragma once
#include "Actor.h"
#include "RectCollisionComponent.h"
#include "Game.h"

class Rectangle1 : public Actor
{
public: 
	Rectangle1();
	Game& game;

private:
	RectCollisionComponent* rect1Collider;
};

