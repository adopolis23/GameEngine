#include "application.h"
#include "Events/ApplicationEvent.h"
#include "Linux/LinuxWindow.h"
#include "Log.h"
#include "Window.h"
#include "core.h"
#include <GLFW/glfw3.h>



// Setting the static instance of the application to nullptr by default before it is created.
Engine::Application* Engine::Application::mInstance = nullptr;

Engine::Application::Application()
{
    ASSERT(mInstance == nullptr, "Application Constructor: Application already exists");
    mInstance = this; 

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
    layer->OnAttach();
}

void Engine::Application::PushOverlay(Layer* layer)
{
    mLayerStack.PushOverlay(layer);
    layer->OnAttach();
}

void Engine::Application::OnEvent(Event& e)
{
    EventDispatcher dispatcher(e);

    // bool Dispatch(EventFn<T> func)
    dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) {
        return OnWindowClose(e);
    });

    dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) {
        return OnWindowResize(e);
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

bool Engine::Application::OnWindowResize(WindowResizeEvent& e)
{
    ENGINE_CORE_INFO("Resizing window to {}, {}", e.GetWidth(), e.GetHeight());
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
