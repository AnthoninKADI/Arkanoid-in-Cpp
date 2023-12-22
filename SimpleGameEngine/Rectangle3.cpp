#include "Rectangle3.h"

Rectangle3::Rectangle3() : game(Game::instance())
{
    rect3Collider = new RectCollisionComponent(this, Rectangle{ game.RectPos3.x, game.RectPos3.y, game.rectWidth, game.rectHeight }); // Adjust the size as needed

    int windowWidth = Game::instance().getWindow().getWidth();
    int windowHeight = Game::instance().getWindow().getHeight();

    setPosition(Vector2(windowWidth / 2, windowHeight - 30));
    SetScale(100); // Adjust the size as needed

    Game::instance().addActor(this);
}
