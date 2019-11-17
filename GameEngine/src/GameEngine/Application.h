#pragma once

#include "Core.h"
#include "Window.h"

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

	private:

		std::unique_ptr<Window> mWindow;
		
		bool mRunning = true;

	};


	// to be defined in client
	Application* createApplication();


}