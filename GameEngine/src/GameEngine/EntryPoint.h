#pragma once


#ifdef GE_PLATFORM_WINDOWS


extern GameEngine::Application* GameEngine::createApplication();

int main(int argc, char** argv)
{
	auto app = GameEngine::createApplication();
	app->run();
	delete app;
}

#endif // GE_PLATFORM_WINDOWS
