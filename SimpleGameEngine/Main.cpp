#include <iostream>
#include <SDL.h>
#include "Game.h"
#include "Component.h"
#include "Vector2.h"
#include "Window.h"
#include "Actor.h"
#include "Renderer.h"
#include "Log.h"

#include <algorithm>

using std::cout;

int main(int argc, char** argv) 
{
	bool isGameInit = Game::instance().initialize();
	if(isGameInit)
	{
		Game::instance().load();
		Game::instance().loop();
		Game::instance().unload();
	}
	Game::instance().close();
	return 0;
}