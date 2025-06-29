#pragma once
#include "Core.h"
#include <memory>
#include "Window.h"
#include "Log.h"
#include "GLFW/glfw3.h"
#include "Events/ApplicationEvent.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = false;

	};

	//define in client
	Application* CreateApplication();

}

