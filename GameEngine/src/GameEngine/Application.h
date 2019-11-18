#pragma once

#include "Core.h"
#include "Window.h"

#include "Event/Event.h"
#include "Event/ApplicationEvent.h"

#include "Layer.h"
#include "LayerStack.h"

namespace GameEngine
{
	class GAMEENGINE_API Application
	{

	public:

		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		bool onWindowCloseEvent(WindowCloseEvent& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

	private:

		std::unique_ptr<Window> mWindow;
		
		bool mRunning = true;

		LayerStack mLayerStack;

	};


	// to be defined in client
	Application* createApplication();


}