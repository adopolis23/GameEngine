#pragma once

#include "Log.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Window.h"
#include "Application.h"

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	//initialize spdlog
	Engine::Log::Init();
	ENGINE_CORE_TRACE("Initialized Logger");


	//get applicaion implementation from client and run
	auto app = Engine::CreateApplication();
	app->run();
	delete app;
}

#endif

