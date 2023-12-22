#include "Rectangle1.h"

Rectangle1::Rectangle1() : game(Game::instance())
{
    rect1Collider = new RectCollisionComponent(this, Rectangle{ game.RectPos1.x, game.RectPos1.y, game.rectWidth, game.rectHeight }); // Adjust the size as needed

    int windowWidth = Game::instance().getWindow().getWidth();
    int windowHeight = Game::instance().getWindow().getHeight();

    setPosition(Vector2(windowWidth / 2, windowHeight - 30));
    SetScale(100); // Adjust the size as needed

    Game::instance().addActor(this);
}
