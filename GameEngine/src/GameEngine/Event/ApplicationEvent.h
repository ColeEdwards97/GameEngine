#pragma once

#include "Event.h"

namespace GameEngine
{

	// -----------------------------------------------------------
	// WINDOW RESIZE EVENT
	class GAMEENGINE_API WindowResizeEvent : public Event
	{

	public:

		WindowResizeEvent(unsigned int width, unsigned int height) : mWidth(width), mHeight(height) {}

		unsigned int getWidth() const { return mWidth; }
		unsigned int getHeight() const { return mHeight; }

		EVENT_TYPE(WindowResize);
		EVENT_CATEGORY(EventCategoryWindow | EventCategoryApplication);

	private:
		unsigned int mWidth;
		unsigned int mHeight;

	};

	// -----------------------------------------------------------
	// WINDOW CLOSE EVENT
	class GAMEENGINE_API WindowCloseEvent : public Event
	{

	public:

		WindowCloseEvent() {}

		EVENT_TYPE(WindowClose);
		EVENT_CATEGORY(EventCategoryWindow | EventCategoryApplication);

	};

	// --------------------------------------------------------
	// WINDOW FOCUS EVENT
	class GAMEENGINE_API WindowFocusEvent : public Event
	{

	public:

		WindowFocusEvent() {}

		EVENT_TYPE(WindowFocus);
		EVENT_CATEGORY(EventCategoryWindow | EventCategoryApplication);

	};

	// --------------------------------------------------------
	// WINDOW UNFOCUS EVENT
	class GAMEENGINE_API WindowUnfocusEvent : public Event
	{

	public:

		WindowUnfocusEvent() {}

		EVENT_TYPE(WindowUnfocus);
		EVENT_CATEGORY(EventCategoryWindow | EventCategoryApplication);

	};

	// -----------------------------------------------------------
	// WINDOW MOVED EVENT
	class GAMEENGINE_API WindowMovedEvent : public Event
	{

	public:

		WindowMovedEvent() {}

		EVENT_TYPE(WindowMoved);
		EVENT_CATEGORY(EventCategoryWindow | EventCategoryApplication);

	};


}