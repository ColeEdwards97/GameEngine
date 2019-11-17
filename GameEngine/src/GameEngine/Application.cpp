#include "gepch.h"
#include "Application.h"

namespace GameEngine
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}


	void Application::run()
	{
		WindowResizeEvent e(800, 600);
		CORE_LOG_TRACE(e);

		while (true);
	}

}