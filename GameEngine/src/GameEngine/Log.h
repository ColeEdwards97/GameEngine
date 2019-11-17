#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GameEngine
{

	class GAMEENGINE_API Log
	{

	public:

		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }	

	private:

		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	};

}

// CORE LOGGING MACROS
#define CORE_LOG_TRACE(...)	::GameEngine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CORE_LOG_INFO(...)	::GameEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_LOG_WARN(...)	::GameEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG_ERROR(...)	::GameEngine::Log::getCoreLogger()->error(__VA_ARGS__)

// CLIENT LOGGING MACROS
#define LOG_TRACE(...)		::GameEngine::Log::getClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)		::GameEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)		::GameEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)		::GameEngine::Log::getClientLogger()->error(__VA_ARGS__)


