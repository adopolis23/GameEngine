#pragma once

#include "Events/Input.h"

namespace Engine {

	class LinuxInput : public Input
	{
	protected:
        virtual bool IsMouseButtonPressedImpl(int button) override;
        //virtual int GetKeyPressedImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}
