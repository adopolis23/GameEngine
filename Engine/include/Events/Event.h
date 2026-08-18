#pragma once

#include "core.h"

#include <string>
#include <functional>

#define BIND_EVENT_FUNCTION(type, fn) [this](type& e) { return this->fn(e); }

namespace Engine
{


    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseMoved,
        KeyScrolled,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseScrolled,
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryKeyboard = BIT(1),
        EventCategoryInput = BIT(2),
        EventCategoryMouse = BIT(3),
    };

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }



    class ENGINE_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
        
        inline bool Handled() { return mHandled; }

	protected:
		bool mHandled = false;
	};


    class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

        public:

            EventDispatcher(Event& event) : mEvent(event)
            { }

            template<typename T>
            bool Dispatch(EventFn<T> func)
            {
                if (mEvent.GetEventType() == T::GetStaticType())
                {
                    mEvent.mHandled = func(*(T*)&mEvent);
                    return true;
                }
                return false;
            }

        private:
            Event& mEvent;
	};




	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
