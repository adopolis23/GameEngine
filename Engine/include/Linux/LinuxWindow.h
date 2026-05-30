#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"
#include "Log.h"
#include "core.h"

#include <string>

namespace Engine
{

    class LinuxWindow : public Window
    {
        public:
            LinuxWindow(const WindowData& windowData);
            virtual ~LinuxWindow();

            void OnUpdate() override;

            inline size_t GetWidth() const override { return mWindowData.Width; }
            inline size_t GetHeight() const override { return mWindowData.Height; }

        private:
            virtual void Init(const WindowData& props);
            void SetCallbacks();
            virtual void Shutdown();

        private:
            GLFWwindow* mWindow;
            WindowData mWindowData;

    };

}
