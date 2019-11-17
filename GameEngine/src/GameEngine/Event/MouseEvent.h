#pragma once

#include "Event.h"


namespace GameEngine
{

	//---------------------------------------------------------
	// MOUSE MOVED
	class GAMEENGINE_API MouseMovedEvent : public Event
	{

	public:

		MouseMovedEvent(float x, float y) : mMouseX(x), mMouseY(y) {}

		inline float getMouseX() const { return mMouseX; }
		inline float getMouseY() const { return mMouseY; }

		EVENT_TYPE(MouseMoved);
		EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		float mMouseX;
		float mMouseY;

	};

	
	// --------------------------------------------------------
	// MOUSE SCROLLED
	class GAMEENGINE_API MouseScrolledEvent : public Event
	{

	public:

		MouseScrolledEvent(float xOffset, float yOffset) : mOffsetX(xOffset), mOffsetY(yOffset) {}

		inline float getOffsetX() const { return mOffsetX; }
		inline float getOffsetY() const { return mOffsetY; }

		EVENT_TYPE(MouseScroll);
		EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		float mOffsetX;
		float mOffsetY;

	};

	// --------------------------------------------------------
	// MOUSE BUTTON EVENT ABSTRACT
	class GAMEENGINE_API MouseButtonEvent : public Event
	{

	public:

		inline int getButton() const { return mButton; }

		EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse);

	protected:
		MouseButtonEvent(int button) : mButton(button) {}

		int mButton;

	};

	// --------------------------------------------------------
	// MOUSE BUTTON PRESSED
	class GAMEENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:

		MouseButtonPressedEvent(int button, int repeats) : MouseButtonEvent(button), mRepeatCount(repeats) {}

		inline int getRepeatCount() const { return mRepeatCount; }

		EVENT_TYPE(MouseButtonPressed);

	private:
		int mRepeatCount;

	};

	// --------------------------------------------------------
	// MOUSE BUTTON RELEASED
	class GAMEENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:

		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		EVENT_TYPE(MouseButtonReleased);

	};

}

