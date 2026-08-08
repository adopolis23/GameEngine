#include "application.h"
#include "Linux/LinuxWindow.h"
#include "Window.h"
#include <GLFW/glfw3.h>

Engine::Application::Application()
{
    mWindow = std::unique_ptr<Window>(Window::Create());
}

Engine::Application::~Application()
{

}

void Engine::Application::run() {
    ENGINE_CORE_TRACE("Starting 'run' on application");
    mRunning = true;

    while (mRunning)
    {
        
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        mWindow->OnUpdate();

    }

}
