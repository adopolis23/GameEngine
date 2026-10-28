#pragma once

#include "Renderer/OpenGl/OpenGLContext.h"
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

            void* GetNativeWindow() const override;

            inline size_t GetWidth() const override { return mWindowData.Width; }
            inline size_t GetHeight() const override { return mWindowData.Height; }

        private:
            virtual void Init(const WindowData& props) override;
            inline void SetEventCallback(const EventCallback& callback) override { mWindowData.EventCallbackFn = callback; }
            void setGLFWCallbacks();
            virtual void Shutdown();

        private:
            GLFWwindow* mWindow;
            Context* mContext;
            WindowData mWindowData;

    };

}
