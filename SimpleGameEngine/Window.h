#pragma once
#include <SDL.h>

constexpr int WINDOW_WIDTH = 400;
constexpr int WINDOW_HEIGHT = 768;

constexpr int PADDLE_WIDTH = 300;
constexpr int PADDLE_HEIGHT = 150;

class Window
{
public:
	Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool initialize();
	void close();

	SDL_Window* getSDLWindow() const { return SDLWindow; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }


private:
	SDL_Window* SDLWindow;
	int width;
	int height;
};

