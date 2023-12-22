#include "Rectangle5.h"

Rectangle5::Rectangle5() : game(Game::instance())
{
    rect5Collider = new RectCollisionComponent(this, Rectangle{ game.RectPos5.x, game.RectPos5.y, game.rectWidth, game.rectHeight }); // Adjust the size as needed

    int windowWidth = Game::instance().getWindow().getWidth();
    int windowHeight = Game::instance().getWindow().getHeight();

    setPosition(Vector2(windowWidth / 2, windowHeight - 30));
    SetScale(100); // Adjust the size as needed

    Game::instance().addActor(this);
}
