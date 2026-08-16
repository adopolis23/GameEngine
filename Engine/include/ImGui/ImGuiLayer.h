#pragma once

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
		float mDeltaTime{0.0f};

	};

}
