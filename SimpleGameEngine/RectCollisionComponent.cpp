#include "RectCollisionComponent.h"
#include "Actor.h"
#include "Paddle.h"
#include "Rectangle1.h"

RectCollisionComponent::RectCollisionComponent(Actor* ownerP, const Rectangle& boxP):
	Component(ownerP),
	box {boxP}
{
}

Vector2 RectCollisionComponent::getMin() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x - box.width / 2.0f;
	float y = pos.y + box.y - box.height / 2.0f;
	return Vector2(x, y);
}

Vector2 RectCollisionComponent::getMax() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2(x, y);
}

Vector2 RectCollisionComponent::paddleCollision() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2();
}

//collision Rectangle1
Vector2 RectCollisionComponent::Rectangle1Collision() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2();
}

//collision Rectangle2
Vector2 RectCollisionComponent::Rectangle2Collision() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2();
}

//collision Rectangle3
Vector2 RectCollisionComponent::Rectangle3Collision() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2();
}

//collision Rectangle4
Vector2 RectCollisionComponent::Rectangle4Collision() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2();
}

//collision Rectangle5
Vector2 RectCollisionComponent::Rectangle5Collision() const
{
	Vector2 pos = owner.getPosition();
	float x = pos.x + box.x + box.width / 2.0f;
	float y = pos.y + box.y + box.height / 2.0f;
	return Vector2();
}

bool Intersect(const RectCollisionComponent& a, const RectCollisionComponent& b)
{
	bool notColliding =
		// check a left non-collision
		a.getMin().x > b.getMax().x ||
		// check a right non - collision
		a.getMax().x < b.getMin().x ||
		// check a top non - collision
		a.getMin().y > b.getMax().y ||
		// check a bot non - collision
		a.getMax().y < b.getMin().y;

	return !notColliding;
}
