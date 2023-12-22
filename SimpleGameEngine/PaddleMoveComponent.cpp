#include "PaddleMoveComponent.h"
#include "Maths.h"
#include "Actor.h"

PaddleMoveComponent::PaddleMoveComponent(Actor* ownerP, int updateOrderP)
    : MoveComponent(ownerP, updateOrderP), forwardSpeed(0.0f), angularSpeed(0.0f)
{
}

void PaddleMoveComponent::setForwardSpeed(float forwardSpeedP)
{
    forwardSpeed = forwardSpeedP;
}

void PaddleMoveComponent::setAngularSpeed(float angularSpeedP)
{
    angularSpeed = angularSpeedP;
}

void PaddleMoveComponent::update(float dt)
{
    if (!Maths::nearZero(angularSpeed))
    {
        float newRotation = owner.getRotation() + angularSpeed * dt;
        owner.setRotation(newRotation);
    }
    if (!Maths::nearZero(forwardSpeed))
    {
        Vector2 newPosition = owner.getPosition() + owner.getForward() * forwardSpeed * dt;
        owner.setPosition(newPosition);
    }
}
