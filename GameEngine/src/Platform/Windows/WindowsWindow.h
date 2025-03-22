#pragma once
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Log.h"
#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"

namespace Engine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }


		inline void SetEventCallback(const EventCallbackFn& Callback) override { m_Data.Callback = Callback; }


	private:
		virtual void Init(const WindowProperties& props);
		void SetCallbacks();
		virtual void Shutdown();

		GLFWwindow* m_Window;

		//might get rid of this and just use win props, would just add the call back
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			EventCallbackFn Callback;
		};

		WindowData m_Data;
	};

}

