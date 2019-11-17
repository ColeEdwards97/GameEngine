#pragma once


#ifdef GE_PLATFORM_WINDOWS


extern GameEngine::Application* GameEngine::createApplication();

int main(int argc, char** argv)
{

	// TODO: remove later
	GameEngine::Log::init();
	CORE_LOG_WARN("Log initialized!");
	LOG_INFO("Game Engine is starting!");
	int a = 5;
	LOG_INFO("Var={0}", a);

	auto app = GameEngine::createApplication();
	app->run();
	delete app;
}

#endif // GE_PLATFORM_WINDOWS
