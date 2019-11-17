#include "gepch.h"
#include "WindowsWindow.h"


namespace GameEngine
{

	static bool sGLFWInitialized = false;

	Window* Window::create(const WindowProperties& properties)
	{
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		init(properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		this->shutdown();
	}

	void WindowsWindow::init(const WindowProperties& properties)
	{
		mWindowData.title = properties.title;
		mWindowData.width = properties.width;
		mWindowData.height = properties.height;

		CORE_LOG_INFO("Initializing GLFW and Creating window with title \"{0}\" and size ({1}, {2})", mWindowData.title, mWindowData.width, mWindowData.height);

		if (!sGLFWInitialized)
		{
			int success = glfwInit();
			GE_CORE_ASSERT(success, "Failed initializing GLFW");
			sGLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)mWindowData.width, (int)mWindowData.height, mWindowData.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mWindowData);
		setVSyncEnabled(true);

	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(mWindow);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void WindowsWindow::setVSyncEnabled(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		mWindowData.VSyncEnabled = true;
	}

	bool WindowsWindow::isVSyncEnabled() const
	{
		return mWindowData.VSyncEnabled;
	}

}