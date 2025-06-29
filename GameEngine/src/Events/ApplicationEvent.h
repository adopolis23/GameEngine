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

		EventTypeEnum GetEventType() const { return EventTypeEnum::WindowResize; }
		int GetCatagoryFlags() const { return EventCatagoryEnum::EventCatagoryApplication; }


		unsigned int GetWidth() { return m_width; }
		unsigned int GetHeight() { return m_Height; }

	private:
		unsigned int m_width;
		unsigned int m_Height;

	};


	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		const char* GetName() const
		{
			return "Window Close";
		}

		const EventTypeEnum GetStaticType() { return EventTypeEnum::WindowClose; }
		EventTypeEnum GetEventType() const override { return EventTypeEnum::WindowClose; }
		int GetCatagoryFlags() const override { return EventCatagoryEnum::EventCatagoryApplication; }

	};


}