#pragma once

#include "core.h"

#include <iostream>


namespace Engine {

    class ENGINE_API Application
    {

        public:
            void run();

        private:
            bool mIsRunning;

    };

    Application* CreateApplication();

}
