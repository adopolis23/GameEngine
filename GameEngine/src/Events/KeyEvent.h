#pragma once

#include "Event.h"
#include "KeyCodes.h"
#include <sstream>


namespace Engine {

	using KeyCode = uint16_t;

	class KeyEvent : public Event
	{
	public:


		KeyCode GetKeyCode() { return m_Keycode;  }

		//return keyboard event OR'd with Input event
		int GetCatagoryFlags() const { return EventCatagoryEnum::EventCatagoryKeyboard | EventCatagoryEnum::EventCatagoryInput; }

	protected:
		KeyCode m_Keycode;

		KeyEvent(const KeyCode key)
		{
			m_Keycode = key;
		}

	};


	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int key, bool isRepeat) : KeyEvent(key)
		{
			m_IsRepeat = isRepeat;
		}

		const char* GetName() const
		{
			return "Key Pressed";
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_Keycode << " (repeat = " << m_IsRepeat << ")";
			return ss.str();
		}

		EventTypeEnum GetEventType() const { return EventTypeEnum::KeyPressed; }

	private:
		bool m_IsRepeat;
	};



	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_Keycode;
			return ss.str();
		}

		const char* GetName() const
		{
			return "Key Released";
		}

		EventTypeEnum GetEventType() const { return EventTypeEnum::KeyReleased; }
	};

}