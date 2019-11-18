#include "gepch.h"
#include "WindowsWindow.h"

#include "GameEngine/Event/ApplicationEvent.h"
#include "GameEngine/Event/MouseEvent.h"
#include "GameEngine/Event/KeyEvent.h"	

#include <glad/glad.h>

namespace GameEngine
{

	static bool sGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* message)
	{
		CORE_LOG_ERROR("GLFW Error code {0}: {1}", error, message);
	}


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
			GE_CORE_ASSERT(success, "Failed to initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			sGLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)mWindowData.width, (int)mWindowData.height, mWindowData.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_CORE_ASSERT(status, "Failed to initialize Glad");

		glfwSetWindowUserPointer(mWindow, &mWindowData);
		setVSyncEnabled(true);





		// set GLFW callbacks
		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;
			
			WindowResizeEvent event(width, height);
			data.callback(event);
		});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			WindowCloseEvent event;
			data.callback(event);
		});

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keyCode, int scanCode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(keyCode, 0);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(keyCode);
					data.callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(keyCode, 1);
					data.callback(event);
					break;
				}
			}

		});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button, 0);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					MouseButtonPressedEvent event(button, 1);
					data.callback(event);
					break;
				}
			}

		});

		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.callback(event);
		});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.callback(event);
		});



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