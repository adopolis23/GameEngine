#include <cstdlib>
#include <glad/glad.h>
#include "Linux/LinuxWindow.h"
#include "GLFW/glfw3.h"
#include "Log.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"


namespace Engine 
{
    static bool s_GLFWInitialized = false;

    LinuxWindow::LinuxWindow(const WindowData& windowData)
    {
        Init(windowData);
    }

    LinuxWindow::~LinuxWindow()
    {
    }

    //definition of the Create function defined in the base window class
    //defined to return a linux specific window.
    Window* Window::Create(const WindowData& props)
    {
        return new LinuxWindow(props);
    }

    static void GLFWErrorCallback(int error, const char* description)
	{
		ENGINE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

    //set member window data
    //initialize glfw
    void LinuxWindow::Init(const WindowData& props)
    {
        mWindowData.Title = props.Title;
        mWindowData.Width = props.Width;
        mWindowData.Height = props.Height;

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

        mWindow = glfwCreateWindow(mWindowData.Width, mWindowData.Height, mWindowData.Title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(mWindow);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
        {
            ENGINE_CORE_ERROR("Failed to initialize GLAD");
            return;
        }

        //bind the user data of this window to the address of mWindowData
        glfwSetWindowUserPointer(mWindow, &mWindowData);

        glfwSetErrorCallback(GLFWErrorCallback);

        setGLFWCallbacks();
    }

    void LinuxWindow::setGLFWCallbacks()
    {
        glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallbackFn(event);
		});

        glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(width, height);
			data.EventCallbackFn(event);
        });

        glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch(action)
            {

            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.EventCallbackFn(event);
                break;
            }

            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.EventCallbackFn(event);
                break;
            }
                
            case GLFW_REPEAT:
                KeyPressedEvent event(key, 1);
                data.EventCallbackFn(event);
                break;

            }
        });


        glfwSetCharCallback(mWindow, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallbackFn(event);
		});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallbackFn(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallbackFn(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallbackFn(event);
		});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallbackFn(event);
		});
    }

    void LinuxWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(mWindow);
    }


    void LinuxWindow::Shutdown()
    {
        glfwDestroyWindow(mWindow);
    }

}
