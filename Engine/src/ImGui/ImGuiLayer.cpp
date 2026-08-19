#include "ImGui/ImGuiLayer.h"
#include "ImGui/ImGuiUtilityFunctions.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/Event.h"
#include "Log.h"
#include "imgui.h"
#include "OpenGl/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "application.h"

namespace Engine {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable keyboard navigation
        
        // No KeyMap needed anymore!
        
        ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::GetInstance();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = mDeltaTime > 0.0f ? (time - mDeltaTime) : (1.0f / 60.0f);
		mDeltaTime = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

    bool ImGuiLayer::OnMousePressedEvent(MouseButtonPressedEvent& event)
    {
        ENGINE_CORE_INFO("Mouse Button Pressed Event");

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = true;

		return false;
    }

    bool ImGuiLayer::OnMouseReleasedEvent(MouseButtonReleasedEvent& event)
    {
        ENGINE_CORE_INFO("Mouse Button Released Event");

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = false;

        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
    {
        //ENGINE_CORE_INFO("Mouse Moved Event");

		ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(event.GetX(), event.GetY());

        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event) 
    {
        ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += event.GetXOffset();
		io.MouseWheel += event.GetYOffset();

        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
		int keycode = event.GetKeycode();

//		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
//		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
//		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
//		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

        ImGuiKey imguikey = KeycodeToImGuiKey(keycode);

        if (imguikey != ImGuiKey_None)
        {
            io.AddKeyEvent(imguikey, true);
        }

        return false;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
		int keycode = event.GetKeycode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned int)keycode);

        return false;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& event)
    {
//        ImGuiIO& io = ImGui::GetIO();
//		io.KeysDown[event.GetKeycode()] = false;
        ImGuiIO& io = ImGui::GetIO();
    
        int keycode = event.GetKeycode();
        ImGuiKey imguikey = KeycodeToImGuiKey(keycode);

        if (imguikey != ImGuiKey_None)
        {
            io.AddKeyEvent(imguikey, false);
        }


        return false;
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& event)
    {

        ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, event.GetWidth(), event.GetHeight());

		return false;
    }


	void ImGuiLayer::OnEvent(Event& event)
	{
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUNCTION(MouseButtonPressedEvent, OnMousePressedEvent));

        dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FUNCTION(MouseButtonReleasedEvent, OnMouseReleasedEvent));

        dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FUNCTION(MouseMovedEvent, OnMouseMovedEvent));

		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FUNCTION(MouseScrolledEvent, OnMouseScrolledEvent));

		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FUNCTION(KeyPressedEvent, OnKeyPressedEvent));

        dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FUNCTION(KeyTypedEvent, OnKeyTypedEvent));

		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FUNCTION(KeyReleasedEvent, OnKeyReleasedEvent));

		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FUNCTION(WindowResizeEvent, OnWindowResizeEvent));
	}

}
