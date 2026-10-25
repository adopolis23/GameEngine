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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

		float mDeltaTime{0.0f};

	};

}
