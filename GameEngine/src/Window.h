#pragma once

#include "Core.h"
#include "Events/Event.h"
#include <functional>

namespace Engine {

	//struct for holding window properties so that they can be passed into functions
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Engine",
						unsigned int width = 1280,
						unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{}
	};


	class ENGINE_API Window
	{

	public:
		
		//EventCallBackFn is some function that returns void 
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void Init(const WindowProperties& props) = 0;
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		

		virtual void SetEventCallback(const EventCallbackFn& Callback) = 0;
		

		static Window* Create(const WindowProperties& props = WindowProperties());

		
	};

}

