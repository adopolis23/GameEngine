#pragma once

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
#include "Layer.h"
#include "core.h"

namespace Engine {

	class ENGINE_API ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
        bool OnMousePressedEvent(MouseButtonPressedEvent& event);
        bool OnMouseReleasedEvent(MouseButtonReleasedEvent& event);
        bool OnMouseMovedEvent(MouseMovedEvent& event);
        bool OnMouseScrolledEvent(MouseScrolledEvent& event);
        bool OnKeyPressedEvent(KeyPressedEvent& event);
        bool OnKeyTypedEvent(KeyTypedEvent& event);
        bool OnKeyReleasedEvent(KeyReleasedEvent& event);
        bool OnWindowResizeEvent(WindowResizeEvent& event);

		float mDeltaTime{0.0f};

	};

}
