#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace GameEngine
{

	class GAMEENGINE_API Layer
	{

	public:

		Layer();
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& e) {}

	};

}