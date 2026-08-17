#include "ImGui/ImGuiLayer.h"
#include <Engine.h>


class Sandbox : public Engine::Application
{
    public:
        Sandbox()
        {
            PushOverlay(new Engine::ImGuiLayer());
        };

        ~Sandbox() {};
            
    private:
};


Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
