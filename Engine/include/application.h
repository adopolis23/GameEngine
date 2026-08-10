#pragma once

#include "core.h"
#include "Log.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

#include <iostream>
#include <memory>


namespace Engine {

    class ENGINE_API Application
    {

        public:
            Application();
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* layer);

        private:
            bool OnWindowClose(WindowCloseEvent& e);

            bool mRunning{false};
            std::unique_ptr<Window> mWindow{};
            
            LayerStack mLayerStack;

    };

    Application* CreateApplication();

}
