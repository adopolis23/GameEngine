#include "Application.h"

Engine::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());

	auto callback = std::bind(&Application::OnEvent, this, std::placeholders::_1);
	m_Window->SetEventCallback(callback);

	m_Running = true;
}

Engine::Application::~Application()
{
}

void Engine::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

	ENGINE_CORE_INFO("Application OnEvent: " + e.ToString());
}

bool Engine::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

void Engine::Application::run()
{
	while (m_Running)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}
