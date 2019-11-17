#include "gepch.h"
#include "Log.h"

namespace GameEngine
{

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;


	void Log::init()
	{
		spdlog::set_pattern("[%T][%n]%^[%l]%$: %v");

		coreLogger = spdlog::stdout_color_mt("CORE");
		coreLogger->set_level(spdlog::level::trace);


		clientLogger = spdlog::stdout_color_mt("CLIENT");
		clientLogger->set_level(spdlog::level::trace);
	}


}