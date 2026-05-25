#include <iostream>

#include "application.h"

extern Engine::Application* Engine::CreateApplication();

// Define main entry point.
int main(int argc, char** argv)
{
    std::cout << "Creating application" << std::endl;
    auto app = Engine::CreateApplication();
    app->run();

    return 0;
}

