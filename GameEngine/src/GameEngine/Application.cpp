#include "gepch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace GameEngine
{

	Application::Application()
	{
		mWindow = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{

	}


	void Application::run()
	{
		while (mRunning)
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->onUpdate();
		}
	}

}