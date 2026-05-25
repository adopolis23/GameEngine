workspace "GameEngine"
    configurations { "Debug", "Release" }
    platforms { "x64" }
    -- location "build"

    -- Common project settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        runtime "Release"

    filter "platforms:x64"
        architecture "x86_64"

    filter {} -- Reset filter


project "Engine"
    kind "SharedLib"  -- This creates a DLL
    language "C++"
    -- targetname "Engine"
    targetextension ".so"

    -- Output directories
    targetdir "%{prj.name}/bin/%{cfg.buildcfg}/%{cfg.platform}"
    objdir "%{prj.name}/obj/%{cfg.buildcfg}/%{cfg.platform}"

    -- Source files
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.hpp"
    }

    -- Include directories
    includedirs {
        "%{prj.name}/include",
        "%{prj.name}/src",

        -- spdlog include dirs
        "%{prj.name}/Vendor/spdlog/include"
    }

    -- Library directories 
    libdirs {
        --"lib/%{cfg.platform}",
        --"external/lib/%{cfg.platform}"
    }

    -- Libraries to link 
    links { 
        -- "user32",
        -- "kernel32",
        -- "external_library"
    }

    -- Define export macro for DLL
    defines {
        "ENGINE_DLL_EXPORT"
    }

    -- Platform-specific settings
    filter "platforms:x64"
        defines { "_WIN64" }

    filter "action:vs*"
        buildoptions { "/EHsc", "/MP" }  -- Enable C++ exceptions, multi-processor build

    filter "action:gmake"
        buildoptions { "-fPIC", "-std=c++11" }

    filter "configurations:Debug"
        targetsuffix ""
        defines { "_DEBUG" }

    filter "configurations:Release"
        targetsuffix ""
        defines { "_RELEASE" }

    filter {} -- Reset filter


project "Sandbox"
    kind "ConsoleApp"  -- or "WindowedApp" for GUI
    language "C++"

    targetname "Sandbox"
    targetdir "%{prj.name}/bin/%{cfg.buildcfg}/%{cfg.platform}"
    objdir "%{prj.name}/obj/%{cfg.buildcfg}/%{cfg.platform}"

    -- Source files
    files {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp"
    }

    -- Include directories (point to engine headers)
    includedirs {
        "%{prj.name}/include",
        "%{prj.name}/src",
        "Engine/include",  -- Path to engine headers
        "Engine/Vendor/spdlog/include" -- path to engine spdlog headers TODO: Figure out how to automatically include this
    }

    -- Library directories
    libdirs {
        "Engine/bin/%{cfg.buildcfg}/%{cfg.platform}"  -- Path to engine .so
    }

    -- Link with engine library
    links {
        "Engine"  -- Links to libEngine.so on Linux
    }

    -- Platform-specific settings
    filter "system:linux"
        buildoptions { "-std=c++17", "-Wall" }
        linkoptions { "-Wl,-rpath=$$ORIGIN" }  -- Look for .so in same directory as executable
        defines { "LINUX" }

    filter "system:windows"
        defines { "_WINDOWS", "_WIN32" }
        buildoptions { "/EHsc", "/MP" }
        links { 
            "Engine.lib",  -- Import library on Windows
            "user32",
            "kernel32"
        }

    filter "configurations:Debug"
        targetsuffix ""
        defines { "_DEBUG" }

    filter "configurations:Release"
        targetsuffix ""
        defines { "NDEBUG" }

    filter {}

    -- Post-build command to copy engine .so to executable directory
    filter "system:linux"
        postbuildcommands {
            '{COPY} "Engine/bin/%{cfg.buildcfg}/%{cfg.platform}/libEngine.so" "%{cfg.targetdir}"'
        }
