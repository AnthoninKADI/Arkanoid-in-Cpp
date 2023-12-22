#include "Paddle.h"

Paddle::Paddle() : game(Game::instance())
{
    paddleMove = new PaddleMoveComponent(this);
    collider = new RectCollisionComponent(this, Rectangle{game.paddlePos.x, game.paddlePos.y, game.paddleWidth, game.paddleHeight}); // Adjust the size as needed

    int windowWidth = Game::instance().getWindow().getWidth();
    int windowHeight = Game::instance().getWindow().getHeight();

    setPosition(Vector2(windowWidth / 2, windowHeight - 150));
    SetScale(300); // Adjust the size as needed

    Game::instance().addActor(this);
}


