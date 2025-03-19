#pragma once

//fix this with include directory (maybe in the premake file)
#include "../Core.h"
#include <string>

namespace Engine
{

	//enum class for the different event types
	enum class EventTypeEnum
	{
		None = 0,
		WindowResize,
		WindowClose,
		KeyPressed,
	};


	//Enum for the event catagories. Each catagory is a 1 shifted over by some number of bits such as Keyboard events are = 00100
	//This is so that en event can have multiple event catagories applied to it.
	enum EventCatagoryEnum
	{
		None = 0,
		EventCatagoryApplication = BIT(0),
		EventCatagoryInput = BIT(1),
		EventCatagoryKeyboard = BIT(2),
		EventCatagoryMouse = BIT(3),
		EventCatagoryMouseButton = BIT(4),
	};


	class Event
	{
	public:
		virtual ~Event() = default;
		
		inline bool IsHandled() { return m_Handled; }

		//returns the event type of the event. Type is from the event type enum. 
		virtual EventTypeEnum GetEventType() const = 0;

		virtual const char* GetName() const = 0;

		virtual int GetCatagoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); };


		//does an and between the passed catagory and the events catagory flags.
		bool IsInCatagory(EventCatagoryEnum category)
		{
			return GetCatagoryFlags() & category;
		}

	private:
		bool m_Handled = false;

	};

}