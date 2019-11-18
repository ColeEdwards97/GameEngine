#pragma once

#include "GameEngine/Window.h"
#include <GLFW/glfw3.h>


namespace GameEngine
{

	class WindowsWindow : public Window
	{

	public:
		
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return mWindowData.width; }
		inline unsigned int getHeight() const override { return mWindowData.height; }

		inline void setEventCallback(const EventCallbackFcn& callback) override { mWindowData.callback = callback; }
		void setVSyncEnabled(bool enabled) override;
		bool isVSyncEnabled() const override;

	private:

		virtual void init(const WindowProperties& properties);
		virtual void shutdown();

		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			bool VSyncEnabled;
			EventCallbackFcn callback;
		};

		GLFWwindow* mWindow;

		WindowData mWindowData;

	};

}