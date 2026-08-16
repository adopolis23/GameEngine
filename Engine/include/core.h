#pragma once
#include <cstdlib>

#ifdef __linux__
    #ifdef ENGINE_DLL_EXPORT
        #define ENGINE_API __attribute__((visibility("default")))
    #else
        #define ENGINE_API __attribute__((visibility("default")))
    #endif
#endif

// TODO Add windows macro and dll export
//#ifdef _WIN64
//    #ifdef ENGINE_DLL_EXPORT
//        #define ENGINE_API __declspec(dllexport)
//    #else
//        #define ENGINE_API __declspec(dllimport)
//    #endif
//#endif

#define BIT(x) (x << 1)

#define ASSERT(cond, msg) \
    do { \
        if (!(cond)) { \
            ENGINE_CORE_ERROR(msg); \
            std::abort(); \
        } \
    } while (0)
