#pragma once

#ifdef __linux__
    #ifdef ENGINE_DLL_EXPORT
        #define ENGINE_API __attribute__((visibility("default")))
    #else
        #define ENGINE_API __attribute__((visibility("default")))
    #endif
#endif

#define BIT(x) (x << 1)
