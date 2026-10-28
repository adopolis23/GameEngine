#include "Renderer/OpenGl/OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <GL/GL.h>

#include "Log.h"

namespace Engine {

	//   OpenGLContext::OpenGLContext(GLFWwindow* window)
	// 	: mWindow(window)
	// {
	// 	ASSERT(window, "Window handle is null!");
	// }

	void OpenGLContext::Init()
	{
        glfwMakeContextCurrent(mWindow);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
        {
            ENGINE_CORE_INFO("Failed to initialize GLAD");
            return;
        }
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

}
