#pragma once

#include "spdlog.h"
#include "Core.h"
#include "sinks/stdout_color_sinks.h"

namespace Engine {


	class ENGINE_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;


	};

}

//Core Log Macros
#define ENGINE_CORE_TRACE(...)  Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)   Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)   Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)  Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_FATAL(...)  Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define ENGINE_TRACE(...)  Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...)   Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...)   Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...)  Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...)  Engine::Log::GetClientLogger()->fatal(__VA_ARGS__)

