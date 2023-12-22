#include "Ball.h"
#include "DrawCircleComponent.h"
#include "MoveComponent.h"
#include "RectCollisionComponent.h"
#include "Window.h"
#include "Paddle.h"
#include "Game.h"
#include "Rectangle1.h"
#include "Rectangle2.h"
#include "Rectangle3.h"
#include "Rectangle4.h"
#include "Rectangle5.h"

#include <iostream>

using namespace std;

Ball::Ball() : game(Game::instance())
{
	drawCircle = new DrawCircleComponent(this, 20);
	collider = new RectCollisionComponent(this, Rectangle{ 0, 0, 25, 25 });
	move = new MoveComponent(this);
	setPosition(Vector2{ WINDOW_WIDTH /2, WINDOW_HEIGHT /2 });
	setRotation(45);
	move->setForwardSpeed(200);
}

void Ball::updateActor(float dt)
{
	if (getPosition().x > WINDOW_WIDTH || getPosition().y > WINDOW_HEIGHT ||
		getPosition().x < 0 || getPosition().y < 0) {
		setRotation(getRotation() + 180);

		setPosition(getPosition() * -1);

	}

	// Paddle
	if (getPosition().x + 20 > game.paddlePos.x && getPosition().y + 20 > game.paddlePos.y)
	{
		setRotation(-getRotation());	



	}

	// Rectangle 1
	if (getPosition().x + 20 < game.RectPos1.x + 100 && getPosition().y + 20 < game.RectPos1.y + 30)
	{
		cout << "Rectangle 1 Hit " << endl;

		///setRotation(-getRotation());

		setPosition(getPosition()*-1);

		game.RectPos1 = { 1000, 1000 };

	}

	//Rectangle 2
	else if (getPosition().x + 20 < game.RectPos2.x + 100 && getPosition().y + 20 < game.RectPos2.y + 30)
	{
		cout << "Rectangle 2 Hit " << endl;
		//setRotation(-getRotation());

		setPosition(getPosition() * -1);

		game.RectPos2 = { 1000, 1000 };

	}

	// Rectangle 3
	if (getPosition().x + 20 < game.RectPos3.x + 100 && getPosition().y + 20 < game.RectPos3.y + 30)
	{
		cout << "Rectangle 3 Hit " << endl;
		//setRotation(-getRotation());

		setPosition(getPosition() * -1);

		game.RectPos3 = { 1000, 1000 };

	}

	//Rectangle 4
	if (getPosition().x + 20 < game.RectPos4.x + 100 && getPosition().y + 20 < game.RectPos4.y + 30)
	{
		cout << "Rectangle 4 Hit " << endl;
		//setRotation(-getRotation());

		setPosition(getPosition() * -1);

		game.RectPos4 = { 1000, 1000 };

	}

	//Rectangle 5
	if (getPosition().x + 20 < game.RectPos5.x + 100 && getPosition().y + 20 < game.RectPos5.y + 30)
	{
		cout << "Rectangle 5 Hit " << endl;
		cout << getPosition().x + 20 << "  " << game.RectPos5.x << endl;

		//setRotation(-getRotation());

		setPosition(getPosition() * -1);

		game.RectPos5 = { 1000, 1000 };

	}
/*
	if (Intersect(*collider, *game.getRectCollider1()))
	{
		game.removeRect(1);
	}
	else if (Intersect(*collider, *game.getRectCollider2()))
	{
		game.removeRect(2);
	}
	else if (Intersect(*collider, *game.getRectCollider3()))
	{
		game.removeRect(3);
	}
	else if (Intersect(*collider, *game.getRectCollider4()))
	{
		game.removeRect(4);
	}
	else if (Intersect(*collider, *game.getRectCollider5()))
	{
		game.removeRect(5);
	}
*/
}
