#include "Log.h"
#include <SDl_log.h>
#include <SDl_error.h>

void Log::info(const string& message)
{
	SDL_Log(message.c_str());
}

void Log::error(LogCategory category, const string& message)
{
	SDL_LogError(static_cast<int>(category), "%s | SDL: %s", message.c_str(), SDL_GetError());
}