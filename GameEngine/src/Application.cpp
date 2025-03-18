#include "Application.h"

Engine::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());

	auto callback = std::bind(&Application::OnEvent, this, std::placeholders::_1);

	m_Window->SetEventCallback(callback);
}

Engine::Application::~Application()
{
}

void Engine::Application::OnEvent(Event& e)
{
	ENGINE_CORE_INFO("Application OnEvent: " + e.ToString());
}

void Engine::Application::run()
{
	while (true);
}
