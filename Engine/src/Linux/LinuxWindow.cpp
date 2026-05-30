#include "Linux/LinuxWindow.h"
#include "Window.h"

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

        //bind the user data of this window to the address of mWindowData
        glfwSetWindowUserPointer(mWindow, &mWindowData);

        //callbacks
        SetCallbacks();
    }

    void LinuxWindow::SetCallbacks()
    {
        return;
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
