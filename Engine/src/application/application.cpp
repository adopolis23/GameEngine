#include "application.h"
#include "Events/ApplicationEvent.h"
#include "Linux/LinuxWindow.h"
#include "Window.h"
#include <GLFW/glfw3.h>

Engine::Application::Application()
{
    mWindow = std::unique_ptr<Window>(Window::Create());


    //void SetEventCallback(const EventCallback& callback) override { mWindowData.Callback = callback; }
    mWindow->SetEventCallback([this](Event& e) {
        this->OnEvent(e);
    });
}

Engine::Application::~Application()
{

}


void Engine::Application::PushLayer(Layer* layer)
{
    mLayerStack.PushLayer(layer);
}

void Engine::Application::PushOverlay(Layer* layer)
{
    mLayerStack.PushOverlay(layer);
}

void Engine::Application::OnEvent(Event& e)
{
    EventDispatcher dispatcher(e);

    // bool Dispatch(EventFn<T> func)
    dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) {
        return OnWindowClose(e);
    });


    for (auto it = mLayerStack.end(); it != mLayerStack.begin(); )
    {
        (*--it)->OnEvent(e);
        if (e.Handled())
            break;
    }
}

bool Engine::Application::OnWindowClose(WindowCloseEvent& e)
{
    mRunning = false;
    return true;
}

void Engine::Application::Run() {
    ENGINE_CORE_TRACE("Starting 'run' on application");
    mRunning = true;

    while (mRunning)
    {
        
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        for (Layer* layer : mLayerStack)
        {
            layer->OnUpdate();
        }

        mWindow->OnUpdate();

    }

}
