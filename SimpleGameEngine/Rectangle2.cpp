#include "Rectangle2.h"

Rectangle2::Rectangle2() : game(Game::instance())
{
    rect2Collider = new RectCollisionComponent(this, Rectangle{ game.RectPos2.x, game.RectPos2.y, game.rectWidth, game.rectHeight }); // Adjust the size as needed

    int windowWidth = Game::instance().getWindow().getWidth();
    int windowHeight = Game::instance().getWindow().getHeight();

    setPosition(Vector2(windowWidth / 2, windowHeight - 30));
    SetScale(100); // Adjust the size as needed

    Game::instance().addActor(this);
}
