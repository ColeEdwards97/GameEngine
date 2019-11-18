#include "gepch.h"
#include "Application.h"

#include "Log.h"

#include <glad/glad.h>

namespace GameEngine
{

#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		mWindow = std::unique_ptr<Window>(Window::create());
		mWindow->setEventCallback(BIND_EVENT(onEvent));
	}

	Application::~Application()
	{

	}

	void Application::pushLayer(Layer* layer)
	{
		mLayerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		mLayerStack.pushOverlay(overlay);
	}


	void Application::onEvent(Event& e)
	{

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(onWindowCloseEvent));
		CORE_LOG_TRACE("{0}", e);

		for (auto it = mLayerStack.end(); it != mLayerStack.begin(); )
		{
			(*--it)->onUpdate();
			if (e.isHandled())
			{
				break;
			}
		}

	}

	void Application::run()
	{
		while (mRunning)
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->onUpdate();

			for (Layer* layer : mLayerStack)
			{
				layer->onUpdate();
			}

		}
	}


	// --------------------------------------------------------
	// EVENTS

	// window close
	bool Application::onWindowCloseEvent(WindowCloseEvent& e)
	{
		mRunning = false;
		return true;
	}

}