#include "ImGui/ImGuiLayer.h"
#include "imgui.h"
#include <Engine.h>



class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

    virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

};



class Sandbox : public Engine::Application
{
    public:
        Sandbox()
        {
            PushLayer(new ExampleLayer());
        };

        ~Sandbox() {};
            
    private:
};


Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
