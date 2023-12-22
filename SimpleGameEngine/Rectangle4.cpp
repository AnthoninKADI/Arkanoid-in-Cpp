#include "Rectangle4.h"

Rectangle4::Rectangle4() : game(Game::instance())
{
    rect4Collider = new RectCollisionComponent(this, Rectangle{ game.RectPos4.x, game.RectPos4.y, game.rectWidth, game.rectHeight }); // Adjust the size as needed

    int windowWidth = Game::instance().getWindow().getWidth();
    int windowHeight = Game::instance().getWindow().getHeight();

    setPosition(Vector2(windowWidth / 2, windowHeight - 30));
    SetScale(100); // Adjust the size as needed

    Game::instance().addActor(this);
}
