#include "WindowsWindow.h"
#include <Events/ApplicationEvent.h>

namespace Engine {

	static bool s_GLFWInitialized = false;

	//definition of the Create function defined in the base window class
	//defined to return a windows specific window.
	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	//set member window data
	//initialize glfw
	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		ENGINE_CORE_INFO("WindowsWindow:: Creating Window {} ({}, {})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			if (!glfwInit())
			{
				ENGINE_ERROR("Could not initialize GLFW");
			}
			else
			{
				s_GLFWInitialized = true;
			}
		}

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);

		//bind the user data of this window to the address of m_Data
		glfwSetWindowUserPointer(m_Window, &m_Data);


		//callbacks
		SetCallbacks();

	}

	void WindowsWindow::SetCallbacks()
	{
		
		//Window Resize Event
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
				//get the prev set user pointer (m_data)
				void* UserPointer = glfwGetWindowUserPointer(window);
				WindowData& data = *(WindowData*)UserPointer;

				data.Width = width;
				data.Height = height;

				//create the windowresize event object and call the windows event callback
				//application creats a window and sets its event callback to application::onevent
				WindowResizeEvent event(width, height);
				data.Callback(event);
				
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
				//get the prev set user pointer (m_data)
				void* UserPointer = glfwGetWindowUserPointer(window);
				WindowData& data = *(WindowData*)UserPointer;

				WindowCloseEvent event;
				data.Callback(event);
		});

	}


	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}


	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}
