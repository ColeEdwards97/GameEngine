#pragma once

#include "Core.h"

// testing
#include "Log.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
// testing

namespace GameEngine
{
	class GAMEENGINE_API Application
	{

	public:

		Application();
		virtual ~Application();

		void run();

	};


	// to be defined in client
	Application* createApplication();


}