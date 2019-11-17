#pragma once

#include "Core.h"

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