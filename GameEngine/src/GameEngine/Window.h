#pragma once

#include "gepch.h"

#include "GameEngine/Core.h"

#include "GameEngine/Event/Event.h"


namespace GameEngine
{

	struct WindowProperties
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& title = "Game Engine",
						unsigned int width = 1280,
						unsigned int height = 720) 
			: title(title), width(width), height(height) {}

	};


	class GAMEENGINE_API Window
	{

	public:

		using EventCallbackFcn = std::function<void(Event& e)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFcn& callback) = 0;
		virtual void setVSyncEnabled(bool enabled) = 0;
		virtual bool isVSyncEnabled() const = 0;

		static Window* create(const WindowProperties& properties = WindowProperties());

	};



}