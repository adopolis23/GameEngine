#pragma once

#include <string>

#include "core.h"

namespace Engine 
{
   
    struct WindowProperties
    {
        std::string Title;
        size_t Width;
        size_t Height;

        WindowProperties(const std::string& title = "Engine", size_t width = 1280, size_t height = 720)
            :Title(title), Width(width), Height(height) {}
    };
     
    class ENGINE_API Window
    {
        public:
            virtual ~Window() {}

            virtual void Init(const WindowProperties& props) = 0;
            virtual void OnUpdate() = 0;

            virtual size_t GetWidth() const = 0; 
            virtual size_t GetHeight() const = 0; 


            // creates a window with the default props if none are provided
            static Window* Create(const WindowProperties& props = WindowProperties());

        private:
    };

}
