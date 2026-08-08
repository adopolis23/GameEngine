#pragma once

#include "core.h"
#include "Log.h"
#include "Window.h"

#include <iostream>
#include <memory>


namespace Engine {

    class ENGINE_API Application
    {

        public:
            Application();
            virtual ~Application();

            void run();

        private:
            bool mRunning{false};

            std::unique_ptr<Window> mWindow{};

    };

    Application* CreateApplication();

}
