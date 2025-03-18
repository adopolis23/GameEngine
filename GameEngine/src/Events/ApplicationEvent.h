#pragma once

#include "Event.h"

namespace Engine
{

	class WindowResizeEvent : public Event
	{

	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
		{
			m_width = width;
			m_Height = height;
		}

		const char* GetName() const
		{
			return "Window Resize";
		}

		EVENT_TYPE(WindowResize)
		EVENT_CATAGORY(EventCatagoryApplication)

		unsigned int GetWidth() { return m_width; }
		unsigned int GetHeight() { return m_Height; }

	private:
		unsigned int m_width;
		unsigned int m_Height;

	};



}