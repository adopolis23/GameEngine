#pragma once
#include "Core.h"
#include <memory>
#include "Window.h"
#include "Log.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window;

	};

	//define in client
	Application* CreateApplication();

}

