#pragma once

#include "core.h"
#include "Log.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

#include <iostream>
#include <memory>
#include <stdexcept>


namespace Engine {

    class ENGINE_API Application
    {

        public:
            Application();
            Application(Application& other) = delete;
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* layer);

            // Singletons should not be assignable
            void operator=(const Application& other) = delete;

            inline Window& GetWindow() 
            { 
                ASSERT(mWindow != nullptr, "Application::Window is nullptr");
                return *mWindow; 
            } 

            inline static Application& GetInstance()
            {
                ASSERT(mInstance != nullptr, "Application static instance is nullptr");
                return *mInstance;
            }


        private:
            bool OnWindowClose(WindowCloseEvent& e);
            bool OnWindowResize(WindowResizeEvent& e);

            bool mRunning{false};
            std::unique_ptr<Window> mWindow{};
            
            LayerStack mLayerStack;

            // Application is a Singleton, this is the only instance.
            static Application* mInstance;

    };


    Application* CreateApplication();

}
