#pragma once

#include "Event.h"

namespace GameEngine
{

	// -----------------------------------------------------------
	// ABSTRACT KEY EVENT
	class GAMEENGINE_API KeyEvent : public Event
	{

	public:

		inline int getKeyCode() const { return mKeyCode; }

		EVENT_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

	protected:

		KeyEvent(int keyCode) : mKeyCode(keyCode) {}

		int mKeyCode;

	};

	// -----------------------------------------------------------
	// KEY PRESSED EVENT
	class GAMEENGINE_API KeyPressedEvent : public KeyEvent
	{

	public:

		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), mRepeatCount(repeatCount) {}

		inline int getRepeatCount() const { return mRepeatCount; }

		int mRepeatCount;

		EVENT_TYPE(KeyPressed);

	};

	// -----------------------------------------------------------
	// KEY RELEASED EVENT
	class GAMEENGINE_API KeyReleasedEvent : public KeyEvent
	{

	public:

		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		EVENT_TYPE(KeyReleased);

	};



}