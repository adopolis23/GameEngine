#pragma once

//#include "GLFW/glfw3.h"
#include "Renderer/GraphicsContext.h"
#include "core.h"

class GLFWwindow;
namespace Engine
{

    //class GLFWwindow;

    class OpenGLContext : public Context
    {
    public:
        OpenGLContext(GLFWwindow* window)
            :mWindow(window)
        {
            //ASSERT(window, "Context: Window Is Null");
        }

        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* mWindow;

    };

}
