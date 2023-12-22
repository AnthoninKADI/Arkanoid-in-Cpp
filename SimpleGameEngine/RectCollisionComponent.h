#pragma once
#include "Component.h"
#include "Rectangle.h"
#include "Vector2.h"

class RectCollisionComponent : public Component
{
public:
	RectCollisionComponent(Actor* ownerP, const Rectangle& boxP);
	virtual ~RectCollisionComponent() = default;

	RectCollisionComponent() = delete;

	Vector2 getMin() const;
	Vector2 getMax() const;
	Vector2 paddleCollision() const;
	Vector2 Rectangle1Collision() const;
	Vector2 Rectangle2Collision() const;
	Vector2 Rectangle3Collision() const;
	Vector2 Rectangle4Collision() const;
	Vector2 Rectangle5Collision() const;

private:
	Rectangle box{ 0, 0, 1, 1 };
};

bool Intersect(const RectCollisionComponent& a, const RectCollisionComponent& b);

