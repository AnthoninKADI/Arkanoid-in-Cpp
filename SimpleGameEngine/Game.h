#pragma once
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"
#include "Actor.h"
#include "Assets.h"
#include "SpriteComponent.h"
#include "DrawCircleComponent.h"

using std::vector;

class DrawCircleComponent;
class RectCollisionComponent;

class Game
{
public: 
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;
	const Window& getWindow() const { return window; }

private:
	Game() :isRunning(true), isUpdatingActors(false) {}
	
public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	void removeRect(int rectIndex);

	Renderer& getRenderer() { return renderer; }
	// Game specific


private:
	void processInput();
	void update(float dt);
	void render();

	bool isRunning;
	Window window;
	Renderer renderer;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

public:
	//Paddle
	Vector2 paddlePos = { 197, 700};
	Rectangle paddleRect;

	const float paddleWidth = 96;
	const float paddleHeight = 10;

	//Rectangle 1
	Vector2 RectPos1 = { 60, 70};
	Rectangle rectRect1;

	//Rectangle 2
	Vector2 RectPos2 = { 140, 20 };
	Rectangle rectRect2;

	//Rectangle 3
	Vector2 RectPos3 = { 260, 20 };
	Rectangle rectRect3;

	//Rectangle 4
	Vector2 RectPos4 = { 340, 70 };
	Rectangle rectRect4;

	//Rectangle 5
	Vector2 RectPos5 = { 200, 70 };
	Rectangle rectRect5;

	const float rectWidth = 100;
	const float rectHeight = 30;

/*	
	void setRectPostion(Vector2 rectPos);
*/

private:
	// Game specific
	Actor* ball{ nullptr };
	Actor* test{ nullptr };

	RectCollisionComponent* testBallComp{ nullptr };
	RectCollisionComponent* testComp{ nullptr };
};

