#pragma once
#include "Event.h"

namespace Engine
{


    class ENGINE_API KeyEvent : public Event
    {
        public:
            inline int GetKeycode() const { return mKeycode; };

            EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

        protected:
            KeyEvent(int keycode): mKeycode(keycode) {}; 

        private:
            int mKeycode{}; 

    };

    class ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount): KeyEvent(keycode), mRepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return mRepeatCount; }

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int mRepeatCount;
	};


	class ENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class ENGINE_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyTyped)
	};





}
