#include <iostream>

#include "Log.h"
#include "spdlog/spdlog.h"
#include "application.h"

extern Engine::Application* Engine::CreateApplication();

// Define main entry point.
int main(int argc, char** argv)
{
    
    Engine::Log::Init();
    ENGINE_CORE_TRACE("Initialized Logging (spdlog)");


    // Create and run main application
    auto app = Engine::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

