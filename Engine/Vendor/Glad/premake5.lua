project "Glad"
    kind "StaticLib"
    language "C"

    targetdir "%{prj.name}/bin/%{cfg.buildcfg}/%{cfg.platform}"
    objdir "%{prj.name}/obj/%{cfg.buildcfg}/%{cfg.platform}"

    files {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs {
        "include"
    }

    filter "system:linux"
        pic "On"
        links { 
            "dl",
            "pthread",
            "rt",
            "X11",
            "Xrandr",
            "Xinerama",
            "Xi",
            "Xcursor",
            "GL"
        }

    filter "configurations:Debug"
        symbols "On"
        defines { "_DEBUG" }

    filter "configurations:Release"
        optimize "On"
        defines { "NDEBUG" }
