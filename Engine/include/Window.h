#pragma once

#include <string>
#include <cstddef>
#include <functional>

#include "core.h"
#include "Events/Event.h"


namespace Engine 
{
   
    struct WindowData 
    {
        using EventCallback = std::function<void(Event&)>;

        std::string Title;
        size_t Width;
        size_t Height;
        EventCallback Callback;

        WindowData(const std::string& title = "Engine", size_t width = 1280, size_t height = 720)
            :Title(title), Width(width), Height(height) {}
    };
     
    class ENGINE_API Window
    {
        public:
            using EventCallback = std::function<void(Event&)>;

            virtual ~Window() {}

            virtual void Init(const struct WindowData& props) = 0;
            virtual void OnUpdate() = 0;

            virtual size_t GetWidth() const = 0; 
            virtual size_t GetHeight() const = 0; 

            virtual void SetEventCallback(const EventCallback& callback) = 0;

            // creates a window with the default props if none are provided
            static Window* Create(const WindowData& props = WindowData());

        private:
    };

}
