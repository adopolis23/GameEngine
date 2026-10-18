#include "ImGui/ImGuiLayer.h"
#include "Log.h"
#include <Engine.h>



class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnEvent(Engine::Event& event) override
	{
		//ENGINE_TRACE("{0}", event);
		if (event.GetEventType() == Engine::EventType::KeyPressed)
		{
			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event;

			if (e.GetKeyCode() == KEY_TAB)
				ENGINE_TRACE("Tab key is pressed (event)!");

			ENGINE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};



class Sandbox : public Engine::Application
{
    public:
        Sandbox()
        {
            PushLayer(new ExampleLayer());

            PushOverlay(new Engine::ImGuiLayer());
        };

        ~Sandbox() {};
            
    private:
};


Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
