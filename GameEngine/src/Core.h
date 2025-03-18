#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

	#ifdef ENGINE_BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif

#endif

#define BIT(x) 1 << x

#define ENGINE_ERROR(x) throw std::exception(x)

#define ASSERT(x, ...) if(!x) { ENGINE_CORE_ERROR("ERROR: {0}", __VA_ARGS__); __debugbreak(); }