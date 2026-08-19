#pragma once

#include "Engine/Vendor/imgui/imgui.h"
#include "imgui.h"
#include "OpenGl/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"


ImGuiKey KeycodeToImGuiKey(int keycode)
{
    ImGuiKey imguiKey = ImGuiKey_None;

    switch(keycode)
    {
        case GLFW_KEY_TAB: imguiKey = ImGuiKey_Tab; break;
        case GLFW_KEY_LEFT: imguiKey = ImGuiKey_LeftArrow; break;
        case GLFW_KEY_RIGHT: imguiKey = ImGuiKey_RightArrow; break;
        case GLFW_KEY_UP: imguiKey = ImGuiKey_UpArrow; break;
        case GLFW_KEY_DOWN: imguiKey = ImGuiKey_DownArrow; break;
        case GLFW_KEY_PAGE_UP: imguiKey = ImGuiKey_PageUp; break;
        case GLFW_KEY_PAGE_DOWN: imguiKey = ImGuiKey_PageDown; break;
        case GLFW_KEY_HOME: imguiKey = ImGuiKey_Home; break;
        case GLFW_KEY_END: imguiKey = ImGuiKey_End; break;
        case GLFW_KEY_INSERT: imguiKey = ImGuiKey_Insert; break;
        case GLFW_KEY_DELETE: imguiKey = ImGuiKey_Delete; break;
        case GLFW_KEY_BACKSPACE: imguiKey = ImGuiKey_Backspace; break;
        case GLFW_KEY_SPACE: imguiKey = ImGuiKey_Space; break;
        case GLFW_KEY_ENTER: imguiKey = ImGuiKey_Enter; break;
        case GLFW_KEY_ESCAPE: imguiKey = ImGuiKey_Escape; break;
        case GLFW_KEY_LEFT_CONTROL: imguiKey = ImGuiKey_LeftCtrl; break;
        case GLFW_KEY_RIGHT_CONTROL: imguiKey = ImGuiKey_RightCtrl; break;
        case GLFW_KEY_LEFT_SHIFT: imguiKey = ImGuiKey_LeftShift; break;
        case GLFW_KEY_RIGHT_SHIFT: imguiKey = ImGuiKey_RightShift; break;
        case GLFW_KEY_LEFT_ALT: imguiKey = ImGuiKey_LeftAlt; break;
        case GLFW_KEY_RIGHT_ALT: imguiKey = ImGuiKey_RightAlt; break;
        case GLFW_KEY_LEFT_SUPER: break;
        case GLFW_KEY_RIGHT_SUPER: break;
    }

    return imguiKey;
}

