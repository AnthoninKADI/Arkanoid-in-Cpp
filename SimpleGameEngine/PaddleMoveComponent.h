#pragma once
#include "MoveComponent.h"

class PaddleMoveComponent : public MoveComponent
{
public:
    PaddleMoveComponent(Actor* ownerP, int updateOrder = 10);

    float getForwardSpeed() const { return forwardSpeed; }
    float getAngularSpeed() const { return angularSpeed; }

    void setForwardSpeed(float forwardSpeedP);
    void setAngularSpeed(float angularSpeedP);

    void update(float dt) override;

private:
    float forwardSpeed;
    float angularSpeed;
};
