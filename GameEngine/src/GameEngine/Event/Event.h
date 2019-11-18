#pragma once

#include "GameEngine/Core.h"

namespace GameEngine
{


	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowUnfocus, WindowMoved,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroll,
		KeyPressed, KeyReleased
	};



	enum EventCategory
	{
		None = 0,
		EventCategoryWindow = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryMouse = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryApplication = BIT(4)
	};



#define EVENT_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
							virtual EventType getEventType() const override { return getStaticType(); }\
							virtual const char* getName() const override { return #type; }

#define EVENT_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }
							



	// -----------------------------------------------------------
	// ABSTRACT EVENT
	class GAMEENGINE_API Event
	{

		friend class EventDispatcher;

	public:

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		}

		inline bool isHandled() const { return mIsHandled; }

	protected:
		bool mIsHandled = false;


	};

	// -----------------------------------------------------------
	// EVENT DISPATCHER
	class EventDispatcher
	{

		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:

		EventDispatcher(Event& e) : mEvent(e) {}


		template<typename T> 
		bool Dispatch(EventFn<T> func)
		{
			if (mEvent.getEventType() == T::getStaticType())
			{
				mEvent.mIsHandled = func(*(T*)& mEvent);
				return true;
			}
			return false;
		}


	private:
		Event& mEvent;

	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}



}