#pragma once

#include "Log.h"

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	ENGINE_CORE_WARN("Initialized Logger");

	auto app = Engine::CreateApplication();
	app->run();
	delete app;
}

#endif