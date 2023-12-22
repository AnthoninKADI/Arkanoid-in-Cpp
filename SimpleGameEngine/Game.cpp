#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "AnimSpriteComponent.h"
#include "Timer.h"
#include "Assets.h"
#include "Ball.h"
#include "Paddle.h"
#include "Rectangle.h"
#include "Window.h"
#include "Rectangle1.h"
#include "Rectangle2.h"
#include "Rectangle3.h"
#include "Rectangle4.h"
#include "Rectangle5.h"

#include <algorithm>
#include <iostream>

using namespace std;

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);

	return isWindowInit && isRendererInit; // Return bool && bool && bool ...to detect error
}


void Game::load()
{
	// Load textures
	//Assets::loadTexture(renderer, "Res\\Ship01.png", "Ship01");

	ball = new Ball();
	Paddle* paddle = new Paddle();
	Rectangle1* rectangle1 = new Rectangle1();
	Rectangle2* rectangle2 = new Rectangle2();
	Rectangle3* rectangle3 = new Rectangle3();
	Rectangle4* rectangle4 = new Rectangle4();
	Rectangle5* rectangle5 = new Rectangle5();
}

void Game::processInput()
{
	// SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
	// Keyboard state
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	// Escaoe: quit game
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}

	if (0 + paddleWidth < paddlePos.x < WINDOW_WIDTH - paddleWidth)
	{
		//cout << paddlePos.x << endl;

		if (keyboardState[SDL_SCANCODE_RIGHT])
		{
			paddlePos.x += 3;
		}
		if (keyboardState[SDL_SCANCODE_LEFT])
		{
			paddlePos.x -= 3;
		}
	}
	// Actor input
	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->processInput(keyboardState);
	}
	isUpdatingActors = false;
}

void Game::update(float dt)
{
	// Update actors
	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->update(dt);
	}
	isUpdatingActors = false;

	//Move pending actors to actors
	for (auto pendingActor : pendingActors)
	{
		actors.emplace_back(pendingActor);
	}
	pendingActors.clear();

	//Delete dead actors
	vector<Actor*> deadActors;
	for (auto actor : actors)
	{
		if (actor->getState() == Actor::ActorState::Dead)
		{
			deadActors.emplace_back(actor);
		}
	}
	for (auto deadActor : deadActors)
	{
		delete deadActor;
	}
}

void Game::render()
{
	renderer.beginDraw();

	//Draw Paddle
	paddleRect = { paddlePos.x - paddleWidth / 2, paddlePos.y - paddleHeight / 2, paddleWidth, paddleHeight };
	renderer.drawRect(paddleRect);
	
	//Draw Rectangle1
	rectRect1 = { RectPos1.x - rectWidth / 2, RectPos1.y - rectHeight / 2, rectWidth, rectHeight };
	renderer.drawRect(rectRect1);

	

	//Draw Rectangle2
	rectRect2 = { RectPos2.x - rectWidth / 2, RectPos2.y - rectHeight / 2, rectWidth, rectHeight };
	renderer.drawRect(rectRect2);

	//Draw Rectangle3
	rectRect3 = { RectPos3.x - rectWidth / 2, RectPos3.y - rectHeight / 2, rectWidth, rectHeight };
	renderer.drawRect(rectRect3);

	//Draw Rectangle4
	rectRect4 = { RectPos4.x - rectWidth / 2, RectPos4.y - rectHeight / 2, rectWidth, rectHeight };
	renderer.drawRect(rectRect4);

	//Draw Rectangle5
	rectRect5 = {RectPos5.x - rectWidth / 2, RectPos5.y - rectHeight / 2, rectWidth, rectHeight};
	renderer.drawRect(rectRect5); 

	renderer.draw();
	renderer.endDraw();
}


void Game::loop()
{
	Timer timer;
	float dt = 0;
	while(isRunning)
	{
		float dt = timer.computeDeltaTime() / 1000.0f;
		processInput();
		update(dt);
		render();
		timer.delayTime();
	}
}

void Game::unload()
{
	// Delete actors
	// Because ~Actor calls RemoveActor, have to use a different style loop
	while (!actors.empty())
	{
		delete actors.back();
	}

	// Resources
	Assets::clear();
}

void Game::close()
{
	renderer.close();
	window.close();
	SDL_Quit();
}

void Game::addActor(Actor* actor)
{
	if (isUpdatingActors) 
	{
		pendingActors.emplace_back(actor);
	}
	else
	{
		actors.emplace_back(actor);
	}
}

void Game::removeActor(Actor* actor)
{
	// Erase actor from the two vectors
	auto iter = std::find(begin(pendingActors), end(pendingActors), actor);
	if (iter != end(pendingActors))
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, end(pendingActors) - 1);
		pendingActors.pop_back();
	}
	iter = std::find(begin(actors), end(actors), actor);
	if( iter != end(actors))
	{
		std::iter_swap(iter, end(actors) - 1);
		actors.pop_back();
	}
}

void Game::removeRect(int rectIndex)
{
	if (rectIndex >= 1 && rectIndex <= 5)
	{
		switch (rectIndex)
		{
		case 1:
			rectRect1.width = 0;
			rectRect1.height = 0;
			break;
		case 2:
			rectRect2.width = 0;
			rectRect2.height = 0;
			break;
		case 3:
			rectRect3.width = 0;
			rectRect3.height = 0;
			break;
		case 4:
			rectRect4.width = 0;
			rectRect4.height = 0;
			break;
		case 5:
			rectRect5.width = 0;
			rectRect5.height = 0;
			break;
		}
	}
}
